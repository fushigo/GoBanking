#include "CustomerData.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include <msclr/marshal_cppstd.h>

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	string dateFilter;
	string searchFilter;

    // Mengambil data dari API
	static string getData() {
		API api;
		string endpoint = "/nasabah";
		string response;

		try {
			response = api.GET(endpoint);
		}
        catch (System::String^ err) {
            System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
        }

		return response.data();
	}

    // Menampilkan data nasabah
    System::Void CustomerData::CustomerData_Load(System::Object^ sender, System::EventArgs^ e) {

        string dataNasabah = getData();

        if (dataNasabah.empty()) {
            System::Windows::Forms::MessageBox::Show("Gagal mengambil data!.", "Terjadi kesalahan");
            return;
        }
        else {
            try {
                // Mengubah string dataNasabah menjadi object json
                auto jsonData = json::parse(dataNasabah);
                // Mengambil data object dengan key "data"
                auto& data = jsonData["data"];

                // Menghapus data rows
                dataGridView->Rows->Clear();

                // Mengambil data
                for (const auto& item : data) {
                    string createAt = item["createdAt"].get<string>();
                    string namaLengkap = item["namaLengkap"].get<string>();
                    string nik = item["nik"].get<string>();

                    // Filter data berdasarkan tanggal dibuat
                    if (!dateFilter.empty() && createAt.substr(0, 10) != dateFilter) {
                        continue;
                    }

                    // Filter data berdasarkan query nama lengkap atau nomor identitas (nik)
                    if (!searchFilter.empty()) {
                        // Mengubah namaLengkap, nik, dan searchQuery menjadi lowercase
                        string nama_lower = namaLengkap, nik_lower = nik, search_lower = searchFilter;
                        transform(nama_lower.begin(), nama_lower.end(), nama_lower.begin(), tolower);
                        transform(nik_lower.begin(), nik_lower.end(), nik_lower.begin(), tolower);
                        transform(search_lower.begin(), search_lower.end(), search_lower.begin(), tolower);

                        // Melakukan filter data dengan case intensitive
                        if (nama_lower.find(search_lower) == string::npos && nik_lower.find(search_lower) == string::npos) {
                            continue;
                        }
                    }

                    // Konversi data string menggunakan marshal_as menjadi System::String / String^
                    String^ nmIdentitas = msclr::interop::marshal_as<String^>(item["nik"].get<string>());
                    String^ namaNasabah = msclr::interop::marshal_as<String^>(item["namaLengkap"].get<string>());
                    String^ jenisKelamin = msclr::interop::marshal_as<String^>(item["jenisKelamin"].get<string>());
                    String^ email = msclr::interop::marshal_as<String^>(item["email"].get<string>());
                    String^ nomorTelephone = msclr::interop::marshal_as<String^>(item["nomorTelepone"].get<string>());
                    String^ dirubah = msclr::interop::marshal_as<String^>(item["updateAt"].get<string>());
                    String^ dibuat = msclr::interop::marshal_as<String^>(item["createdAt"].get<string>());

                    // Menampilkan data
                    dataGridView->Rows->Add(nmIdentitas, namaNasabah, jenisKelamin, email, nomorTelephone, dibuat, dirubah);
                }
            }
            catch (json::exception& e) {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan saat parse json");
            }
        }
    }

	// Menangani kondisi ketika nilai dateTimePicker berubah
	System::Void CustomerData::dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		DateTime datetime = dateTimePicker->Value;
        String^ isoFormatted = datetime.ToUniversalTime().ToString("yyyy-MM-dd");
		dateFilter = msclr::interop::marshal_as<string>(isoFormatted);

		CustomerData_Load(nullptr, nullptr);
	}

    // Menangani ketika nilai textBox1 (Filter Pencarian) berubah
    System::Void CustomerData::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ textValue = textBox1->Text;
        searchFilter = msclr::interop::marshal_as<string>(textValue);
    }

    System::Void CustomerData::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        CustomerData_Load(nullptr, nullptr);
    }

    // Menangani kondisi ketika button reset ditekan
    System::Void CustomerData::button1_Click(System::Object^ sender, System::EventArgs^ e) {
        dateFilter = "";
        searchFilter = "";

        CustomerData_Load(nullptr, nullptr);
    }
}
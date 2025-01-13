#include "CustomerData.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include <msclr/marshal_cppstd.h>

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	string dateFilter;
	string searchFilter;

    string nomorNik;

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

    static string deleteData(const string& nik) {
        API api;
        string endpoint = "/nasabah/nik/" + nik;
        string response;

        try {
            response = api.REQDELETE(endpoint);
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

    System::Void CustomerData::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && dataGridView->Rows->Count > 0) {

            if (e->ColumnIndex == dataGridView->Columns["edit"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                );

                if (dataGridView->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    //buttonCell->Style->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    //buttonCell->Style->SelectionBackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    String^ noNik = dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
                    nomorNik = msclr::interop::marshal_as<string>(noNik);

                    ShowPopupEdit();
                }
            }

            else if (e->ColumnIndex == dataGridView->Columns["deletecol"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                );

                if (dataGridView->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    //buttonCell->Style->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    //buttonCell->Style->SelectionBackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    String^ noNik = dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
                    nomorNik = msclr::interop::marshal_as<string>(noNik);

                    ShowConfirmationPopup();
                }
            }
        }
    }

    System::Void CustomerData::ShowConfirmationPopup() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        currentPopup->SetMessage("Apakah Anda yakin ingin menghapus data?");
        currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &CustomerData::OnConfirmDelete));
        currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &CustomerData::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void CustomerData::ShowPopupEdit() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        currentPopup->SetMessage("Apakah Anda yakin ingin mengedit data?");
        currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &CustomerData::OnConfirmDelete));
        currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &CustomerData::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void CustomerData::OnConfirmEdit(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessEdit();
        }
    }

    System::Void CustomerData::ProcessEdit() {

    }

    System::Void CustomerData::OnConfirmDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessDelete();
        }
    }

    System::Void CustomerData::ProcessDelete() {
        if (nomorNik.empty()) {
            System::Windows::Forms::MessageBox::Show("Nomor Identitas diperlukan", "Terjadi kesalahan");
        }

        try {
            auto jsonData = json::parse(deleteData(nomorNik));
            int statusCode = jsonData["statusCode"].get<int>();

            if (statusCode == 200) {
                nomorNik = "";
                ShowResultPopup(true, "Berhasil menghapus data");
                CustomerData_Load(nullptr, nullptr);
            }
        }
        catch (json::exception err) {
            System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse json");
      }
    }

    System::Void CustomerData::ShowResultPopup(bool isSuccess, String^ message) {
        currentPopup = gcnew PopupForm();
        if (isSuccess) {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &CustomerData::OnResultConfirmed));
        }
        else {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &CustomerData::OnRetryDelete));
        }
        currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &CustomerData::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void CustomerData::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void CustomerData::OnRetryDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ShowConfirmationPopup();
        }
    }

    System::Void CustomerData::OnClose(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void CustomerData::CloseCurrentPopup() {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            currentPopup = nullptr;
        }
    }
}
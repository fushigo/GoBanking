#include "CheckSavings.h"
#include "nlohmann/json.hpp"
#include <msclr/marshal_cppstd.h>
#include "Api.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	string textValue;

	static string getData(const string& nik) {
		API api;
		string endpoint = "/nasabah/nik/"+nik;
		string response;

		try {
			response = api.GET(endpoint);
		}
		catch (System::String^ err) {
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
	}

	static string getDataActivity(const string& norek) {
		API api;
		string endpoint = "/rekening/norek/"+norek;
		string response;

		try {
			response = api.GET(endpoint);
		}
		catch (System::String^ err) {
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
	}

	// Menangani ketika tombol btnCheckSavings di klik
	System::Void CheckSavings::btnCheckSavings_Click(System::Object^ sender, System::EventArgs^ e)
	{
		string nikParams = textValue;
		string allRekeningData = getData(nikParams);

		if (allRekeningData.empty()) {
			System::Windows::Forms::MessageBox::Show("Gagal mengambil data.!", "Terjadi kesalahan");
			return;
		}
		else {
			try {
				// Membuat variable auto untuk menyimpan data JSON
				auto jsonData = json::parse(allRekeningData);
				auto& data = jsonData["data"]["rekening"];

				// Menghapus data di table
				dataGridViewAccount->Rows->Clear();

				for (const auto& item : data) {
					int inomorRekening = item["nomorRekening"].get<int>();

					// Konversi data string menggunakan marshal_as menjadi System::String / String^
					String^ nomorRekening = msclr::interop::marshal_as<String^>(std::to_string(inomorRekening));
					String^ jenisTabungan = msclr::interop::marshal_as<String^>(item["jenisTabungan"].get<string>());
					String^ jumlahSaldo = msclr::interop::marshal_as<String^>(item["totalDana"].get<string>());
					String^ jumlahBunga = msclr::interop::marshal_as<String^>(item["bonusBunga"].get<string>());
					String^ dibuat = msclr::interop::marshal_as<String^>(item["createdAt"].get<string>());
					String^ dirubah = msclr::interop::marshal_as<String^>(item["updatedAt"].get<string>());

					// Konversi String^ menjadi double
					double jm_saldo = Convert::ToDouble(jumlahSaldo);
					double jm_bunga = Convert::ToDouble(jumlahBunga);
					double saldo = Convert::ToDouble(jumlahSaldo);
					double bunga = Convert::ToDouble(jumlahBunga);

					double totalSaldo = saldo + bunga;

					// Melakukan format mata uang Rupiah
					System::Globalization::CultureInfo^ culture = gcnew System::Globalization::CultureInfo("id-ID");
					String^ formattedSaldo = String::Format(culture, "{0:c2}", jm_saldo);
					String^ formattedBunga = String::Format(culture, "{0:c2}", jm_bunga);
					String^ formattedTSaldo = String::Format(culture, "{0:c2}", totalSaldo);

					// Menampilkan data ke table
					dataGridViewAccount->Rows->Add(nomorRekening, jenisTabungan, formattedSaldo, formattedBunga, formattedTSaldo, dibuat, dirubah);
				}

			}
			catch (json::exception e) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan saat parse json");
			}
		}
	}

	System::Void CheckSavings::dataGridViewAccount_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		try {
			if (e->ColumnIndex == dataGridViewAccount->Columns["details"]->Index) {
				// Check if the row has data before processing the click
				if (dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
					!String::IsNullOrEmpty(dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value->ToString())) {

					String^ norek = dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value->ToString();
					string nomorRekening =  msclr::interop::marshal_as<string>(norek);

					dataGridViewDetail->Rows->Clear();

					try {
						// Fetch data activity rekening
						string dataActivity = getDataActivity(msclr::interop::marshal_as<string>(norek));
						auto jsonData = json::parse(dataActivity);
						auto& data = jsonData["data"]["rekeningActivity"];

						for (const auto& item : data) {
							String^ jenisAktivitas = msclr::interop::marshal_as<String^>(item["jenisActivity"].get<string>());
							String^ jumlahDana = msclr::interop::marshal_as<String^>(item["jumlahDana"].get<string>());
							String^ dibuat = msclr::interop::marshal_as<String^>(item["createdAt"].get<string>());

							double jm_dana = Convert::ToDouble(jumlahDana);

							System::Globalization::CultureInfo^ culture = gcnew System::Globalization::CultureInfo("id-ID");
							String^ formattedJmDana = String::Format(culture, "{0:c2}", jm_dana);

							dataGridViewDetail->Rows->Add(jenisAktivitas, formattedJmDana, dibuat);
						}
					}
					catch (json::exception e) {
						System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan saat parse json");
					}

					detailPanel->Visible = true;
					opacityValue = 0.0;
					fadeInTimer->Start();
				}
			}
		}
		catch (String^ err){

		}
	}

	// Menangani ketika nilai Text Input berubah
	System::Void CheckSavings::customerAccInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		textValue = msclr::interop::marshal_as<string>(customerAccInput->Text);
	}
}
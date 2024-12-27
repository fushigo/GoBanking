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
				auto jsonData = json::parse(allRekeningData);
				auto& data = jsonData["data"]["rekening"];

				for (const auto& item : data) {
					int inomorRekening = item["nomorRekening"].get<int>();

					// Konversi data string menggunakan marshal_as menjadi System::String / String^
					String^ nomorRekening = msclr::interop::marshal_as<String^>(std::to_string(inomorRekening));
					String^ jenisTabungan = msclr::interop::marshal_as<String^>(item["jenisTabungan"].get<string>());
					String^ jumlahSaldo = msclr::interop::marshal_as<String^>(item["totalDana"].get<string>());
					String^ jumlahBunga = msclr::interop::marshal_as<String^>(item["bonusBunga"].get<string>());
					String^ dibuat = msclr::interop::marshal_as<String^>(item["createdAt"].get<string>());
					String^ dirubah = msclr::interop::marshal_as<String^>(item["updatedAt"].get<string>());

					double saldo = Convert::ToDouble(jumlahSaldo);
					double bunga = Convert::ToDouble(jumlahBunga);

					double totalSaldo = saldo + bunga;

					dataGridViewAccount->Rows->Add(nomorRekening, jenisTabungan, jumlahSaldo, jumlahBunga, totalSaldo.ToString("F2"), dibuat, dirubah);
				}

			}
			catch (json::exception e) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan saat parse json");
			}
		}
	}

	System::Void CheckSavings::customerAccInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		textValue = msclr::interop::marshal_as<string>(customerAccInput->Text);
	}

}
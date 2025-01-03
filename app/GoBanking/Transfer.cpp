#include "Transfer.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include "msclr/marshal_cppstd.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	struct Selection {
		int pengirim;
		int penerima;
	}nasabah;

	static string getNasabah() {
		API api;
		string endpoint = "/nasabah";
		string response;

		try {
			response = api.GET(endpoint);
		}
		catch (String^ err) {
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
	}

	static string getAllRekeningNasabah(const string& nik) {
		API api;
		string endpoint = "/nasabah/nik/" + nik;
		string response;

		try {
			response = api.GET(endpoint);
		}
		catch (System::String^ err) {
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
	}

	static string getRekeningData(const string& norek) {
		API api;
		string endpoint = "/rekening/norek/" + norek;
		string response;

		try {
			response = api.GET(endpoint);
		}
		catch (System::String^ err) {
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
	}

	static string getUniqueItem(const string item) {
		size_t pos = item.find('|');
		string result;

		if (pos != string::npos) {
			result = item.substr(0, pos - 1);
		}
		else {
			result = item;
		}

		return result;
	}

	System::Void Transfer::dropDownMenuSend_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (dropDownMenuSend->SelectedIndex > 0) {
			string sendIdentityNumber = getUniqueItem(msclr::interop::marshal_as<string>(dropDownMenuSend->SelectedItem->ToString()));
			string receiveIdentityNumber;

			if (dropDownMenuReceive->SelectedIndex > 0) {
				receiveIdentityNumber = getUniqueItem(msclr::interop::marshal_as<string>(dropDownMenuReceive->SelectedItem->ToString()));
			}

			if (sendIdentityNumber == receiveIdentityNumber) {
				System::Windows::Forms::MessageBox::Show("Tidak bisa transfer pada nasabah yang sama", "Terjadi kesalahan");
				dropDownMenuSend->SelectedIndex = 0;
				return;
			}
			
			try {
				dropDownDana->Items->Clear();
				this->dropDownDana->Items->Insert(0, "-- Pilih Sumber Dana --");
				this->dropDownDana->SelectedIndex = 0;

				string rekeningData = getAllRekeningNasabah(sendIdentityNumber);
				auto jsonData = json::parse(rekeningData);

				auto& data = jsonData["data"]["rekening"];

				for (const auto& item : data) {
					dropDownDana->Items->Add(msclr::interop::marshal_as<String^>(item["nomorRekening"].get<string>() + " | " + item["jenisTabungan"].get<string>()));
					/*System::Windows::Forms::MessageBox::Show(msclr::interop::marshal_as<String^>(item["nomorRekening"].get<string>()));*/
				}

			}
			catch (json::exception err) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()));
			}

			/*System::Windows::Forms::MessageBox::Show(gcnew System::String(identityNumber.c_str()));*/
		}
	}

	System::Void Transfer::dropDownMenuReceive_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (dropDownMenuReceive->SelectedIndex > 0) {
			string recieveIdentityNumber = getUniqueItem(msclr::interop::marshal_as<string>(dropDownMenuReceive->SelectedItem->ToString()));
			string sendIdentityNumber;

			if (dropDownMenuSend->SelectedIndex > 0) {
				sendIdentityNumber = getUniqueItem(msclr::interop::marshal_as<string>(dropDownMenuSend->SelectedItem->ToString()));
			}

			if (recieveIdentityNumber == sendIdentityNumber) {
				System::Windows::Forms::MessageBox::Show("Tidak bisa transfer pada nasabah yang sama", "Terjadi kesalahan");
				dropDownMenuReceive->SelectedIndex = 0;
				return;
			}

		}
	}

	System::Void Transfer::dropDownDana_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (dropDownDana->SelectedIndex > 0) {
			string rekeningNumber = getUniqueItem(msclr::interop::marshal_as<string>(dropDownDana->SelectedItem->ToString()));
			string rekeningData = getRekeningData(rekeningNumber);

			try {
				auto jsonData = json::parse(rekeningData);

				string dataDana = jsonData["data"]["totalDana"].get<string>();
				string dataBunga = jsonData["data"]["bonusBunga"].get<string>();

				double dana = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataDana));
				double bunga = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataBunga));

				double totalSaldo = dana + bunga;

				System::Globalization::CultureInfo^ culture = gcnew System::Globalization::CultureInfo("id-ID");
				String^ formattedSaldo = String::Format(culture, "{0:c2}", totalSaldo);

				label4->Text = "Saldo : " + formattedSaldo;
			}
			catch (json::exception err) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
			}
		}
		else {
			label4->Text = "Saldo : ";
		}
	}

	void Transfer::loadDropdownData() {
		string dataNasabah = getNasabah();

		dropDownMenuSend->Items->Clear();
		dropDownMenuReceive->Items->Clear();
		dropDownDana->Items->Clear();

		dropDownMenuSend->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
		dropDownMenuSend->AutoCompleteSource = AutoCompleteSource::ListItems;

		dropDownMenuReceive->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
		dropDownMenuReceive->AutoCompleteSource = AutoCompleteSource::ListItems;

		try {
			auto jsonData = json::parse(dataNasabah);
			auto& data = jsonData["data"];

			for (const auto& item : data) {
				dropDownMenuSend->Items->Add(msclr::interop::marshal_as<String^>(item["nik"].get<string>() + " | " + item["namaLengkap"].get<string>()));
				dropDownMenuReceive->Items->Add(msclr::interop::marshal_as<String^>(item["nik"].get<string>() + " | " + item["namaLengkap"].get<string>()));
			}
		}
		catch (json::exception& err) {
			System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
		}
	}
	System::Void Transfer::nominalInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		
	}
}
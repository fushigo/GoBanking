#include "Transfer.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include "msclr/marshal_cppstd.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	double tSaldo, saldoTf;
	string rekSender, rekReceiver, pinRek;

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

	static string postData(string& payload) {
		API api;
		string endpoint = "/rekening/transfer";
		string response;

		try
		{
			response = api.POST(endpoint, payload);
		}
		catch (String^ err)
		{
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
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

			try {
				dropDownRekReceive->Items->Clear();
				dropDownRekReceive->Items->Insert(0, "-- Pilih Rekening --");
				dropDownRekReceive->SelectedIndex = 0;

				string rekeningData = getAllRekeningNasabah(recieveIdentityNumber);
				auto jsonData = json::parse(rekeningData);

				auto& data = jsonData["data"]["rekening"];

				for (const auto& item : data) {
					dropDownRekReceive->Items->Add(msclr::interop::marshal_as<String^>(item["nomorRekening"].get<string>() + " | " + item["jenisTabungan"].get<string>()));
					//System::Windows::Forms::MessageBox::Show(msclr::interop::marshal_as<String^>(item["nomorRekening"].get<string>()));
				}

			}
			catch (json::exception err) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()));
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
				string dataNorek = jsonData["data"]["nomorRekening"].get<string>();
				int dataPin = jsonData["data"]["pin"].get<int>();

				double dana = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataDana));
				double bunga = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataBunga));

				double totalSaldo = dana + bunga;
				tSaldo = totalSaldo;
				pinRek = msclr::interop::marshal_as<string>(dataPin.ToString());
				rekSender = dataNorek;

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
		dropDownRekReceive->Items->Clear();

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
		double inpSaldo = Convert::ToDouble(nominalInput->Text);
		if (tSaldo && inpSaldo >= tSaldo) {
			System::Windows::Forms::MessageBox::Show("Saldo rekening nasabah tidak cukup", "Terjadi kesalahan");
			nominalInput->Text = (tSaldo - 10000).ToString();
			return;
		}

		saldoTf = inpSaldo;
	}
	System::Void Transfer::dropDownRekReceive_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (dropDownRekReceive->SelectedIndex > 0) {
			string rekeningNumber = getUniqueItem(msclr::interop::marshal_as<string>(dropDownRekReceive->SelectedItem->ToString()));
			string rekeningData = getRekeningData(rekeningNumber);

			try {
				auto jsonData = json::parse(rekeningData);

				string dataDana = jsonData["data"]["totalDana"].get<string>();
				string dataBunga = jsonData["data"]["bonusBunga"].get<string>();
				string dataNorek = jsonData["data"]["nomorRekening"].get<string>();

				double dana = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataDana));
				double bunga = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataBunga));

				double totalSaldo = dana + bunga;

				rekReceiver = dataNorek;

				System::Globalization::CultureInfo^ culture = gcnew System::Globalization::CultureInfo("id-ID");
				String^ formattedSaldo = String::Format(culture, "{0:c2}", totalSaldo);

				label6->Text = "Saldo : " + formattedSaldo;
			}
			catch (json::exception err) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
			}
		}
		else {
			label6->Text = "Saldo : ";
		}
	}

	System::Void Transfer::btnTransfer_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ShowConfirmationPopup();
	}

	System::Void Transfer::ShowConfirmationPopup() {
		CloseCurrentPopup();
		currentPopup = gcnew PopupForm();
		currentPopup->SetMessage("Apakah Anda yakin ingin melanjutkan transfer?");
		currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &Transfer::OnConfirmTransfer));
		currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &Transfer::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void Transfer::OnConfirmTransfer(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			ProcessTransfer();
		}
	}

	System::Void Transfer::ProcessTransfer() {
		json payjson;

		payjson["rekSend"] = rekSender;
		payjson["rekReceive"] = rekReceiver;
		payjson["nominalTf"] = saldoTf;
		payjson["pin"] = pinRek;

		try {
			string response = postData(payjson.dump());

			auto jsonData = json::parse(response);
			auto& status = jsonData["statusCode"];

			if (status.get<int>() == 500) {
				ShowResultPopup(false);
			}else if (status.get<int>() == 400) {
				ShowResultPopup(false);
			}
			else {
				ShowResultPopup(true);
			}
		}
		catch (json::exception e) {
			System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan");
			return;
		}
	}

	System::Void Transfer::ShowResultPopup(bool isSuccess) {
		currentPopup = gcnew PopupForm();
		if (isSuccess) {
			currentPopup->SetMessage("Transfer berhasil!");
			currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &Transfer::OnResultConfirmed));
		}
		else {
			currentPopup->SetMessage("Transfer gagal!");
			currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &Transfer::OnRetryTransfer));
		}
		currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &Transfer::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void Transfer::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void Transfer::OnRetryTransfer(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			ShowConfirmationPopup();
		}
	}

	System::Void Transfer::OnClose(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void Transfer::CloseCurrentPopup() {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			currentPopup = nullptr;
		}
	}
}
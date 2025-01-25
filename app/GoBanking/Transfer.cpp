#include "Transfer.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include "msclr/marshal_cppstd.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	double tSaldo, saldoTf;
	struct rekeningTranfer{
		string rekSender, rekReceiver, pinRek;
	};

	rekeningTranfer rekening;

	// Fungsi untuk menangani permintaan ke API
	static string apiRequester(const string& endpoint, const string& params, const string& payload, const string& method) {
		API api;
		string response;

		try
		{
			if (method == "GET") {
				response = api.GET(!params.empty() ? endpoint + params : endpoint);
			}
			else if (method == "POST") {
				response = api.POST(endpoint, payload);
			}
			else if (method == "PATCH") {
				response = api.REQPATCH(endpoint + params, payload);
			}
			else if (method == "DELETE") {
				response = api.REQDELETE(endpoint + params);
			}
			else {
				System::Windows::Forms::MessageBox::Show("Method tidak dizinkan", "Terjadi kesalahan pada Api Requester");
				return "";
			}
		}
		catch (String^ e) {
			System::Windows::Forms::MessageBox::Show(e, "Terjadi kesalahan");
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

				string rekeningData = apiRequester("/nasabah/nik/", sendIdentityNumber, "", "GET");
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

				string rekeningData = apiRequester("/nasabah/nik/", recieveIdentityNumber, "", "GET");
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
			string rekeningData = apiRequester("/rekening/norek/", rekeningNumber, "", "GET");

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
				rekening.pinRek = msclr::interop::marshal_as<string>(dataPin.ToString());
				rekening.rekSender = dataNorek;

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
		string dataNasabah = apiRequester("/nasabah", "", "", "GET");

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
		if (String::IsNullOrEmpty(nominalInput->Text)) {
			return;
		}

		double inpSaldo;
		if (!Double::TryParse(nominalInput->Text, inpSaldo)) {
			currentPopup = gcnew PopupForm();
			currentPopup->SetMessage("Masukkan nominal yang valid");
			currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &Transfer::OnRetryTransfer));
			currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &Transfer::OnClose));
			currentPopup->ShowPopup();
			nominalInput->Text = "";
			return;
		}

		if (tSaldo && inpSaldo >= tSaldo) {
			currentPopup = gcnew PopupForm();
			currentPopup->SetMessage("Saldo rekening nasabah tidak cukup");
			currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &Transfer::OnRetryTransfer));
			currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &Transfer::OnClose));
			currentPopup->ShowPopup();
			nominalInput->Text = (tSaldo - 10000).ToString();
			return;
		}

		saldoTf = inpSaldo;
	}
	System::Void Transfer::dropDownRekReceive_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (dropDownRekReceive->SelectedIndex > 0) {
			string rekeningNumber = getUniqueItem(msclr::interop::marshal_as<string>(dropDownRekReceive->SelectedItem->ToString()));
			string rekeningData = apiRequester("/rekening/norek/", rekeningNumber, "", "GET");

			try {
				auto jsonData = json::parse(rekeningData);

				string dataDana = jsonData["data"]["totalDana"].get<string>();
				string dataBunga = jsonData["data"]["bonusBunga"].get<string>();
				string dataNorek = jsonData["data"]["nomorRekening"].get<string>();

				double dana = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataDana));
				double bunga = Convert::ToDouble(msclr::interop::marshal_as<String^>(dataBunga));

				double totalSaldo = dana + bunga;

				rekening.rekReceiver = dataNorek;

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

		payjson["rekSend"] = rekening.rekSender;
		payjson["rekReceive"] = rekening.rekReceiver;
		payjson["nominalTf"] = saldoTf;
		payjson["pin"] = rekening.pinRek;

		try {
			string response = apiRequester("/rekening/transfer", "", payjson.dump(), "POST");

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
			nominalInput->Focus();
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
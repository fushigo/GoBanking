#include "AddSavingsFunds.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include "msclr/marshal_cppstd.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	struct {
		string nomorRekening;
		string nominal;
		string pinRekening;
	}rekening;

	static string postAddSavingsFunds(const string& payload) {
		API api;
		string endpoint = "/rekening/saving-funds";
		string response;

		try {
			response = api.POST(endpoint, payload);
		}
		catch (String^ err) {
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
	}

	System::Void AddSavingsFunds::btnAddSavings_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ShowConfirmationPopup();
	}

	System::Void AddSavingsFunds::customerAccInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.nomorRekening = msclr::interop::marshal_as<string>(customerAccInput->Text);
	}

	System::Void AddSavingsFunds::addSavingsInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.nominal = msclr::interop::marshal_as<string>(addSavingsInput->Text);
	}

	System::Void AddSavingsFunds::pinInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.pinRekening = msclr::interop::marshal_as<string>(pinInput->Text);
	}

	System::Void AddSavingsFunds::ShowConfirmationPopup() {
		CloseCurrentPopup();
		currentPopup = gcnew PopupForm();
		currentPopup->Size = System::Drawing::Size(400, 250);
		currentPopup->SetMessage("Apakah Anda yakin ingin menambah tabungan?");
		currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &AddSavingsFunds::OnConfirmAddSavings));
		currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &AddSavingsFunds::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void AddSavingsFunds::OnConfirmAddSavings(System::Object^ sender, System::EventArgs^ e)
	{
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			ProcessAddSavings();
		}
		else {
			ProcessAddSavings();
		}
	}

	System::Void AddSavingsFunds::ProcessAddSavings()
	{
		if (rekening.nomorRekening.empty() || rekening.nominal.empty() || rekening.pinRekening.empty()) {
			ShowResultPopup(false, "Tidak boleh ada formulir yang kosong");
			return;
		}

		try {
			json payjson;
			payjson["nomorRekening"] = rekening.nomorRekening;
			payjson["nominal"] = rekening.nominal;
			payjson["pinRekening"] = rekening.pinRekening;

			auto jsonData = json::parse(postAddSavingsFunds(payjson.dump()));
			auto& statusCode = jsonData["statusCode"], & message = jsonData["message"];

			if (statusCode.get<int>() == 200) {
				ShowResultPopup(true, "Berhasil melakukan penambahan saldo tabungan");
			}
			else {
				ShowResultPopup(false, msclr::interop::marshal_as<String^>(message.get<string>()));
			}
		}
		catch (json::exception err) {
			System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
		}
	}

	System::Void AddSavingsFunds::ShowResultPopup(bool isSuccess, String^ message) {
		currentPopup = gcnew PopupForm();
		if (isSuccess) {
			currentPopup->SetMessage(message);
			currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &AddSavingsFunds::OnResultConfirmed));
		}
		else {
			currentPopup->SetMessage(message);
			currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &AddSavingsFunds::OnRetryAddSavings));
		}
		currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &AddSavingsFunds::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void AddSavingsFunds::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void AddSavingsFunds::OnRetryAddSavings(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void AddSavingsFunds::OnClose(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void AddSavingsFunds::CloseCurrentPopup() {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			currentPopup = nullptr;
		}
	}
}
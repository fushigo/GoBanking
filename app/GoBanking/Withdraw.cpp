#include "Withdraw.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include "msclr/marshal_cppstd.h"
#include "PopupForm.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	struct withdraw {
		string nomorRekening;
		string nominal;
		string pin;
	}rekening;

	static string postWithdraw(const string& payload) {
		API api;
		string endpoint = "/rekening/tarik-tunai";
		string response;

		try {
			response = api.POST(endpoint, payload);
		}
		catch (String^ e) {
			System::Windows::Forms::MessageBox::Show(e, "Terjadi kesalahan");
		}

		return response.data();
	}

	System::Void Withdraw::customerAccInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.nomorRekening = msclr::interop::marshal_as<string>(customerAccInput->Text);
	}

	System::Void Withdraw::nominalWithdrawInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.nominal = msclr::interop::marshal_as<string>(nominalWithdrawInput->Text);
	}

	System::Void Withdraw::pinInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.pin = msclr::interop::marshal_as<string>(pinInput->Text);
	}

	System::Void Withdraw::btnWithdraw_Click(System::Object^ sender, System::EventArgs^ e)
	{
			ShowConfirmationPopup();
	}

	System::Void Withdraw::ShowConfirmationPopup() {
		CloseCurrentPopup();
		currentPopup = gcnew PopupForm();
		currentPopup->Size = System::Drawing::Size(400, 250);
		currentPopup->SetMessage("Apakah Anda yakin ingin menarik tunai?");
		currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &Withdraw::OnConfirmWithdraw));
		currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &Withdraw::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void Withdraw::OnConfirmWithdraw(System::Object^ sender, System::EventArgs^ e)
	{
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			ProcessWithdraw();
		}
		else {
			ProcessWithdraw();
		}
	}

	System::Void Withdraw::ProcessWithdraw()
	{
		if (rekening.nomorRekening.empty() || rekening.nominal.empty() || rekening.pin.empty()) {
			ShowResultPopup(false, "Tidak boleh ada formulir yang kosong");
			return;
		}

		try {
			json payjson;
			payjson["nomorRekening"] = rekening.nomorRekening;
			payjson["nominal"] = rekening.nominal;
			payjson["pinRekening"] = rekening.pin;

			auto jsonData = json::parse(postWithdraw(payjson.dump()));
			auto& statusCode = jsonData["statusCode"], & message = jsonData["message"];

			if (statusCode.get<int>() == 200) {
				ShowResultPopup(true, "Berhasil melakukan penarikan tunai");
			}
			else {
				ShowResultPopup(false, msclr::interop::marshal_as<String^>(message.get<string>()));
			}
		}
		catch (json::exception err) {
			System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat penarikan tunai!");
		}
	}

	System::Void Withdraw::ShowResultPopup(bool isSuccess, String^ message) {
		currentPopup = gcnew PopupForm();
		if (isSuccess) {
			currentPopup->SetMessage(message);
			currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &Withdraw::OnResultConfirmed));
		}
		else {
			currentPopup->SetMessage(message);
			currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &Withdraw::OnRetryWithdraw));
		}
		currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &Withdraw::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void Withdraw::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void Withdraw::OnRetryWithdraw(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void Withdraw::OnClose(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void Withdraw::CloseCurrentPopup() {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			currentPopup = nullptr;
		}
	}
}
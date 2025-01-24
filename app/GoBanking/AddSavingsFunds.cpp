#include "AddSavingsFunds.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include "msclr/marshal_cppstd.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	// Membuat struct rekening
	struct {
		string nomorRekening;
		string nominal;
		string pinRekening;
	}rekening;

	// Fungsi untuk request post data ke API
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

	// Fungsi untuk menangani ketika tombol di tekan
	System::Void AddSavingsFunds::btnAddSavings_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ShowConfirmationPopup();
	}

	// Fungsi untuk menangani ketika nilai text field berubah
	System::Void AddSavingsFunds::customerAccInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.nomorRekening = msclr::interop::marshal_as<string>(customerAccInput->Text);
	}

	// Fungsi untuk menangani ketika nilai text field berubah
	System::Void AddSavingsFunds::addSavingsInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.nominal = msclr::interop::marshal_as<string>(addSavingsInput->Text);
	}

	// Fungsi untuk menangani ketika nilai text field berubah
	System::Void AddSavingsFunds::pinInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		rekening.pinRekening = msclr::interop::marshal_as<string>(pinInput->Text);
	}

	// Fungsi untuk menampilkan 
	System::Void AddSavingsFunds::ShowConfirmationPopup() {
		CloseCurrentPopup();
		currentPopup = gcnew PopupForm();
		currentPopup->Size = System::Drawing::Size(400, 250);
		currentPopup->SetMessage("Apakah Anda yakin ingin menambah tabungan?");
		currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &AddSavingsFunds::OnConfirmAddSavings));
		currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &AddSavingsFunds::OnClose));
		currentPopup->ShowPopup();
	}

	// Fungsi untuk menagani ketika tombol konfirmasi ditekan
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

	// Fungsi untuk menangani proses menambah tabungan
	System::Void AddSavingsFunds::ProcessAddSavings()
	{
		// Kondisi jika nomorRekening, nominal, pinRekening tidak bernilai
		if (rekening.nomorRekening.empty() || rekening.nominal.empty() || rekening.pinRekening.empty()) {
			ShowResultPopup(false, "Tidak boleh ada formulir yang kosong");
			return;
		}

		try {
			// Membuat variable payjson dengan tipe data json;
			json payjson;
			payjson["nomorRekening"] = rekening.nomorRekening;
			payjson["nominal"] = rekening.nominal;
			payjson["pinRekening"] = rekening.pinRekening;

			// Membuat variable dengan tipe data auto agar dapat menyesuaikan dengan data json;
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

	// Fungsi untuk menampilkan pop-up hasil
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

	// Fungsi untuk menangani ketika tombol konfirmasi ditekan
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
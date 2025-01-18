#include "AddSavingsFunds.h"

namespace GoBanking {

	System::Void AddSavingsFunds::btnAddSavings_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ShowConfirmationPopup();
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
		//process
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
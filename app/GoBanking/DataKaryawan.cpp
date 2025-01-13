#include "DataKaryawan.h"

namespace GoBanking {
    System::Void DataKaryawan::dataGridViewKaryawan_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && dataGridViewKaryawan->Rows->Count > 0) {

            if (e->ColumnIndex == dataGridViewKaryawan->Columns["edit"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridViewKaryawan->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                    );

                if (dataGridViewKaryawan->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridViewKaryawan->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    ShowPopupEdit();
                }
            }

            else if (e->ColumnIndex == dataGridViewKaryawan->Columns["deletecol"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridViewKaryawan->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                    );

                if (dataGridViewKaryawan->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridViewKaryawan->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    ShowConfirmationPopup();
                }
            }
        }
    }

    System::Void DataKaryawan::btnCreate_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ShowPopupCreate();
    }


    System::Void DataKaryawan::ShowPopupCreate() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        cli::array<PopupForm::FormField^>^ fields = gcnew cli::array<PopupForm::FormField^>(5);

        fields[0] = gcnew PopupForm::FormField();
        fields[0]->label = "No. Karyawan";
        fields[0]->type = "text";

        fields[1] = gcnew PopupForm::FormField();
        fields[1]->label = "Nama Karyawan";
        fields[1]->type = "text";

        fields[2] = gcnew PopupForm::FormField();
        fields[2]->label = "Username";
        fields[2]->type = "text";

        fields[3] = gcnew PopupForm::FormField();
        fields[3]->label = "Role";
        fields[3]->type = "text";

        fields[4] = gcnew PopupForm::FormField();
        fields[4]->label = "Password";
        fields[4]->type = "text";

        currentPopup->SetMessageVisible(false);

        currentPopup->SetActionButton1("Tambah", gcnew EventHandler(this, &DataKaryawan::OnConfirmCreate));
        currentPopup->SetActionButton2("Close", gcnew EventHandler(this, &DataKaryawan::OnClose));

        currentPopup->CreateFormFields(fields);
        currentPopup->Size = System::Drawing::Size(400, 400);
        currentPopup->ShowPopup();
    }

    System::Void DataKaryawan::ShowConfirmationPopup() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        currentPopup->Size = System::Drawing::Size(400, 250);
        currentPopup->SetMessage("Apakah Anda yakin ingin menghapus data?");
        currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &DataKaryawan::OnConfirmDelete));
        currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &DataKaryawan::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void DataKaryawan::ShowPopupEdit() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        cli::array<PopupForm::FormField^>^ fields = gcnew cli::array<PopupForm::FormField^>(4);

        fields[0] = gcnew PopupForm::FormField();
        fields[0]->label = "No. Karyawan";
        fields[0]->type = "text";

        fields[1] = gcnew PopupForm::FormField();
        fields[1]->label = "Nama Karyawan";
        fields[1]->type = "text";

        fields[2] = gcnew PopupForm::FormField();
        fields[2]->label = "Username";
        fields[2]->type = "text";

        fields[3] = gcnew PopupForm::FormField();
        fields[3]->label = "Role";
        fields[3]->type = "text";

        currentPopup->SetMessageVisible(false);

        currentPopup->SetActionButton1("Edit", gcnew EventHandler(this, &DataKaryawan::OnConfirmEdit));
        currentPopup->SetActionButton2("Close", gcnew EventHandler(this, &DataKaryawan::OnClose));

        currentPopup->CreateFormFields(fields);
        currentPopup->Size = System::Drawing::Size(400, 400);
        currentPopup->ShowPopup();
    }


    System::Void DataKaryawan::OnConfirmCreate(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessEdit();
        }
    }

    System::Void DataKaryawan::ProcessCreate() {

    }

    System::Void DataKaryawan::OnConfirmEdit(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessEdit();
        }
    }

    System::Void DataKaryawan::ProcessEdit() {

    }

    System::Void DataKaryawan::OnConfirmDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessDelete();
        }
    }

    System::Void DataKaryawan::ProcessDelete() {

    }

    System::Void DataKaryawan::ShowResultPopup(bool isSuccess, String^ message) {
        currentPopup = gcnew PopupForm();
        if (isSuccess) {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &DataKaryawan::OnResultConfirmed));
        }
        else {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &DataKaryawan::OnRetryDelete));
        }
        currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &DataKaryawan::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void DataKaryawan::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void DataKaryawan::OnRetryDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ShowConfirmationPopup();
        }
    }

    System::Void DataKaryawan::OnClose(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void DataKaryawan::CloseCurrentPopup() {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            currentPopup = nullptr;
        }
    }
}
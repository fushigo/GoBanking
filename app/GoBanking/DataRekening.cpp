#include "DataRekening.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include <msclr/marshal_cppstd.h>

namespace GoBanking {
    using namespace std;
    using json = nlohmann::json;

    string dateFilterRekening;
    string searchFilterRekening;

    string nomorRek;

    // Mengambil data dari API
    static string getData() {
        API api;
        string endpoint = "/rekening";
        string response;

        try {
            response = api.GET(endpoint);
        }
        catch (System::String^ err) {
            System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
        }

        return response.data();
    }

    static string deleteData(const string& norek) {
        API api;
        string endpoint = "/rekening/norek/" + norek;
        string response;

        try {
            response = api.REQDELETE(endpoint);
        }
        catch (System::String^ err) {
            System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
        }

        return response.data();
    }

    // Menampilkan data nasabah
    System::Void DataRekening::DataRekening_Load(System::Object^ sender, System::EventArgs^ e) {

        string dataRekening = getData();

        if (dataRekening.empty()) {
            System::Windows::Forms::MessageBox::Show("Gagal mengambil data!.", "Terjadi kesalahan");
            return;
        }
        else {
            try {
                // Mengubah string dataRekening menjadi object json
                auto jsonData = json::parse(dataRekening);
                // Mengambil data object dengan key "data"
                auto& data = jsonData["data"];

                // Menghapus data rows
                dataGridViewRekening->Rows->Clear();

                // Mengambil data
                for (const auto& item : data) {
                    string createAt = item["createdAt"].get<string>();
                    string nomorRekening = item["nomorRekening"].get<string>();
                    string jenisTabungan = item["jenisTabungan"].get<string>();

                    // Filter data berdasarkan tanggal dibuat
                    if (!dateFilterRekening.empty() && createAt.substr(0, 10) != dateFilterRekening) {
                        continue;
                    }

                    // Filter data berdasarkan query nama lengkap atau nomor identitas (nik)
                    if (!searchFilterRekening.empty()) {
                        // Mengubah namaLengkap, nomorRekening, dan searchQuery menjadi lowercase
                        string jenis_lower = jenisTabungan, nomor_lower = nomorRekening, search_lower = searchFilterRekening;
                        transform(jenis_lower.begin(), jenis_lower.end(), jenis_lower.begin(), tolower);
                        transform(nomor_lower.begin(), nomor_lower.end(), nomor_lower.begin(), tolower);
                        transform(search_lower.begin(), search_lower.end(), search_lower.begin(), tolower);

                        // Melakukan filter data dengan case intensitive
                        if (jenis_lower.find(search_lower) == string::npos && nomor_lower.find(search_lower) == string::npos) {
                            continue;
                        }
                    }

                    // Konversi data string menggunakan marshal_as menjadi System::String / String^
                    String^ nomorrek = msclr::interop::marshal_as<String^>(item["nomorRekening"].get<string>());
                    String^ jenistabungan = msclr::interop::marshal_as<String^>(item["jenisTabungan"].get<string>());
                    String^ totaldana = msclr::interop::marshal_as<String^>(item["totalDana"].get<string>());
                    String^ bonus = msclr::interop::marshal_as<String^>(item["bonusBunga"].get<string>());
                    String^ dirubah = msclr::interop::marshal_as<String^>(item["updatedAt"].get<string>());
                    String^ dibuat = msclr::interop::marshal_as<String^>(item["createdAt"].get<string>());

                    // Mengubah pin menjadi **** saat ditampilkan
                    int pin_number = item["pin"].get<int>();
                    String^ pin = Convert::ToString(pin_number);
                    String^ maskedPin = gcnew String(L'*', pin->Length);

                    // Menampilkan data
                    dataGridViewRekening->Rows->Add(nomorrek, jenistabungan, totaldana, bonus, maskedPin, dibuat, dirubah);
                }
            }
            catch (json::exception& e) {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan saat parse json");
            }
        }
    }

    // Menangani kondisi ketika nilai dateTimePicker berubah
    System::Void DataRekening::dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
        DateTime datetime = dateTimePicker->Value;
        String^ isoFormatted = datetime.ToUniversalTime().ToString("yyyy-MM-dd");
        dateFilterRekening = msclr::interop::marshal_as<string>(isoFormatted);

        DataRekening_Load(nullptr, nullptr);
    }

    // Menangani ketika nilai textBox1 (Filter Pencarian) berubah
    System::Void DataRekening::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ textValue = textBox1->Text;
        searchFilterRekening = msclr::interop::marshal_as<string>(textValue);
    }

    System::Void DataRekening::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        DataRekening_Load(nullptr, nullptr);
    }

    // Menangani kondisi ketika button reset ditekan
    System::Void DataRekening::button1_Click(System::Object^ sender, System::EventArgs^ e) {
        dateFilterRekening = "";
        searchFilterRekening = "";

        DataRekening_Load(nullptr, nullptr);
    }

    System::Void DataRekening::dataGridViewRekening_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && dataGridViewRekening->Rows->Count > 0) {

            if (e->ColumnIndex == dataGridViewRekening->Columns["edit"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridViewRekening->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                    );

                if (dataGridViewRekening->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridViewRekening->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    //buttonCell->Style->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    //buttonCell->Style->SelectionBackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    ShowPopupEdit();
                }
            }

            else if (e->ColumnIndex == dataGridViewRekening->Columns["deletecol"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridViewRekening->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                    );

                if (dataGridViewRekening->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridViewRekening->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    //buttonCell->Style->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    //buttonCell->Style->SelectionBackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    ShowConfirmationPopup();
                }
            }
        }
    }


    System::Void DataRekening::ShowConfirmationPopup() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        currentPopup->Size = System::Drawing::Size(400, 250);
        //currentPopup->SetActionButton1Position(250, 150);
        //currentPopup->SetActionButton2Position(0, 150);
        currentPopup->SetMessage("Apakah Anda yakin ingin menghapus data?");
        currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &DataRekening::OnConfirmDelete));
        currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &DataRekening::OnClose));
        currentPopup->ShowPopup();
    }


    System::Void DataRekening::ShowPopupEdit() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        cli::array<PopupForm::FormField^>^ fields = gcnew cli::array<PopupForm::FormField^>(4);

        fields[0] = gcnew PopupForm::FormField();
        fields[0]->label = "Nomor Rekening";
        fields[0]->type = "text";

        fields[1] = gcnew PopupForm::FormField();
        fields[1]->label = "Janis Tabungan";
        fields[1]->type = "text";

        fields[2] = gcnew PopupForm::FormField();
        fields[2]->label = "Total Dana";
        fields[2]->type = "text";

        fields[3] = gcnew PopupForm::FormField();
        fields[3]->label = "Bonus Bunga";
        fields[3]->type = "text";

        currentPopup->SetMessageVisible(false);

        currentPopup->SetActionButton1("Edit", gcnew EventHandler(this, &DataRekening::OnConfirmEdit));
        currentPopup->SetActionButton2("Close", gcnew EventHandler(this, &DataRekening::OnClose));

        currentPopup->CreateFormFields(fields);
        currentPopup->Size = System::Drawing::Size(400, 400);
        currentPopup->ShowPopup();
    }

    System::Void DataRekening::OnConfirmEdit(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessEdit();
        }
    }

    System::Void DataRekening::ProcessEdit() {

    }

    System::Void DataRekening::OnConfirmDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessDelete();
        }
    }

    System::Void DataRekening::ProcessDelete() {
    }

    System::Void DataRekening::ShowResultPopup(bool isSuccess, String^ message) {
        currentPopup = gcnew PopupForm();
        if (isSuccess) {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &DataRekening::OnResultConfirmed));
        }
        else {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &DataRekening::OnRetryDelete));
        }
        currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &DataRekening::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void DataRekening::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void DataRekening::OnRetryDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ShowConfirmationPopup();
        }
    }

    System::Void DataRekening::OnClose(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void DataRekening::CloseCurrentPopup() {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            currentPopup = nullptr;
        }
    }
}

#include "DataRekening.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include <msclr/marshal_cppstd.h>

namespace GoBanking {
    using namespace std;
    using json = nlohmann::json;

    struct {
        string dateFilterRekening;
        string searchFilterRekening;
    }filter;

    string nomorRek;

    // request data dari API
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

    // request memperbaharui data ke API
    static string updateData(const string& norek, const string& payload) {
        API api;
        string endpoint = "/rekening/norek/" + norek;
        string response;

        try
        {
            response = api.REQPATCH(endpoint,payload);
        }
        catch (String^ err)
        {
            System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
        }

        return response.data();
    }

    // request menghapus data ke API
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
                    if (!filter.dateFilterRekening.empty() && createAt.substr(0, 10) != filter.dateFilterRekening) {
                        continue;
                    }

                    // Filter data berdasarkan kata pencarian
                    if (!filter.searchFilterRekening.empty()) {
                        // Mengubah namaLengkap, nomorRekening, dan searchQuery menjadi lowercase
                        string jenis_lower = jenisTabungan, nomor_lower = nomorRekening, search_lower = filter.searchFilterRekening;
                        transform(jenis_lower.begin(), jenis_lower.end(), jenis_lower.begin(), tolower);
                        transform(nomor_lower.begin(), nomor_lower.end(), nomor_lower.begin(), tolower);
                        transform(search_lower.begin(), search_lower.end(), search_lower.begin(), tolower);

                        // Melakukan filter data dengan case intensitive
                        if (jenis_lower.find(search_lower) == string::npos && nomor_lower.find(search_lower) == string::npos) {
                            continue;
                        }
                    }

                    // Konversi data dengan tipe data string menggunakan marshal_as menjadi String^
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

                    // Menampilkan / menambahkan data ke dalam rows dataGridViewRekening 
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
        filter.dateFilterRekening = msclr::interop::marshal_as<string>(isoFormatted);

        DataRekening_Load(nullptr, nullptr);
    }

    // Menangani ketika nilai textBox1 (Filter Pencarian) berubah
    System::Void DataRekening::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ textValue = textBox1->Text;
        filter.searchFilterRekening = msclr::interop::marshal_as<string>(textValue);
    }

    // Menangani ketika tombol pencarian ditekan
    System::Void DataRekening::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        DataRekening_Load(nullptr, nullptr);
    }

    // Menangani ketika tombol reset filter ditekan
    System::Void DataRekening::btn_reset_Click(System::Object^ sender, System::EventArgs^ e)
    {
        filter.dateFilterRekening = "";
        filter.searchFilterRekening = "";

        DataRekening_Load(nullptr, nullptr);
    }

    // Menangani ketika cell di dalam dataGridViewRekening ditekan
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

                    nomorRek = msclr::interop::marshal_as<string>(dataGridViewRekening->Rows[e->RowIndex]->Cells[0]->Value->ToString());

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

                    nomorRek = msclr::interop::marshal_as<string>(dataGridViewRekening->Rows[e->RowIndex]->Cells[0]->Value->ToString());

                    ShowConfirmationPopup();
                }
            }
        }
    }

    // Fungsi untuk menampilkan pop-up konfirmasi
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

    // Fungsi untuk menampilkan pop-up edit
    System::Void DataRekening::ShowPopupEdit() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        cli::array<PopupForm::FormField^>^ fields = gcnew cli::array<PopupForm::FormField^>(3);

        fields[0] = gcnew PopupForm::FormField();
        fields[0]->label = "Nomor Rekening";
        fields[0]->type = "text";

        fields[1] = gcnew PopupForm::FormField();
        fields[1]->label = "Jenis Tabungan";
        fields[1]->type = "radio";
        fields[1]->options = gcnew cli::array<String^>{"GoSilver", "GoPlatinum", "GoPriority"};

        fields[2] = gcnew PopupForm::FormField();
        fields[2]->label = "Total Dana";
        fields[2]->type = "text";

        currentPopup->SetMessageVisible(false);

        currentPopup->SetActionButton1("Edit", gcnew EventHandler(this, &DataRekening::OnConfirmEdit));
        currentPopup->SetActionButton2("Close", gcnew EventHandler(this, &DataRekening::OnClose));

        currentPopup->CreateFormFields(fields);
        currentPopup->Size = System::Drawing::Size(400, 400);
        currentPopup->ShowPopup();
    }

    // Fungsi untuk menangani kondisi ketika tombol konfirmasi ditekan
    System::Void DataRekening::OnConfirmEdit(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessEdit();
        }
    }

    // Fungsi untuk menangani proses edit
    System::Void DataRekening::ProcessEdit() {
        String^ formData = currentPopup->GetFormData();
        cli::array<String^>^ lines = formData->Split(gcnew cli::array<Char> {'\n'}, StringSplitOptions::RemoveEmptyEntries);

        System::Collections::Generic::Dictionary<String^, String^>^ data = gcnew System::Collections::Generic::Dictionary<String^, String^>();

        for each (String ^ line in lines) {
            int colonIndex = line->IndexOf(":");
            if (colonIndex != -1) {
                String^ label = line->Substring(0, colonIndex)->Trim();
                String^ value = line->Substring(colonIndex + 1)->Trim();
                data[label] = value;
            }
        }

        // Membuat tipe data json;
        json payjson;

        // Menangani apabila di dalam formdata terdapat key Nomor Rekening
        if (data->ContainsKey("Nomor Rekening") && data["Nomor Rekening"] != "") {
            payjson["nomorRekening"] = msclr::interop::marshal_as<string>(data["Nomor Rekening"]);
        }

        // Menangani apabila di dalam formdata terdapat key Jenis Tabungan
        if (data->ContainsKey("Jenis Tabungan") && data["Jenis Tabungan"] != "") {
            payjson["jenisTabungan"] = msclr::interop::marshal_as<string>(data["Jenis Tabungan"]);
        }

        // Mengangani apabila di dalam fromdata terdapat key Total Dana
        if (data->ContainsKey("Total Dana") && data["Total Dana"] != "") {
            payjson["totalDana"] = msclr::interop::marshal_as<string>(data["Total Dana"]);
        }

        try {
            // Membuat variable dengan tipe auto agar bisa menyesuaikan dengan tipe data json
            auto jsonData = json::parse(updateData(nomorRek, payjson.dump()));
            auto& statusCode = jsonData["statusCode"], & message = jsonData["message"];

            // Menangani ketika nilai dari statusCode adalah 200
            if (statusCode.get<int>() == 200) {
                // Menampilkan pop-up hasil
                ShowResultPopup(true, "Berhasil mengubah data");
                // Melakukan reset pada variable nomorRek
                nomorRek = "";
                // Memanggil kembali fungsi untuk menampilkan data
                DataRekening_Load(nullptr, nullptr);
            }
            else {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(msclr::interop::marshal_as<String^>(message.get<string>())), "Terjadi kesalahan");
                nomorRek = "";
                return;
            }
        }
        catch (json::exception err) {
            System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
        }
    }

    // Fungsi untuk menangani ketika tombol konfirmasi ditekan
    System::Void DataRekening::OnConfirmDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessDelete();
        }
    }

    // Fungsi untuk menangani proses menghapus data
    System::Void DataRekening::ProcessDelete() {
        try
        {
            auto jsonData = json::parse(deleteData(nomorRek));
            auto& statusCode = jsonData["statusCode"], & message = jsonData["message"];

            if (statusCode.get<int>() == 200) {
                ShowResultPopup(true, "Berhasil menghapus data");
            }
            else {
                nomorRek = "";
                ShowResultPopup(false, msclr::interop::marshal_as<String^>(message.get<string>()));
                DataRekening_Load(nullptr, nullptr);
            }
        }
        catch (json::exception err)
        {
            System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
        }
    }

    // Fungsi untuk menampilkan pop-up hasil
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

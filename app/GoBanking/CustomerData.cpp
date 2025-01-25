#include "CustomerData.h"
#include "Api.h"
#include "nlohmann/json.hpp"
#include <msclr/marshal_cppstd.h>

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

    struct filteringNasabah{
        string dateFilter;
        string searchFilter;
    };

    filteringNasabah filter;

    string nomorNik;

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

    // Menampilkan data nasabah
    System::Void CustomerData::CustomerData_Load(System::Object^ sender, System::EventArgs^ e) {

        string dataNasabah = apiRequester("/nasabah", "", "", "GET");

        if (dataNasabah.empty()) {
            System::Windows::Forms::MessageBox::Show("Gagal mengambil data!.", "Terjadi kesalahan");
            return;
        }
        else {
            try {
                // Mengubah string dataNasabah menjadi object json
                auto jsonData = json::parse(dataNasabah);
                // Mengambil data object dengan key "data"
                auto& data = jsonData["data"];

                // Menghapus data rows
                dataGridView->Rows->Clear();

                // Mengambil data
                for (const auto& item : data) {
                    string createAt = item["createdAt"].get<string>();
                    string namaLengkap = item["namaLengkap"].get<string>();
                    string nik = item["nik"].get<string>();

                    // Filter data berdasarkan tanggal dibuat
                    if (!filter.dateFilter.empty() && createAt.substr(0, 10) != filter.dateFilter) {
                        continue;
                    }

                    // Filter data berdasarkan query nama lengkap atau nomor identitas (nik)
                    if (!filter.searchFilter.empty()) {
                        // Mengubah namaLengkap, nik, dan searchQuery menjadi lowercase
                        string nama_lower = namaLengkap, nik_lower = nik, search_lower = filter.searchFilter;
                        transform(nama_lower.begin(), nama_lower.end(), nama_lower.begin(), tolower);
                        transform(nik_lower.begin(), nik_lower.end(), nik_lower.begin(), tolower);
                        transform(search_lower.begin(), search_lower.end(), search_lower.begin(), tolower);

                        // Melakukan filter data dengan case intensitive
                        if (nama_lower.find(search_lower) == string::npos && nik_lower.find(search_lower) == string::npos) {
                            continue;
                        }
                    }

                    // Konversi data string menggunakan marshal_as menjadi System::String / String^
                    String^ nmIdentitas = msclr::interop::marshal_as<String^>(item["nik"].get<string>());
                    String^ namaNasabah = msclr::interop::marshal_as<String^>(item["namaLengkap"].get<string>());
                    String^ jenisKelamin = msclr::interop::marshal_as<String^>(item["jenisKelamin"].get<string>());
                    String^ email = msclr::interop::marshal_as<String^>(item["email"].get<string>());
                    String^ nomorTelephone = msclr::interop::marshal_as<String^>(item["nomorTelepone"].get<string>());
                    String^ dirubah = msclr::interop::marshal_as<String^>(item["updateAt"].get<string>());
                    String^ dibuat = msclr::interop::marshal_as<String^>(item["createdAt"].get<string>());

                    // Menampilkan data
                    dataGridView->Rows->Add(nmIdentitas, namaNasabah, jenisKelamin, email, nomorTelephone, dibuat, dirubah);
                }
            }
            catch (json::exception& e) {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan saat parse json");
            }
        }
    }

	// Menangani kondisi ketika nilai dateTimePicker berubah
	System::Void CustomerData::dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		DateTime datetime = dateTimePicker->Value;
        String^ isoFormatted = datetime.ToUniversalTime().ToString("yyyy-MM-dd");
		filter.dateFilter = msclr::interop::marshal_as<string>(isoFormatted);

		CustomerData_Load(nullptr, nullptr);
	}

    // Menangani ketika nilai textBox1 (Filter Pencarian) berubah
    System::Void CustomerData::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        filter.searchFilter = msclr::interop::marshal_as<string>(textBox1->Text);
    }

    System::Void CustomerData::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        CustomerData_Load(nullptr, nullptr);
    }

    // Menangani kondisi ketika button reset ditekan
    System::Void CustomerData::button1_Click(System::Object^ sender, System::EventArgs^ e) {
        filter.dateFilter = "";
        filter.searchFilter = "";

        CustomerData_Load(nullptr, nullptr);
    }

    // Fungsi untuk menangani ketika cells di dalam dataGridView ditekan
    System::Void CustomerData::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && dataGridView->Rows->Count > 0) {

            if (e->ColumnIndex == dataGridView->Columns["edit"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                );

                if (dataGridView->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    //buttonCell->Style->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    //buttonCell->Style->SelectionBackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    String^ noNik = dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
                    nomorNik = msclr::interop::marshal_as<string>(noNik);

                    ShowPopupEdit();
                }
            }

            else if (e->ColumnIndex == dataGridView->Columns["deletecol"]->Index) {
                DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(
                    dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]
                );

                if (dataGridView->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
                    !String::IsNullOrEmpty(dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString()))
                {
                    buttonCell->FlatStyle = FlatStyle::Flat;
                    //buttonCell->Style->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->ForeColor = System::Drawing::Color::White;
                    //buttonCell->Style->SelectionBackColor = System::Drawing::Color::FromArgb(43, 39, 56);
                    buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;

                    String^ noNik = dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
                    nomorNik = msclr::interop::marshal_as<string>(noNik);

                    ShowConfirmationPopup();
                }
            }
        }
    }

    System::Void CustomerData::ShowConfirmationPopup() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        currentPopup->Size = System::Drawing::Size(400, 250);
        //currentPopup->SetActionButton1Position(250, 150);
        //currentPopup->SetActionButton2Position(0, 150);
        currentPopup->SetMessage("Apakah Anda yakin ingin menghapus data?");
        currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &CustomerData::OnConfirmDelete));
        currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &CustomerData::OnClose));
        currentPopup->ShowPopup();
    }


    System::Void CustomerData::ShowPopupEdit() {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        cli::array<PopupForm::FormField^>^ fields = gcnew cli::array<PopupForm::FormField^>(5);

        fields[0] = gcnew PopupForm::FormField();
        fields[0]->label = "Nomor Identitas";
        fields[0]->type = "text";

        fields[1] = gcnew PopupForm::FormField();
        fields[1]->label = "Nama Nasabah";
        fields[1]->type = "text";

        fields[2] = gcnew PopupForm::FormField();
        fields[2]->label = "Jenis Kelamin";
        fields[2]->type = "radio";
        fields[2]->options = gcnew cli::array<String^>{"Laki-laki", "Perempuan"};

        fields[3] = gcnew PopupForm::FormField();
        fields[3]->label = "Email";
        fields[3]->type = "text";

        fields[4] = gcnew PopupForm::FormField();
        fields[4]->label = "Nomor Telephone";
        fields[4]->type = "text";

        currentPopup->SetMessageVisible(false);

        currentPopup->SetActionButton1("Edit", gcnew EventHandler(this, &CustomerData::OnConfirmEdit));
        currentPopup->SetActionButton2("Close", gcnew EventHandler(this, &CustomerData::OnClose));

        currentPopup->CreateFormFields(fields);
        currentPopup->Size = System::Drawing::Size(400, 400);
        currentPopup->ShowPopup();
    }

    System::Void CustomerData::OnConfirmEdit(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessEdit();
        }
    }

    System::Void CustomerData::ProcessEdit() {

    }

    System::Void CustomerData::OnConfirmDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessDelete();
        }
    }

    System::Void CustomerData::ProcessDelete() {
        if (nomorNik.empty()) {
            System::Windows::Forms::MessageBox::Show("Nomor Identitas diperlukan", "Terjadi kesalahan");
        }

        try {
            auto jsonData = json::parse(apiRequester("/nasabah/nik/", "", nomorNik, "DELETE"));
            int statusCode = jsonData["statusCode"].get<int>();

            if (statusCode == 200) {
                nomorNik = "";
                ShowResultPopup(true, "Berhasil menghapus data");
                CustomerData_Load(nullptr, nullptr);
            }
        }
        catch (json::exception err) {
            System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse json");
        }
    }

    System::Void CustomerData::ShowResultPopup(bool isSuccess, String^ message) {
        currentPopup = gcnew PopupForm();
        if (isSuccess) {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &CustomerData::OnResultConfirmed));
        }
        else {
            currentPopup->SetMessage(message);
            currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &CustomerData::OnRetryDelete));
        }
        currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &CustomerData::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void CustomerData::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void CustomerData::OnRetryDelete(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ShowConfirmationPopup();
        }
    }

    System::Void CustomerData::OnClose(System::Object^ sender, System::EventArgs^ e) {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void CustomerData::CloseCurrentPopup() {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            currentPopup = nullptr;
        }
    }
}
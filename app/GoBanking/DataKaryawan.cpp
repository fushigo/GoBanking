#include "DataKaryawan.h"
#include "msclr/marshal_cppstd.h"
#include "nlohmann/json.hpp"
#include "sstream"
#include "Api.h"
#include "PopupForm.h"

namespace GoBanking {
    using namespace std;
    using json = nlohmann::json;

    struct Filtering {
        string date;
        string search;
    }filter;

    string nm_karyawan;

    static string getKaryawan() {
        API api;
        string endpoint = "/karyawan";
        string response;

        try {
            response = api.GET(endpoint);
        }
        catch (String^ e) {
            System::Windows::Forms::MessageBox::Show(e, "Terjadi kesalahan");
        }

        return response.data();
    }

    static string postKaryawan(const string& payload) {
        API api;
        string endpoint = "/karyawan";
        string response;

        try {
            response = api.POST(endpoint, payload);
        }
        catch (String^ e) {
            System::Windows::Forms::MessageBox::Show(e, "Terjadi kesalahan");
        }

        return response.data();
    }


    static string updateKaryawan(const string& payload) {
        API api;
        string endpoint = "/karyawan/nokrywn/" + nm_karyawan;
        string response;

        try {
            response = api.REQPATCH(endpoint, payload);
        }
        catch (String^ e) {
            System::Windows::Forms::MessageBox::Show(e, "Terjadi kesalahan");
        }

        return response.data();
    }

    static string deleteKaryawan() {
        API api;
        string endpoint = "/karyawan/nokrywn/" + nm_karyawan;
        string response;

        try {
            response = api.REQDELETE(endpoint);
        }
        catch (String^ e) {
            System::Windows::Forms::MessageBox::Show(e, "Terjadi kesalahan");
        }

        return response.data();
    }

    static string generateRandomNumber() {
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);

        std::ostringstream oss;
        oss << (localTime->tm_year + 1900) // Tahun
            << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) // Bulan
            << std::setw(2) << std::setfill('0') << localTime->tm_mday // Hari
            << std::setw(2) << std::setfill('0') << localTime->tm_hour // Jam
            << std::setw(2) << std::setfill('0') << localTime->tm_min // Menit
            << std::setw(2) << std::setfill('0') << localTime->tm_sec; // Detik

        srand(static_cast<unsigned int>(now));
        int randomNumber = rand() % 1000; // Range: 0-999
        oss << std::setw(3) << std::setfill('0') << randomNumber;

        return oss.str();
    }

    System::Void DataKaryawan::ShowPopupCreate()
    {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        cli::array<PopupForm::FormField^>^ fields = gcnew cli::array<PopupForm::FormField^>(4);

        fields[0] = gcnew PopupForm::FormField();
        fields[0]->label = "Nama Karyawan";
        fields[0]->type = "text";

        fields[1] = gcnew PopupForm::FormField();
        fields[1]->label = "Username";
        fields[1]->type = "text";

        fields[2] = gcnew PopupForm::FormField();
        fields[2]->label = "Role";
        fields[2]->type = "radio";
        fields[2]->options = gcnew cli::array<String^>{"Admin", "Karyawan"};

        fields[3] = gcnew PopupForm::FormField();
        fields[3]->label = "Password";
        fields[3]->type = "text";

        currentPopup->SetMessageVisible(false);

        currentPopup->SetActionButton1("Tambah", gcnew EventHandler(this, &DataKaryawan::OnConfirmCreate));
        currentPopup->SetActionButton2("Close", gcnew EventHandler(this, &DataKaryawan::OnClose));

        currentPopup->CreateFormFields(fields);
        currentPopup->Size = System::Drawing::Size(400, 400);
        currentPopup->ShowPopup();
    }

    System::Void DataKaryawan::ShowConfirmationPopup()
    {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        currentPopup->Size = System::Drawing::Size(400, 250);
        currentPopup->SetMessage("Apakah Anda yakin ingin menghapus data?");
        currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &DataKaryawan::OnConfirmDelete));
        currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &DataKaryawan::OnClose));
        currentPopup->ShowPopup();
    }

    System::Void DataKaryawan::ShowPopupEdit()
    {
        CloseCurrentPopup();
        currentPopup = gcnew PopupForm();
        cli::array<PopupForm::FormField^>^ fields = gcnew cli::array<PopupForm::FormField^>(3);

        fields[0] = gcnew PopupForm::FormField();
        fields[0]->label = "Nama Karyawan";
        fields[0]->type = "text";

        fields[1] = gcnew PopupForm::FormField();
        fields[1]->label = "Username";
        fields[1]->type = "text";

        fields[2] = gcnew PopupForm::FormField();
        fields[2]->label = "Role";
        fields[2]->type = "radio";
        fields[2]->options = gcnew cli::array<String^>{"Admin", "Karyawan"};

        currentPopup->SetMessageVisible(false);

        currentPopup->SetActionButton1("Edit", gcnew EventHandler(this, &DataKaryawan::OnConfirmEdit));
        currentPopup->SetActionButton2("Close", gcnew EventHandler(this, &DataKaryawan::OnClose));

        currentPopup->CreateFormFields(fields);
        currentPopup->Size = System::Drawing::Size(400, 400);
        currentPopup->ShowPopup();
    }

    System::Void DataKaryawan::OnConfirmCreate(System::Object^ sender, System::EventArgs^ e)
    {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessCreate();
        }
    }

    System::Void DataKaryawan::OnConfirmDelete(System::Object^ sender, System::EventArgs^ e)
    {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessDelete();
        }
    }

    System::Void DataKaryawan::OnConfirmEdit(System::Object^ sender, System::EventArgs^ e)
    {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ProcessEdit();
        }
    }

    System::Void DataKaryawan::ProcessCreate()
    {
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

        json payjson;
        payjson["nomorKaryawan"] = generateRandomNumber();
        payjson["namaKaryawan"] = msclr::interop::marshal_as<string>(data["Nama Karyawan"]);
        payjson["username"] = msclr::interop::marshal_as<string>(data["Username"]);
        payjson["password"] = msclr::interop::marshal_as<string>(data["Password"]);
        payjson["role"] = msclr::interop::marshal_as<string>(data["Role"]);

        try {
            string response = postKaryawan(payjson.dump());

            auto jsonData = json::parse(response);
            auto& statusCode = jsonData["statusCode"], & message = jsonData["message"];

            if (statusCode.get<int>() == 500) {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(msclr::interop::marshal_as<String^>(message.get<string>())), "Terjadi kesalahan");
                return;
            }
            else {
                ShowResultPopup(true, "Berhasil menambahkan data karyawan");
                DataKaryawan_load(nullptr, nullptr);
                return;
            }

        }catch(json::exception err) {
            System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
        }
        /*for each (auto kvp in data) {
            System::Windows::Forms::MessageBox::Show("Label: " + kvp.Key + "\nValue: " + kvp.Value);
        }*/
    }

    System::Void DataKaryawan::ProcessDelete()
    {
        try {
            auto jsonData = json::parse(deleteKaryawan());
            auto& statusCode = jsonData["statusCode"], & message = jsonData["message"];

            if (statusCode == 200) {
                nm_karyawan = "";
                ShowResultPopup(true, "Berhasil menghapus data karyawan");
                DataKaryawan_load(nullptr, nullptr);
            }
            else {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(msclr::interop::marshal_as<String^>(message.get<string>())), "Terjadi kesalahan");
                return;
            }
        }
        catch (json::exception err) {
            System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse json");
        }
    }

    System::Void DataKaryawan::ProcessEdit()
    {
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

        json payjson;

        if(data->ContainsKey("Nama Karyawan") && data["Nama Karyawan"] != "") {
            payjson["namaKaryawan"] = msclr::interop::marshal_as<string>(data["Nama Karyawan"]);
        }

        if (data->ContainsKey("Username") && data["Username"] != "") {
            payjson["username"] = msclr::interop::marshal_as<string>(data["Username"]);
        }

        if (data->ContainsKey("Role")) {
            payjson["role"] = msclr::interop::marshal_as<string>(data["Role"]);
        }

        try {
            string response = updateKaryawan(payjson.dump());

            auto jsonData = json::parse(response);
            auto& statusCode = jsonData["statusCode"], message = jsonData["message"];

            if (statusCode.get<int>() == 500) {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(msclr::interop::marshal_as<String^>(message.get<string>())), "Terjadi kesalahan");
                return;
            }
            else {
                ShowResultPopup(true, "Berhasil mengubah data karyawan");
                nm_karyawan = "";
                DataKaryawan_load(nullptr, nullptr);
                return;
            }

        }
        catch (json::exception err) {
            System::Windows::Forms::MessageBox::Show(gcnew System::String(err.what()), "Terjadi kesalahan saat parse JSON");
        }
    }

    System::Void DataKaryawan::ShowResultPopup(bool isSuccess, String^ message)
    {
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

    System::Void DataKaryawan::OnResultConfirmed(System::Object^ sender, System::EventArgs^ e)
    {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void DataKaryawan::OnRetryDelete(System::Object^ sender, System::EventArgs^ e)
    {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            ShowConfirmationPopup();
        }
    }

    System::Void DataKaryawan::OnClose(System::Object^ sender, System::EventArgs^ e)
    {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
        }
    }

    System::Void DataKaryawan::CloseCurrentPopup()
    {
        if (currentPopup != nullptr) {
            currentPopup->ClosePopup();
            currentPopup = nullptr;
        }
    }

    System::Void DataKaryawan::btnCreate_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ShowPopupCreate();
    }

    System::Void DataKaryawan::DataKaryawan_load(System::Object^ sender, System::EventArgs^ e)
    {
        string dataKaryawan = getKaryawan();

        if (dataKaryawan.empty()) {
            System::Windows::Forms::MessageBox::Show("Gagal mengambil data!.", "Terjadi kesalahan");
            return;
        }
        else {
            try {
                auto jsonData = json::parse(dataKaryawan);
                auto& data = jsonData["data"];

                dataGridViewKaryawan->Rows->Clear();

                // Mengambil data
                for (const auto& item : data) {
                    string createAt = item["createdAt"].get<string>();
                    string nama_karyawan = item["namaKaryawan"].get<string>();
                    string nomor_karyawan = item["nomorKaryawan"].get<string>();

                    // Filter data berdasarkan tanggal dibuat
                    if (!filter.date.empty() && createAt.substr(0, 10) != filter.date) {
                        continue;
                    }

                    if (!filter.search.empty()) {
                        string nama_lower = nama_karyawan, nomor_lower = nomor_karyawan, search_lower = filter.search;
                        transform(nama_lower.begin(), nama_lower.end(), nama_lower.begin(), tolower);
                        transform(nomor_lower.begin(), nomor_lower.end(), nomor_lower.begin(), tolower);
                        transform(search_lower.begin(), search_lower.end(), search_lower.begin(), tolower);

                        // Melakukan filter data dengan case intensitive
                        if (nama_lower.find(search_lower) == string::npos && nomor_lower.find(search_lower) == string::npos) {
                            continue;
                        }
                    }

                    // Konversi data string menggunakan marshal_as menjadi System::String / String^
                    String^ nomorKaryawan = msclr::interop::marshal_as<String^>(item["nomorKaryawan"].get<string>());
                    String^ namaKaryawan = msclr::interop::marshal_as<String^>(item["namaKaryawan"].get<string>());
                    String^ username = msclr::interop::marshal_as<String^>(item["username"].get<string>());
                    String^ role = msclr::interop::marshal_as<String^>(item["role"].get<string>());
                    String^ dirubah = msclr::interop::marshal_as<String^>(item["updatedAt"].get<string>());
                    String^ dibuat = msclr::interop::marshal_as<String^>(item["createdAt"].get<string>());

                    // Menampilkan data
                    dataGridViewKaryawan->Rows->Add(nomorKaryawan, namaKaryawan, username, role, dibuat, dirubah);
                }
            }
            catch (json::exception& e) {
                System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan saat parse json");
            }
        }
    }

    System::Void DataKaryawan::dataGridViewKaryawan_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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

                    nm_karyawan = msclr::interop::marshal_as<string>(dataGridViewKaryawan->Rows[e->RowIndex]->Cells[0]->Value->ToString());

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

                    nm_karyawan = msclr::interop::marshal_as<string>(dataGridViewKaryawan->Rows[e->RowIndex]->Cells[0]->Value->ToString());

                    ShowConfirmationPopup();
                }
            }
        }
    }
}
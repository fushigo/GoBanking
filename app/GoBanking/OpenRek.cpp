#include "OpenRek.h"
#include "nlohmann/json.hpp";
#include "Api.h"
#include "msclr/marshal_cppstd.h"
#include "sstream"
#include "PopupForm.h"

namespace GoBanking {
	using namespace std;
	using json = nlohmann::json;

	struct 
	{
		string textFullname, textNik, textEmail, textTelepone, textJnKelamin, textDpAwal, textPinRekening;
	}nasabah;

	static string postData(string& payload) {
		API api;
		string endpoint = "/rekening/newrek";
		string response;

		try
		{
			response = api.POST(endpoint, payload);
		}
		catch (String^ err)
		{
			System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
		}

		return response.data();
	}

	static string generateRandomNumber() {
		time_t now = time(nullptr);
		tm* localTime = localtime(&now);

		long long timestapm = static_cast<long long>(now);
		srand(static_cast<unsigned int>(timestapm));

		int randomNumber = rand() % 1000;

		ostringstream oss;
		oss << localTime->tm_year + 1900
			<< localTime->tm_mon + 1
			<< localTime->tm_mday
			<< localTime->tm_hour
			<< localTime->tm_min
			<< localTime->tm_sec
			<< randomNumber;

		return oss.str();
	}

	static string validateRekening(const double value) {
		if (value >= 5000000.0) {
			return "GoPriority";
		}
		else if (value >= 2000000.0) {
			return "GoPlatinum";
		}
		else if (value >= 1500000.0) {
			return "GoSilver";
		}

		return "invalid";
	} 

	System::Void OpenRek::fullnameInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		nasabah.textFullname = msclr::interop::marshal_as<string>(fullnameInput->Text);
	}

	System::Void OpenRek::nikInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		nasabah.textNik = msclr::interop::marshal_as<string>(nikInput->Text);
	}

	System::Void OpenRek::emailInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		nasabah.textEmail = msclr::interop::marshal_as<string>(emailInput->Text);
	}

	System::Void OpenRek::phoneNumberInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		nasabah.textTelepone = msclr::interop::marshal_as<string>(phoneNumberInput->Text);
	}

	System::Void OpenRek::maleRadButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (maleRadButton->Checked) {
			nasabah.textJnKelamin = "pria";
		}
	}

	System::Void OpenRek::femaleRadButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (femaleRadButton->Checked) {
			nasabah.textJnKelamin = "wanita";
		}
	}

	System::Void OpenRek::depositoInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (!System::Text::RegularExpressions::Regex::IsMatch(depositoInput->Text, "^[0-9]*\\.?[0-9]+$")) {
			System::Windows::Forms::MessageBox::Show("Hanya angka yang diizinkan.", "Terjadi kesalahan");
			depositoInput->Text = "0";
			return;
		}

		nasabah.textDpAwal = msclr::interop::marshal_as<string>(depositoInput->Text);
	}

	System::Void OpenRek::pinInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		nasabah.textPinRekening = msclr::interop::marshal_as<string>(pinInput->Text);
	}

	System::Void OpenRek::btnOpenRek_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (nasabah.textDpAwal.empty()) {
			System::Windows::Forms::MessageBox::Show("Data deposit tidak boleh kosong", "Terjadi kesalahan");
			return;
		}

		if (stod(nasabah.textDpAwal) < 1500000) {
			MessageBox::Show("Data deposit tidak bisa kurang dari Rp 1.500.000", "Terjadi kesalahan", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (nasabah.textEmail.empty()) {
			System::Windows::Forms::MessageBox::Show("Data email tidak boleh kosong", "Terjadi kesalahan");
			return;
		}

		if (nasabah.textFullname.empty()) {
			System::Windows::Forms::MessageBox::Show("Data nama tidak boleh kosong", "Terjadi kesalahan");
			return;
		}

		if (nasabah.textJnKelamin.empty()) {
			System::Windows::Forms::MessageBox::Show("Data jenis kelamin tidak boleh kosong", "Terjadi kesalahan");
			return;
		}

		if (nasabah.textNik.empty()) {
			System::Windows::Forms::MessageBox::Show("Data nik tidak boleh kosong", "Terjadi kesalahan");
			return;
		}

		if (nasabah.textPinRekening.empty()) {
			System::Windows::Forms::MessageBox::Show("Data pin rekening tidak boleh kosong", "Terjadi kesalahan");
			return;
		}

		if (nasabah.textTelepone.empty()) {
			System::Windows::Forms::MessageBox::Show("Data nomor telepone tidak boleh kosong", "Terjadi kesalahan");
			return;
		}

		double depositValue = 0.0;
		try {
			depositValue = std::stod(nasabah.textDpAwal);
		}
		catch (const std::exception&) {
			System::Windows::Forms::MessageBox::Show("Deposit harus berupa angka valid.", "Terjadi kesalahan");
			return;
		}

		json payjson;

		payjson["nasabahDto"]["nik"] = nasabah.textNik;
		payjson["nasabahDto"]["namaLengkap"] = nasabah.textFullname;
		payjson["nasabahDto"]["email"] = nasabah.textEmail;
		payjson["nasabahDto"]["nomorTelepone"] = nasabah.textTelepone;
		payjson["nasabahDto"]["jenisKelamin"] = nasabah.textJnKelamin;
		payjson["rekeningDto"]["nomorRekening"] = generateRandomNumber();
		payjson["rekeningDto"]["jenisTabungan"] = validateRekening(depositValue);
		payjson["rekeningDto"]["totalDana"] = nasabah.textDpAwal;
		payjson["rekeningDto"]["bonusBunga"] = "0.0";
		payjson["rekeningDto"]["pin"] = nasabah.textPinRekening;

		try {
			string response = postData(payjson.dump());

			auto jsonData = json::parse(response);
			auto& status = jsonData["statusCode"], message = jsonData["message"];

			if (status.get<int>() == 500) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(msclr::interop::marshal_as<String^>(message.get<string>())), "Terjadi kesalahan");
				return;
			}
			else {
				System::Windows::Forms::MessageBox::Show("Berhasil menambahkan rekening dan nasabah baru", "Success");
				return;
			}
		}
		catch (json::exception e) {
			System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan");
			return;
		}
	}
}
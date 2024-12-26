#include "Login.h"
#include "Api.h"
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>

using namespace std;
using json = nlohmann::json;

// Mengambil data dari API
static string getData() {
	API api;
	string endpoint = "/karyawan";
	string response;

	try {
		response = api.GET(endpoint);
	}
	catch (System::String^ err) {
		System::Windows::Forms::MessageBox::Show(err, "Terjadi kesalahan");
	}

	return response.data();
}

namespace GoBanking {
	string textUsername;
	string textPassword;

	// Mengambil nilai username dari Input
	System::Void Login::usernameInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		textUsername = msclr::interop::marshal_as<std::string>(usernameInput->Text);
	}

	// Mengambil nilai password dari Input
	System::Void Login::passwordInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		textPassword = msclr::interop::marshal_as<std::string>(passwordInput->Text);
	}

	// Menangani kondisi apabila loginButton ditekan
	System::Void Login::loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string data_karyawan = getData();

		// Jika data karyawan kosong
		if (data_karyawan.empty()) {
			System::Windows::Forms::MessageBox::Show("Gagal mengambil data.", "Terjadi kesalahan");
			return;
		}
		else {
			try {
				// Mengubah string data_karyawan menjadi object json
				auto json_data = json::parse(data_karyawan);
				// Mengambil data object dengan key "data"
				auto& data = json_data["data"];

				bool validLogin = false;
				json matchedItem;

				//Melakukan for loop untuk mengambil data json
				for (const auto& item : data) {

					// Mengambil data / item sesuai key
					string storedUsername = item["username"].get<string>();
					string storedPassword = item["password"].get<string>();

					// Validasi username dan password
					if (storedUsername == textUsername && storedPassword == textPassword) {
						validLogin = true;
						matchedItem = item;
						break;
					}
				}

				// Jika validLogin bernilai "true"
				if (validLogin) {
					this->Hide();
					Home^ home = gcnew Home(matchedItem);
					home->ShowDialog();
					this->Show();
				}
				else {
					System::Windows::Forms::MessageBox::Show("Username atau kata sandi salah, silahkan coba kembali!", "Terjadi kesalahan");
				}
			}
			catch (json::exception& e) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "Terjadi kesalahan");
			}
		}
	}
}
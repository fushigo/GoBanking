#include "Login.h"
#include "Api.h"
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>

using namespace std;
using json = nlohmann::json;

static string getData() {
	API api;
	string endpoint = "/karyawan";
	string response;

	try {
		response = api.GET(endpoint);
	}
	catch (string err) {
		cout << "error while login" << err;
	}

	return response.data();
}

namespace GoBanking {
	string textUsername;
	string textPassword;

	System::Void Login::usernameInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		textUsername = msclr::interop::marshal_as<std::string>(usernameInput->Text);
	}

	System::Void Login::passwordInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		textPassword = msclr::interop::marshal_as<std::string>(passwordInput->Text);
	}

	System::Void Login::loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string data_karyawan = getData();

		if (data_karyawan.empty()) {
			System::Windows::Forms::MessageBox::Show("Failed to fetch data.", "Error");
			return;
		}
		else {
			try {
				auto json_data = json::parse(data_karyawan);

				auto& data = json_data["data"];

				bool validLogin = false;
				json matchedItem;
				for (const auto& item : data) {

					string storedUsername = item["username"].get<string>();
					string storedPassword = item["password"].get<string>();

					if (storedUsername == textUsername && storedPassword == textPassword) {
						validLogin = true;
						matchedItem = item;
						break;
					}
				}

				if (validLogin) {
					this->Hide();
					Home^ home = gcnew Home(matchedItem);
					home->ShowDialog();
					this->Show();
				}
				else {
					System::Windows::Forms::MessageBox::Show("Invalid username or password. Please try again!");
				}

				//System::Windows::Forms::MessageBox::Show(gcnew System::String(dataIndex0.c_str()));

			}
			catch (json::exception& e) {
				System::Windows::Forms::MessageBox::Show(gcnew System::String(e.what()), "JSON Parsing Error");
			}
		}
	}
}
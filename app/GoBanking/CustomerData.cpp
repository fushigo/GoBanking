#include "CustomerData.h"
#include "Api.h"
#include "iostream"

using namespace std;

namespace GoBanking {

	string getData() {
		API api;
		string endpoint = "/nasabah";
		string response;

		try {
			response = api.GET(endpoint);
		}
		catch (string err) {
			cout << "error while login" << err;
		}

		return response.data();
	}
}
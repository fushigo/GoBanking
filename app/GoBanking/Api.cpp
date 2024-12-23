#include "API.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

string API::GET(const string& endpoint) const {
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();

    if (curl) {
        string request_url = api_url + endpoint;
        curl_easy_setopt(curl, CURLOPT_URL, request_url.c_str());

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cout << "CURL request failed: " << string(curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
    else {
        cout << "Failed to initialize CURL";
    }

    return response;
}

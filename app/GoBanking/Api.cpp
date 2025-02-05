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

string API::POST(const string& endpoint, const string& payload) const {
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();

    if (curl) {
        string request_url = api_url + endpoint;
        curl_easy_setopt(curl, CURLOPT_URL, request_url.c_str());

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cout << "CURL request failed: " << string(curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    else {
        cout << "Failed to initialize CURL";
    }

    return response;
}

string API::REQPATCH(const string& endpoint, const string& payload) const {
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();

    if (curl) {
        string request_url = api_url + endpoint;
        curl_easy_setopt(curl, CURLOPT_URL, request_url.c_str());

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PATCH");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cout << "CURL request failed: " << string(curl_easy_strerror(res)) << endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    else {
        cout << "Failed to initialize CURL" << endl;
    }

    return response;
}

string API::REQDELETE(const string& endpoint) const {
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();

    if (curl) {
        string request_url = api_url + endpoint;
        curl_easy_setopt(curl, CURLOPT_URL, request_url.c_str());

        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cout << "CURL request failed: " << string(curl_easy_strerror(res)) << endl;
        }

        curl_easy_cleanup(curl);
    }
    else {
        cout << "Failed to initialize CURL" << endl;
    }

    return response;
}

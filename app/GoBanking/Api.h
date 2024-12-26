#pragma once
#ifndef API_H
#define API_H

#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* response);

class API {
public:
    string api_url = "https://go-banking-api.vercel.app";

    string GET(const string& endpoint) const;
    string POST(const string& endpoint, const string& payload) const;
};

#endif

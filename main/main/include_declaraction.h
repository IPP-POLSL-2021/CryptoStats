#pragma once
#pragma comment (lib, "cpr.lib")
#ifdef _DEBUG
#pragma comment (lib, "libcurl-d.lib")
#else
#pragma comment (lib, "libcurl.lib")
#endif
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")
#include <iostream>
#include <string>


#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iomanip>
// for convenience
using json = nlohmann::json;


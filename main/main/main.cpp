
#include <iostream>
#include <string>


#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;




int main()
{


    cpr::Response r = cpr::Get(cpr::Url{ "https://api.zonda.exchange/rest/trading/ticker/BTC-PLN" });
    //cpr::Parameters{ {"anon", "true"}, {"key", "value"} });

    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;                         // JSON text string

    auto jason_object = json::parse(r.text);

    std::cout << jason_object.dump(4) << std::endl;

    auto v1 = jason_object["ticker"]["highestBid"].get<std::string>();
    std::cout << v1 << std::endl;
    return 0;

}



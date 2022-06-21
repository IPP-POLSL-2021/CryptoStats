#pragma once
#include "MarketPairStats.h"
MarketPairStats::MarketPairStats(std::string pair_code)
{
    this->pair_code = pair_code;
    int attempts = 0;
    cpr::Response r;
	// We try three times to connect to server than display error message with cerr.
    while (attempts < 3)
    {
        try {
        std::string pair_url = "https://api.zonda.exchange/rest/trading/ticker/" + pair_code;
        r = cpr::Get(cpr::Url{ pair_url });
        //cpr::Parameters{ {"anon", "true"}, {"key", "value"} });
// checking whether the connection was successful
        if (r.status_code != 200)        // 200
            throw r.status_code;

        r.header["content-type"];       // application/json; charset=utf-8
        r.text;                         // JSON text string
        }
        catch (const int status_code)
        {
            std::cerr << "couldn't resolve curl connection status code: " << status_code;
            attempts++;
            if (attempts == 3)
            {
                std::cerr << "couldn't establish connection";
            }

        }
        auto jason_object = json::parse(r.text);
        this->jason_object = jason_object;
        attempts = 3;
    }

}

// Initializing destructor just to be sure.
MarketPairStats::~MarketPairStats()
{
}

// Parsing data we received
void MarketPairStats::showBidAsk()
{
    auto v1 = jason_object["ticker"]["highestBid"].get<std::string>();
    auto v2 = jason_object["ticker"]["lowestAsk"].get<std::string>();
    std::cout<<std::setw(1) << pair_code << "|" << std::setw(23) << v1 + "|" << std::setw(42) << v2 +"|" << std::endl;

}

// The name explains it well
void MarketPairStats::showAllStats()
{
    std::cout << jason_object.dump(4) << std::endl;
}

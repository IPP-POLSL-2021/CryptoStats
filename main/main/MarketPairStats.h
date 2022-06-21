#pragma once
#include "include_declaraction.h"
class MarketPairStats
{
public:
	MarketPairStats(std::string pair_code);
	~MarketPairStats();

	void showBidAsk();
	void showAllStats();

private:
	json jason_object;
	std::string pair_code;
};


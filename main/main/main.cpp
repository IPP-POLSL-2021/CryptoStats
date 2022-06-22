#pragma once
#include "include_declaraction.h"
#include "MarketPairStats.h"


int main(int argc, char* argv[])
{

	int size_of_trading_pairs = sizeof(list_of_trading_pairs) / sizeof(list_of_trading_pairs[0]);

		if(argc==1){
			ShowManPage();
		}
		else{
			std::string argv1 = argv[1];

			if (argv1 == "-help" && argc >= 3)
			{
				std::cout << "--help does not accept any arguments.";
			}
			else if (argv1 == "-help") {
				ShowManPage();
			}


			else if (argv1 == "--help" && argc >= 3)
			{
				std::cout << "--help does not accept any arguments.";
			}
			else if (argv1 == "--help")
			{
				ShowManPage();
			}


			else if (argv1 == "--all-info" && argc == 2)
			{
				std::cout << "-all-info requires at least 1 argument.";
			}
			else if (argv1 == "--all-info" && in_array(argv[2], list_of_trading_pairs, size_of_trading_pairs)){
				for (int i = 2; i <= argc - 1; i++) 
				{
					if (in_array(argv[i], list_of_trading_pairs, size_of_trading_pairs)) 
					{
						MarketPairStats* current_pair = new MarketPairStats(argv[i]);
						current_pair->showAllStats();
						delete current_pair;
					}
				}
			}


			else
			{
				std::cout << std::setw(8) << "|" << std::setw(23) << "bid|" << std::setw(42) << "ask|" << std::endl;
				for (int i = 1; i <= argc - 1; i++)
					if (in_array(argv[i], list_of_trading_pairs, size_of_trading_pairs )) 
					{
						MarketPairStats* current_pair = new MarketPairStats(argv[i]);
						current_pair->showBidAsk();
						delete current_pair;
					}
			}
		}	

    return 0;

}



#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

namespace security
{
	enum class State
	{
		kDefault,
		kAlarm,
		kQuiet
	};

	void checkFloor(const std::string& floor, State& securityState)
	{
		constexpr char chMoney{ '$' };
		constexpr char chGuard{ 'G' };
		constexpr char chThief{ 'T' };

		bool bHaveGuard = false;
		bool bHaveThief = false;

		// xxxxxGxx$xxxT
		for (std::string::const_iterator cIt{ floor.cbegin() }; cIt != floor.cend(); ++cIt)
		{
			if (*cIt == chGuard && bHaveThief == false && bHaveGuard == false) bHaveGuard = true;

			
		}
		 
		securityState = State::kQuiet;
	}
}

int main(int argc, char** argv)
{
	std::function<void(const std::string&)> output([](const std::string& msg)
	{
		std::cout << msg << std::endl;
	});

	std::string sFloor;
	std::getline(std::cin, sFloor);

	security::State securityState{ security::State::kDefault };
	security::checkFloor(sFloor, securityState);
	
	if (securityState == security::State::kAlarm)
	{
		output("ALARM");
	}
	else
	{
		output("quiet");
	}

	return 0;
}
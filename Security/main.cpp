// Created by Aleksandr Matyuhin

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
		constexpr char chFloor{ 'x' };

		bool bMoney = false;
		bool bAlarm = false;

		for (std::string::const_iterator cIt{ floor.cbegin() }; cIt != floor.cend(); ++cIt)
		{
			if (*cIt == chFloor) continue;

			if (*cIt == chMoney)
			{
				bMoney = true;
				continue;
			}

			if (bMoney == false)
			{
				switch (*cIt)
				{
				case chThief:
					if (bAlarm == false) bAlarm = true;
					break;

				case chGuard:
					if (bAlarm == true) bAlarm = false;
					break;
				}
			}
			else
			{
				if (bAlarm == false)
				{
					bAlarm = *cIt == chThief ? true : false;
				}
				break;
			}
		}

		securityState = bAlarm == true ? State::kAlarm : State::kQuiet;
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
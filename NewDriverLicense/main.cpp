#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

namespace ndl
{
	int stoi(const std::string& str, int* value, std::size_t* pos = (std::size_t*)nullptr, const int& base = 10)
	{
		try
		{
			*value = std::stoi(str, pos, base);

			*value = *value < 0 ? 0 : *value;

			return 0;
		}
		catch (const std::invalid_argument& ia)
		{
			return -1;
		}
		catch (const std::out_of_range& oor)
		{
			return -2;
		}
		catch (const std::exception& err)
		{
			return -3;
		}
	}
}


int main(int argc, char** argv)
{
	std::string sName;
	std::string sAgentCount;
	std::string sOtherNames;

	int agentCount = 0; 

	std::vector<std::string> names;

	std::getline(std::cin, sName);
	std::getline(std::cin, sAgentCount);
	std::getline(std::cin, sOtherNames);

	std::stringstream ss(sOtherNames);
	std::string otherName;

	while (std::getline(ss, otherName, ' '))
	{
		names.push_back(otherName);
	}
	
	ndl::stoi(sAgentCount, &agentCount);

	std::cout << sName << "\r\n" << agentCount << "\r\n" << sOtherNames;

	for (std::vector<std::string>::const_iterator it = names.cbegin(); it != names.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
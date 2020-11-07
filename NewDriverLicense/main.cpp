#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

namespace ndl
{
	int stoi(const std::string& str, std::size_t* pos = (std::size_t*)nullptr, const int& base = 10)
	{
		int tmpValue = 0;

		try
		{
			tmpValue = std::stoi(str, pos, base);

			tmpValue = tmpValue < 0 ? 0 : tmpValue;

			return tmpValue;
		}
		catch (const std::exception& err)
		{
			std::cout << err.what() << std::endl;
		}

		return 0;
	}

	namespace vector
	{
		void addItemsFromString(std::vector<std::string>& vector, const std::string& str, const char& separator = ' ')
		{
			std::stringstream sstream(str);
			std::string segment;

			while (std::getline(sstream, segment, separator))
			{
				vector.push_back(segment);
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::string sName; // Our name
	std::string snAgentCount; // Count of Agents
	std::string sOtherNames; // Names of other drivers

	// Input 
	std::getline(std::cin, sName);
	std::getline(std::cin, snAgentCount);
	std::getline(std::cin, sOtherNames);

	std::vector<std::string> names;

	names.push_back(sName);

	int nAgentCount = ndl::stoi(snAgentCount);

	// Extracting names from a string
	ndl::vector::addItemsFromString(names, sOtherNames);

	// Sort the names in alphabetical order
	std::sort(names.begin(), names.end());


	std::cout << sName << "\r\n" << nAgentCount << std::endl;

	for (std::vector<std::string>::const_iterator it = names.cbegin(); it != names.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
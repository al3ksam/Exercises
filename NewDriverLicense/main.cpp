#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

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

	void separateString(const std::string& str, std::vector<std::string>& vector, const char& separator = '_')
	{
		std::stringstream sstream(str);
		std::string segment;

		while (std::getline(sstream, segment, separator))
		{
			vector.push_back(segment);
		}
	}
}

int main(int argc, char** argv)
{
	std::string sName;
	std::string snAgentCount;
	std::string sOtherNames;

	std::vector<std::string> otherNames;

	std::getline(std::cin, sName);
	std::getline(std::cin, snAgentCount);
	std::getline(std::cin, sOtherNames);

	int nAgentCount = ndl::stoi(snAgentCount);

	ndl::separateString(sOtherNames, otherNames);


	std::cout << sName << "\r\n" << nAgentCount << std::endl;

	for (std::vector<std::string>::const_iterator it = otherNames.cbegin(); it != otherNames.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
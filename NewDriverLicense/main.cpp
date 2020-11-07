#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <initializer_list>

namespace ndl
{
	constexpr short kProcessTime = 20;

	void input(std::initializer_list<std::string* const> list)
	{
		for (std::string* const & data : list)
		{
			std::getline(std::cin, *data);
		}
	}

	void output(const short& time)
	{
		std::cout << time << std::endl;
	}

	short stoi(const std::string& str, std::size_t* pos = (std::size_t*)nullptr, const int& base = 10)
	{
		short tmpValue = 0;

		try
		{
			tmpValue = static_cast<short>(std::stoi(str, pos, base));

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

	std::vector<std::string> names;
	short time = 0;

	ndl::input({ &sName, &snAgentCount, &sOtherNames });

	names.push_back(sName);

	short nAgentCount = ndl::stoi(snAgentCount);

	// Agents have a day off :)
	if (nAgentCount <= 0)
	{
		ndl::output(time);
		return 0;
	}

	// Extracting names from a string
	ndl::vector::addItemsFromString(names, sOtherNames);

	// Sort the names in alphabetical order
	std::sort(names.begin(), names.end());

	short i = 0;
	for (std::vector<std::string>::const_iterator it = names.cbegin(); it != names.cend(); ++it, ++i)
	{
		
			time += ndl::kProcessTime;
		
		

		if (*it == sName) break;
	}

	ndl::output(time);



	for (std::vector<std::string>::const_iterator it = names.cbegin(); it != names.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
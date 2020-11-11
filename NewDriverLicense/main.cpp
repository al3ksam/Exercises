#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

namespace ndl
{
	// Minutes to process a new license.
	constexpr short kProcessTime{ 20 };

	struct Data
	{
		std::string sName; // Our name
		std::string snAgentCount; // Count of Agents
		std::string sOtherNames; // Names of other drivers
	};

	void input(Data& data)
	{
		std::getline(std::cin, data.sName);
		std::getline(std::cin, data.snAgentCount);
		std::getline(std::cin, data.sOtherNames);
	}

	void output(const short& time)
	{
		std::cout << time << std::endl;
	}

	short stoi(const std::string& str, std::size_t* pos = (std::size_t*)nullptr, const int& base = 10)
	{
		short tmpValue{ 0 };

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
	ndl::Data data;

	std::vector<std::string> names;
	short time{ 0 };

	ndl::input(data);

	names.push_back(data.sName);

	short nAgentCount{ ndl::stoi(data.snAgentCount) };

	// Agents have a day off :)
	if (nAgentCount == 0)
	{
		ndl::output(time);
		return 0;
	}

	// Extracting names from a string
	ndl::vector::addItemsFromString(names, data.sOtherNames);

	// Sort the names in alphabetical order
	std::sort(names.begin(), names.end());

	// Issuing new licenses
	short i{ 1 };
	time = ndl::kProcessTime;
	for (std::vector<std::string>::const_iterator it{ names.cbegin() }; it != names.cend(); ++it, ++i)
	{
		if (i > nAgentCount)
		{
			time += ndl::kProcessTime;
			i = 1;
		}		

		if (*it == data.sName) break;
	}

	ndl::output(time);

	return 0;
}
#include <iostream>
#include <string>

namespace pw
{
	bool isValidPassword(std::string& password)
	{
		return false;
	}
}

int main(int argc, const char** argv)
{
	std::string password;

	std::getline(std::cin, password);

	if (pw::isValidPassword(password))
	{
		std::cout << "Strong" << std::endl;
	}
	else
	{
		std::cout << "Weak" << std::endl;
	}

	return 0;
}
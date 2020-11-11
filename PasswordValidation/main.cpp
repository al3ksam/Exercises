#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

namespace pw
{
	bool isValidPassword(std::string& password)
	{
		constexpr short kMinPwdLength{ 7 };

		if (password.length() < kMinPwdLength) return false;

		const std::string sSpecialCharacters { "!@#$%&*"	};
		const std::string sNumbers           { "0123456789" };

		constexpr short kMinSpecialChars{ 2 };
		constexpr short kMinNumbers{ 2 };

		short nSpecialChars{ 0 };
		short nNumbers{ 0 };

		bool bIsValid = false;

		for 
		(
			std::string::const_iterator 
				pwdIt = password.cbegin(),	
				cIt = std::string::const_iterator(); 

			pwdIt != password.cend(); 
			++pwdIt
		)
		{
			if (nSpecialChars < kMinSpecialChars)
			{
				cIt = std::find(sSpecialCharacters.cbegin(), sSpecialCharacters.cend(), *pwdIt);
				if (cIt != sSpecialCharacters.cend())
				{
					++nSpecialChars;
				}
			}

			if (nNumbers < kMinNumbers)
			{
				cIt = std::find(sNumbers.cbegin(), sNumbers.cend(), *pwdIt);
				if (cIt != sNumbers.cend())
				{
					++nNumbers;
				}
			}

			bIsValid = nSpecialChars == kMinSpecialChars && nNumbers == kMinNumbers;
			
			if (bIsValid) break;
		}

		return bIsValid;
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
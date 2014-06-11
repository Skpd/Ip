#include <stdint.h>
#include <string>
#include <sstream>
#include <iostream>
#include <istream>
#include <vector>
#ifdef _MSVC
    #include <WinSock2.h>
    #pragma comment(lib,"ws2_32.lib")
#else
    #include <arpa/inet.h>
#endif

#include "Single.h"

namespace Ip 
{
	Single::Single(uint32_t address)
	{
		this->address = address;
	}

	Single::~Single()
	{
	}

	uint32_t Single::getAddress()
	{
		return address;
	}
	
	bool Single::buildFromString(std::string value, Single& ip)
	{
		size_t p = 3;
		std::string rValue;
		std::string buffer[4];

		for (auto it : value) {
			if (it == '.') {
				p--;
				continue;
			}

			buffer[p] += it;
		}

		for (size_t i = 0; i < 4; i++) {
			rValue += buffer[i];

			if (i < 3) {
				rValue += '.';
			}
		}

		uint32_t iValue = inet_addr(rValue.c_str());

		if (iValue) {
			ip.address = iValue;

			return true;
		}

		return false;
	}

	bool Single::buildFromString(std::string value, std::vector<Single>& list)
	{
		uint32_t iValue = inet_addr(value.c_str());

		if (iValue) {
			list.push_back(Single(iValue));

			return true;
		}

		return false;
	}
}

#ifndef SINGLE_H
#define SINGLE_H

#include <stdint.h>
#include <string>
#include <vector>

namespace Ip
{
	class Single
	{
	public:
		Single(uint32_t address);
		~Single();

		uint32_t getAddress();
		static bool buildFromString(std::string value, Single& ip);
		static bool buildFromString(std::string value, std::vector<Single>& list);
	private:
		uint32_t address;
	};
}
#endif


#ifndef CIDR_H
#define CIDR_H

#include <vector>
#include <string>

#include "Single.h"

namespace Ip 
{
	class Cidr
	{
	public:
		Cidr();
		Cidr(Single);
		Cidr(uint32_t, uint8_t);
		~Cidr();

		static uint32_t netmasks[33];

		uint32_t size();
		uint32_t getAddress();
		uint8_t getMask();

		static bool buildFromString(std::string, std::vector<Cidr>&);
		static bool build(uint32_t, uint32_t, std::vector<Cidr>&);
		static std::vector<Cidr> optimize(std::vector<Cidr>&);
		
		bool operator<(Cidr const rhs) const {
			if (start != rhs.start) {
				return start < rhs.start;
			}

			return mask < rhs.mask;
		}

	private:
		uint32_t start;
		uint8_t mask;

		bool sorter(Cidr& lv, Cidr& rv);
	};
}
#endif


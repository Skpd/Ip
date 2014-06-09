#include "Cidr.h"

#include <algorithm>

namespace Ip
{
	Cidr::Cidr()
	{
	}

	Cidr::Cidr(Single address)
	{
		this->start = address.getAddress();
		this->mask = 32;
	}

	Cidr::Cidr(uint32_t start, uint8_t mask)
	{
		this->start = start;
		this->mask = mask;
	}

	Cidr::~Cidr()
	{
	}

	uint32_t Cidr::size()
	{
		return (1 << (32 - mask));
	}

	uint32_t Cidr::getAddress()
	{
		return start;
	}

	uint8_t Cidr::getMask()
	{
		return mask;
	}

	bool Cidr::buildFromString(std::string value, std::vector<Cidr>& list)
	{
		return false;
	}

	bool Cidr::build(uint32_t start, uint32_t end, std::vector<Cidr>& list)
	{
		while (end >= start) {
			uint8_t mask = 0;

			while (mask < 32 && (0xFFFFFFFF >> mask | start) > end){
				mask++;
			}

			list.push_back(Cidr(start, mask));

			start += 1 << (32 - mask);
		}

		return false;
	}

	bool Cidr::sorter(Cidr& lv, Cidr& rv)
	{
		if (lv.getAddress() != rv.getAddress()) {
			return lv.getAddress() < rv.getAddress();
		}

		return lv.getMask() < rv.getMask();
	}

	std::vector<Cidr> Cidr::optimize(std::vector<Cidr>& list)
	{
		std::vector<Cidr> source(list);
		std::vector<Cidr> result;

		std::sort(source.begin(), source.end());

		while (!source.empty()) {
			Cidr first = source[0];
			source.erase(source.begin());

			uint32_t max = first.getAddress() + first.size();

			while (!source.empty() && source[0].getAddress() <= max) {
				Cidr second = source[0];
				source.erase(source.begin());

				max = std::max(max, second.getAddress() + second.size());
			}

			std::vector<Cidr> newList;
			Cidr::build(first.getAddress(), max - 1, newList);

			result.insert(result.begin(), newList.begin(), newList.end());
		}

		return result;
	}
}

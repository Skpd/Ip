#ifndef RANGE_H
#define RANGE_H

#include "Single.h"

namespace Ip
{
	class Range
	{
	public:
		Range(Single start, Single end);
		virtual ~Range();
	private:
		uint32_t start;
		uint32_t end;
	};
}
#endif



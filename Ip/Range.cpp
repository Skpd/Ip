#include "Range.h"

namespace Ip
{
	Range::Range(Single start, Single end)
	{
		this->start = start.getAddress();
		this->end = end.getAddress();
	}

	Range::~Range()
	{
	}
}

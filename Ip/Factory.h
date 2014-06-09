#ifndef FACTORY_H
#define FACTORY_H

#include <string>

#include "Single.h"

namespace Ip
{
	class Factory 
	{
	public:
		template< typename Type >
		static Type create(std::string value)
		{
			return Type::buildFromString(value);
		}
	};
}

#endif


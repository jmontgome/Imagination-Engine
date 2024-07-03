#include "pch.h"
#include "Logger.h"

#include <iostream>

namespace Imagination
{
	namespace Logging
	{
		void Log(const char* message)
		{
			std::cout << message << std::endl;
		}
	}
}
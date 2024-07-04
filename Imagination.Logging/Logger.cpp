#include "pch.h"
#include "Logger.h"

#include <iostream>

namespace Logging
{
	void Log(const char* message)
	{
#if DEBUG
		std::cout << message << std::endl;
#endif
	}
}
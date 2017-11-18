#include "Logger.hpp"

#include "globals.h"

void Logger::error(const __FlashStringHelper * str)
{
#if ERROR == 1
	Serial.print(frameCounter);
	Serial.print(F(" [ERROR] "));
	Serial.println(str);
#endif
}

void Logger::warn(const __FlashStringHelper * str)
{
#if WARN == 1
	Serial.print(frameCounter);
	Serial.print(F(" [WARN] "));
	Serial.println(str);
#endif
}

void Logger::info(const __FlashStringHelper * str)
{
#if INFO == 1
	Serial.print(frameCounter);
	Serial.print(F(" [INFO] "));
	Serial.println(str);
#endif
}

void Logger::debug(const __FlashStringHelper * str)
{
#if DEBUG == 1
	Serial.print(frameCounter);
	Serial.print(F(" [DEBUG] "));
	Serial.println(str);
#endif
}

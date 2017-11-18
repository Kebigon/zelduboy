#ifndef HOPPER_HPP
#define HOPPER_HPP

#define ERROR 1
#define WARN 1
#define INFO 1
#define DEBUG 1

#include "Arduboy2.h"

class Logger
{

public:
	static void error(const __FlashStringHelper * str);
	static void warn(const __FlashStringHelper * str);
	static void info(const __FlashStringHelper * str);
	static void debug(const __FlashStringHelper * str);
};

#endif

#include "common.h"

kram::JsonException::JsonException(const char* msg) :
	exception{ msg }
{}
kram::JsonException::JsonException(const std::string& msg) :
	exception{ msg.c_str() }
{}

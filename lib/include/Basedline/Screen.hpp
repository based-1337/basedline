#pragma once

#include <string_view>

#include "Basedline/ScreenBuf.hpp"
#include "Basedline/TTYConf.hpp"

namespace Basedline {

class Screen {
	TTYConf ttyConf;
	ScreenBuf screenBuf;

public:
	void clear ();
	void write (std::string_view str);
	void flush ();
};

}

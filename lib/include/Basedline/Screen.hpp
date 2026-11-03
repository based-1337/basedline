#pragma once

#include <string_view>

#include "Basedline/Cursor.hpp"
#include "Basedline/ScreenBuf.hpp"
#include "Basedline/TTYConf.hpp"

namespace Basedline {

class Screen {
	TTYConf ttyConf;
	ScreenBuf screenBuf;
	Cursor cursor;

public:
	void clear ();
	void write (std::string_view str);
	void flush ();
};

}

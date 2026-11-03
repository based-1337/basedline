#pragma once

#include <string_view>

#include "Basedline/Cursor.hpp"
#include "Basedline/Input.hpp"
#include "Basedline/ScreenBuf.hpp"
#include "Basedline/TTYConf.hpp"

namespace Basedline {

class Screen {
	TTYConf ttyConf;
	ScreenBuf screenBuf;
	Cursor cursor;

	void clear ();
public:
	Input in;

	void write (std::string_view str);
	void flush ();

	Screen ();

	BASED_CLASS_NO_COPY_MOVE (Screen);
};

}

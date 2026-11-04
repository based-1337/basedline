#pragma once

#include <string_view>

#include "Basedlib/Class.hpp"

#include "Basedline/Input.hpp"
#include "Basedline/InputDisplay.hpp"
#include "Basedline/Screen.hpp"

namespace Basedline {

class Basedline {
	Input in;
	Screen scr;
	InputDisplay inputDisplay;

public:
	void read ();

	void write (std::string_view str);
	void flush ();

	Basedline ();

	BASED_CLASS_NO_COPY_MOVE (Basedline);
};

}

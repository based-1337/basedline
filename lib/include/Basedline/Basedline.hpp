#pragma once

#include <string_view>

#include "Basedline/Input.hpp"
#include "Basedline/Screen.hpp"

namespace Basedline {

class Basedline {
	Input in;
	Screen scr;

public:
	void read ();

	void write (std::string_view str);
	void flush ();
};

}

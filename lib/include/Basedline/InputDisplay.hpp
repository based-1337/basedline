#pragma once

#include "Basedline/Cursor.hpp"
#include "Basedline/Defs.hpp"

namespace Basedline {

class Input;
class Screen;

class InputDisplay {
	const Input& in;
	Screen& scr;
	Cursor cursor;

	tsize_t rows = 1;
	tpos_t cursorPos = {0};
	bool visible = false;

public:
	void hide ();
	void show ();
	void dump ();

	InputDisplay (const Input& in, Screen& scr) : in (in), scr (scr) { }
};

}

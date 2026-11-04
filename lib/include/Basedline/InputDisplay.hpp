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

	tsize_t rows;
	tpos_t cursorPos;
	bool visible;

public:
	void hide ();
	void show ();
	void dump ();

	InputDisplay (const Input& in, Screen& scr) : in (in), scr (scr) { }
};

}

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
	tsize_t editorPos = 0;
	bool visible = false;

	void update_cursor ();
	void restore_cursor ();

public:
	void hide ();
	void show ();

	void draw ();

	InputDisplay (const Input& in, Screen& scr) : in (in), scr (scr) { }
};

}

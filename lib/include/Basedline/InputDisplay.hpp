#pragma once

#include "Basedline/Cursor.hpp"
#include "Basedline/Defs.hpp"
#include "Basedline/ScreenBuf.hpp"

namespace Basedline {

class Input;

class InputDisplay {
	const Input& in;
	ScreenBuf buf;
	Cursor cursor;

	tsize_t rows = 1;
	tpos_t cursorPos = {0};
	tsize_t editorPos = 0;

	void save_cursor ();
	void restore_cursor ();

public:
	void hide ();
	void show ();

	InputDisplay (const Input& in) : in (in) { }
};

}

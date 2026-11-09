#pragma once

#include "Basedlib/Class.hpp"

#include "Basedline/Console.hpp"
#include "Basedline/Defs.hpp"
#include "Basedline/ScreenBuf.hpp"

namespace Basedline {

class Input;

class InputDisplay {
	Console& con;
	const Input& in;
	ScreenBuf buf;

	tsize_t rows = 1;
	tpos_t cursorPos = {0};
	tsize_t editorPos = 0;

	void save_cursor ();
	void restore_cursor ();

public:
	void hide ();
	void show ();

	InputDisplay (Console& con, const Input& in);

	BASED_CLASS_NO_COPY_MOVE (InputDisplay);
};

}

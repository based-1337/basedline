#include "Basedline/InputDisplay.hpp"

#include "Basedline/Input.hpp"
#include "Basedline/Screen.hpp"

#include "VtCommand.hpp"

namespace Basedline {

void InputDisplay::save_cursor () {
	editorPos = in.editor().pos();
	cursorPos.x = editorPos;
	cursorPos.y = 1;
}

void InputDisplay::restore_cursor () {
	cursor.move_up (rows - cursorPos.y - 1);
	cursor.move_to_col (cursorPos.x);
}

void InputDisplay::hide () {
	save_cursor();

	cursor.hide();
	cursor.move_line_begin();
	cursor.move_up (cursorPos.y);
	VtCommand::clear_from_cursor();
}

void InputDisplay::show () {
	buf.push (in.editor().buf());
	buf.flush();

	restore_cursor();
	cursor.show();
}

}

#include "Basedline/InputDisplay.hpp"

#include "Basedline/Input.hpp"
#include "Basedline/Screen.hpp"

#include "VtCommand.hpp"

namespace Basedline {

void InputDisplay::update_cursor () {
	tsize_t editorPosSave = editorPos;
	editorPos = in.editor().pos();

	cursorPos.x = editorPos;
}

void InputDisplay::restore_cursor () {
	cursor.move_up (rows - cursorPos.y - 1);
	cursor.move_to_col (cursorPos.x);
}

void InputDisplay::hide () {
	cursor.hide();
	cursor.move_line_begin();
	cursor.move_up (cursorPos.y);
	VtCommand::clear_from_cursor();
	visible = false;
}

void InputDisplay::show () {
	update_cursor();
	draw();
	restore_cursor();
	cursor.show();
	visible = true;
}

void InputDisplay::draw () {
	scr.write (in.editor().buf());
	scr.flush();
}

}

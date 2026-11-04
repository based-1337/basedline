#include "Basedline/InputDisplay.hpp"

#include "Basedline/Input.hpp"
#include "Basedline/Screen.hpp"

#include "VtCommand.hpp"

namespace Basedline {

void InputDisplay::hide () {
	cursor.hide();
	cursor.move_line_begin();
	cursor.move_up (cursorPos.y);
	VtCommand::clear_from_cursor();
	visible = false;
}

void InputDisplay::show () {
	tsize_t editorPosSave = editorPos;
	editorPos = in.editor().pos();

	cursorPos.x = editorPos;

	scr.write (in.editor().buf());
	scr.flush();

	cursor.move_to_col (cursorPos.x);
	cursor.show();
	visible = true;
}

}

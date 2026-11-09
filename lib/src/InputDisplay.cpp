#include "Basedline/InputDisplay.hpp"

#include "Basedline/Input.hpp"
#include "Basedline/Console.hpp"

#include "VtCommand.hpp"

namespace Basedline {

void InputDisplay::save_cursor () {
	editorPos = in.editor().pos();
	cursorPos.x = editorPos;
	cursorPos.y = 0;
}

void InputDisplay::restore_cursor () {
	con.write (VtCommand::cursor_up (rows - cursorPos.y - 1));
	con.write (VtCommand::cursor_to_col (cursorPos.x));
}

void InputDisplay::hide () {
	save_cursor();

	con.write (VtCommand::cursor_hide());
	con.write (VtCommand::cr());
	con.write (VtCommand::cursor_up (cursorPos.y));
	con.write (VtCommand::clear_from_cursor());
}

void InputDisplay::show () {
	con.write (in.editor().buf());
	restore_cursor();
	con.write (VtCommand::cursor_show());
}

InputDisplay::InputDisplay (Console& con, const Input& in) : con (con), in (in) { }

}

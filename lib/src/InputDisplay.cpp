#include "Basedline/InputDisplay.hpp"

#include <print>

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
	std::print ("{}", VtCommand::cursor_up (rows - cursorPos.y - 1));
	std::print ("{}", VtCommand::cursor_to_col (cursorPos.x));
}

void InputDisplay::hide () {
	save_cursor();

	std::print ("{}", VtCommand::cursor_hide());
	std::print ("{}", VtCommand::cr());
	std::print ("{}", VtCommand::cursor_up (cursorPos.y));
	std::print ("{}", VtCommand::clear_from_cursor());
}

void InputDisplay::show () {
	buf.push (in.editor().buf());
	buf.flush();

	restore_cursor();
	std::print ("{}", VtCommand::cursor_show());
}

InputDisplay::InputDisplay (Console& con, const Input& in) : con (con), in (in) { }

}

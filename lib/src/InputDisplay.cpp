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
	cursor.show();
	visible = true;
}

void InputDisplay::dump () {
	scr.write (in.get());
}

}

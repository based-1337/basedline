#include "Basedline/Cursor.hpp"

#include "VtCommand.hpp"

namespace Basedline {

void Cursor::hide () {
	VtCommand::cursor_hide();
	_visible = false;
}

void Cursor::show () {
	VtCommand::cursor_show();
	_visible = true;
}

void Cursor::move_up (tsize_t dy) {
	if (dy > 0) VtCommand::cursor_up (dy);
}

void Cursor::move_line_begin () {
	VtCommand::cr();
}

}

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

void Cursor::move_down (tsize_t dy) {
	if (dy > 0) VtCommand::cursor_down (dy);
}

void Cursor::move_line_begin () {
	VtCommand::cr();
}

void Cursor::move_to_col (tsize_t col) {
	VtCommand::cursor_to_col (col);
}

}

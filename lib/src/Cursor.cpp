#include "Basedline/Cursor.hpp"

#include "VtCommand.hpp"

namespace Basedline {

tpos_t Cursor::move_to (tpos_t newPos) {
	return {1, 1};
}

void Cursor::hide () {
	VtCommand::cursor_hide();
	_visible = false;
}

void Cursor::show () {
	VtCommand::cursor_show();
	_visible = true;
}

}

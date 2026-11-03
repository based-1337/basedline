#include "Basedline/Screen.hpp"

#include "VtCommand.hpp"

namespace Basedline {

void Screen::clear () {
	VtCommand::clear();
}

void Screen::write (std::string_view str) {
	screenBuf.push (str);
}

void Screen::flush () {
	cursor.set_visible (false);
	screenBuf.flush();
	cursor.set_visible (true);
}

}

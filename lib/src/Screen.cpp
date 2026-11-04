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
	screenBuf.flush();
}

}

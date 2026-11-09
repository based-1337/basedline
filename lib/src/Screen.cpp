#include "Basedline/Screen.hpp"

#ifdef __WIN32
#include "Basedline/Winwrap.hpp"
#else
// select
#endif

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

bool Screen::has_input () {
#ifdef __WIN32
	DWORD input_events = 0;
	if (!GetNumberOfConsoleInputEvents (ttyConf.inputConf.hIn, &input_events))
		return false;
	return (input_events > 0);
#else
	// select
#endif
}

}

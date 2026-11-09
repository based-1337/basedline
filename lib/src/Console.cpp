#include "Basedline/Console.hpp"

#ifdef __WIN32
#include "Basedline/Winwrap.hpp"
#else
// select
#endif

#include "VtCommand.hpp"

namespace Basedline {

void Console::clear () {
	VtCommand::clear();
}

void Console::write (std::string_view str) {
	screenBuf.push (str);
}

void Console::flush () {
	screenBuf.flush();
}

bool Console::has_input () {
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

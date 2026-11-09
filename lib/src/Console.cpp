#include "Basedline/Console.hpp"

#ifdef __WIN32
#include <io.h>
#include "Basedline/Winwrap.hpp"
#else
#include <unistd.h>
// select
#endif

#include "VtCommand.hpp"

namespace Basedline {

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

 std::span<uint8_t> Console::read (std::span<uint8_t> dst) {
	size_t read = ::read (STDIN_FILENO, dst.data(), dst.size());
	if (read <= 0) return {};
	return dst.first (read);
}

}

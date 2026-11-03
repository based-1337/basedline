#include "Basedline/TTYConf.hpp"

#include <print>

#ifndef __WIN32
#include <unistd.h>
#endif

namespace Basedline {

#ifdef __WIN32
InputConf::InputConf (HANDLE hIn) : hIn (hIn) {
	GetConsoleMode (hIn, &modeSave);
	DWORD mode = ENABLE_WINDOW_INPUT | ENABLE_VIRTUAL_TERMINAL_INPUT;
	if (!SetConsoleMode (hIn, mode)) {
		std::print (stderr, "SetConsoleMode for hIn failed\n");
		return;
	}
	ok = true;
}

InputConf::~InputConf () {
	SetConsoleMode (hIn, modeSave);
}

OutputConf::OutputConf (HANDLE hOut) : hOut (hOut) {
	GetConsoleMode (hOut, &modeSave);
	DWORD mode = ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode (hOut, mode)) {
		std::print (stderr, "SetConsoleMode for hOut failed\n");
		return;
	}

	cpSave = GetConsoleOutputCP();
	SetConsoleOutputCP (CP_UTF8);

	ok = true;
}

OutputConf::~OutputConf () {
	SetConsoleMode (hOut, modeSave);
	SetConsoleOutputCP (cpSave);
}
#else
InputConf::InputConf () {
	if (!isatty (STDIN_FILENO)) {
		std::print (stderr, "stdin is not a tty\n");
		return;
	}
	if (tcgetattr (STDIN_FILENO, &save) != 0) {
		std::perror ("tcgetattr");
		return;
	}

	saved = true;
	termios cfg = save;
	cfg.c_lflag &= ~(ICANON | ISIG | ECHO);
	cfg.c_iflag &= ~(IXON);
	cfg.c_cc[VMIN] = 1;
	cfg.c_cc[VTIME] = 0;

	if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &cfg) != 0) {
		std::perror ("tcsetattr");
		return;
	}
	ok = true;
}

InputConf::~InputConf () {
	if (!saved) return;
	if (tcsetattr (STDIN_FILENO, TCSANOW, &save) != 0)
		std::perror ("tcsetattr");
}
#endif

#ifdef __WIN32
TTYConf::TTYConf () : inputConf (GetStdHandle (STD_INPUT_HANDLE)), outputConf (GetStdHandle (STD_OUTPUT_HANDLE)) {}
#else
TTYConf::TTYConf () {}
#endif

}

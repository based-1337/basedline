#pragma once

#ifdef __WIN32
#include "Basedline/Winwrap.hpp"
#else
#include <termios.h>
#endif

#include "Basedlib/Class.hpp"

namespace Basedline {

#ifdef __WIN32
struct InputConf {
	HANDLE hIn;
	DWORD modeSave;

	bool ok = false;
	InputConf (HANDLE hIn);
	~InputConf ();

	BASED_CLASS_NO_COPY_MOVE (InputConf);
};

struct OutputConf {
	HANDLE hOut;
	DWORD modeSave;
	UINT cpSave;

	bool ok = false;
	OutputConf (HANDLE hOut);
	~OutputConf ();

	BASED_CLASS_NO_COPY_MOVE (OutputConf);
};
#else
struct InputConf {
	termios save;

	bool saved = false, ok = false;
	InputConf ();
	~InputConf ();

	BASED_CLASS_NO_COPY_MOVE (InputConf);
};

struct OutputConf {
	BASED_CLASS_NO_COPY_MOVE (OutputConf);
};
#endif

struct TTYConf {
	InputConf inputConf;
	OutputConf outputConf;

	TTYConf ();
};

}

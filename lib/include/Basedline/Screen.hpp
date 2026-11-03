#pragma once

#include <string_view>

#include "Basedline/Cursor.hpp"
#include "Basedline/Input.hpp"
#include "Basedline/ScreenBuf.hpp"

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

class Screen {
	InputConf inputConf;
	OutputConf screenConf;
	ScreenBuf screenBuf;
	Cursor cursor;

	void clear ();
public:
	Input in;

	void write (std::string_view str);
	void flush ();

	Screen ();

	BASED_CLASS_NO_COPY_MOVE (Screen);
};

}

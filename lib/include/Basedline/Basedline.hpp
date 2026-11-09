#pragma once

#include <string>

#include "Basedlib/Class.hpp"

#include "Basedline/Console.hpp"
#include "Basedline/Defs.hpp"
#include "Basedline/Input.hpp"
#include "Basedline/InputDisplay.hpp"
#include "Basedline/Output.hpp"

namespace Basedline {

class Basedline {
	Console con;
	Input in;
	InputDisplay inputDisplay;
	Output out;

public:
	bool read ();
	Inputs loop ();

	void print (std::string str);
	void flush ();

	Basedline ();

	BASED_CLASS_NO_COPY_MOVE (Basedline);
};

}

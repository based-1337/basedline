#pragma once

#include "Basedlib/Class.hpp"

#include "Basedline/Console.hpp"

namespace Basedline {

class Output {
	Console& con;

public:
	Output (Console& con);

	BASED_CLASS_NO_COPY_MOVE (Output);
};

}

#pragma once

#include "Basedlib/Class.hpp"
#include "Basedlib/Container/ThreadSafeQueue.hpp"

#include "Basedline/Console.hpp"

namespace Basedline {

class Output {
	Console& con;

	Basedlib::ThreadSafeQueue<std::string> printQueue;

public:
	Output (Console& con);

	void push (std::string str);
	void write ();

	BASED_CLASS_NO_COPY_MOVE (Output);
};

}

#include "Basedline/Output.hpp"

#define BL_MAX_PRINT_LIMIT 64

namespace Basedline {

void Output::push (std::string str) {
	printQueue.push (std::move (str));
}

void Output::write () {
	if (printQueue.empty()) return;

	size_t printed = 0;
	do {
		con.write (printQueue.pop().value());
		printed++;
	} while (!printQueue.empty() && printed < BL_MAX_PRINT_LIMIT);
}

Output::Output (Console& con) : con (con) { }

}

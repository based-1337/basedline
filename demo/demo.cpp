#include "Basedline/Basedline.hpp"

#include <string>

int main () {
	Basedline::Basedline bl;

	Basedline::Inputs allOuts;
	bool stop = false;
	while (!stop) {
		bl.read();
		Basedline::Inputs outs = bl.loop();
		for (const std::string& out : outs) {
			if (out == "quit" || out == "stop")
				stop = true;
			allOuts.push_back (out);
		}
	}

	bl.write ("All commands:\n");
	for (const std::string& out : allOuts) {
		bl.write (out + "\n");
	}

	bl.flush();

	return 0;
}

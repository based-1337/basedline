#include "Basedline/Basedline.hpp"

#include <string>

int main () {
	Basedline::Basedline bl;

	Basedline::Outputs allOuts;
	bool stop = false;
	while (!stop) {
		bl.read();
		while (!stop) {
			Basedline::Outputs outs = bl.loop();
			bl.flush();
			for (const std::string& out : outs) {
				if (out == "quit" || out == "stop")
					stop = true;
				allOuts.push_back (out);
			}
		}
	}

	bl.write ("All commands:\n");
	for (const std::string& out : allOuts) {
		bl.write (out + "\n");
	}

	bl.flush();

	return 0;
}

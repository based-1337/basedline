#include "Basedline/Basedline.hpp"

int main () {
	Basedline::Basedline bl;

	for (int i = 0; i < 10; i++) {
		bl.read();
		//bl.write ("a");
		bl.flush();
	}

	return 0;
}

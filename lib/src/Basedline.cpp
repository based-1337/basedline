#include "Basedline/Basedline.hpp"

namespace Basedline {

Outputs Basedline::read () {
	return in.read();
}

void Basedline::write (std::string_view str) {
	scr.write (str);
}

void Basedline::flush () {
	inputDisplay.hide();
	scr.flush();
	inputDisplay.show();
}

Basedline::Basedline () : inputDisplay (in, scr) { }

}

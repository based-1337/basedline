#include "Basedline/Basedline.hpp"

namespace Basedline {

void Basedline::read () {
	in.enabled = true;
}

Outputs Basedline::loop () {
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

Basedline::Basedline () : inputDisplay (in) { }

}

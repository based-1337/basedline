#include "Basedline/Basedline.hpp"

namespace Basedline {

bool Basedline::read () {
	if (in.enabled) return false;
	in.enabled = true;
	return true;
}

Outputs Basedline::loop () {
	flush();
	if (in.enabled)
		return in.read();
	return {};
}

void Basedline::write (std::string_view str) {
	con.write (str);
}

void Basedline::flush () {
	if (in.enabled)
		inputDisplay.hide();
	con.flush();
	if (in.enabled)
		inputDisplay.show();
}

Basedline::Basedline () : inputDisplay (in) { }

}

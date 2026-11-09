#include "Basedline/Basedline.hpp"

namespace Basedline {

bool Basedline::read () {
	if (in.enabled) return false;
	in.enabled = true;
	return true;
}

Inputs Basedline::loop () {
	flush();
	if (in.enabled)
		return in.read();
	return {};
}

void Basedline::print (std::string str) {
	out.push (std::move (str));
}

void Basedline::flush () {
	if (in.enabled)
		inputDisplay.hide();
	out.write();
	if (in.enabled)
		inputDisplay.show();
	con.flush();
}

Basedline::Basedline () : in (con), inputDisplay (con, in), out (con) { }

}

#include "Basedline/InputDisplay.hpp"

#include "Basedline/Input.hpp"
#include "Basedline/Screen.hpp"

namespace Basedline {

void InputDisplay::hide () {
	cursor.hide();
	visible = false;
}

void InputDisplay::show () {
	cursor.show();
	visible = true;
}

void InputDisplay::dump () {
	scr.write (in.get());
}

}

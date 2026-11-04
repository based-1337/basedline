#pragma once

#include "Defs.hpp"

namespace Basedline {

class Cursor {
	tpos_t _pos;
	bool _visible;
public:
	tpos_t pos () const noexcept { return _pos; }
	bool visible () const noexcept { return _visible; }

	void hide();
	void show();
	tpos_t move_to (tpos_t newPos);
};

}

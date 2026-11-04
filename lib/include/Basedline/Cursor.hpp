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

	void move_up (tsize_t dy);
	void move_line_begin ();
};

}

#pragma once

#include "Basedline/Defs.hpp"

namespace Basedline::VtCommand {

void clear ();
void clear_from_cursor ();
void clear_lines (tsize_t from, tsize_t count);

void cr ();

void cursor_up (tsize_t dy);
void cursor_to (tpos_t pos);
void cursor_hide ();
void cursor_show ();

}

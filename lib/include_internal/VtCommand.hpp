#pragma once

#include <string>

#include "Basedline/Defs.hpp"

namespace Basedline::VtCommand {

std::string clear ();
std::string clear_from_cursor ();
std::string clear_lines (tsize_t from, tsize_t count);

std::string cr ();

std::string cursor_up (tsize_t dy);
std::string cursor_down (tsize_t dy);
std::string cursor_to (tpos_t pos);
std::string cursor_to_col (tsize_t col);
std::string cursor_hide ();
std::string cursor_show ();

}

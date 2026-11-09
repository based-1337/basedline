#include "VtCommand.hpp"

#include <format>

#define CR "\r"

#define ESC "\x1b"
#define CSI ESC"["

#define VT_DECSC ESC"7"
#define VT_DECSR ESC"8"

#define VT_CHA CSI"{}G"
#define VT_CUH CSI"H"
#define VT_CUP CSI"{};{}H"
#define VT_CUU CSI"{}A"
#define VT_CUD CSI"{}B"
#define VT_DECTCEM_L CSI"?25l"
#define VT_DECTCEM_H CSI"?25h"
#define VT_DL  CSI"{}M"
#define VT_ED0 CSI"0J"
#define VT_ED2 CSI"2J"

namespace Basedline::VtCommand {

std::string clear () {
	return {VT_CUH VT_ED2};
}

std::string clear_from_cursor () {
	return {VT_ED0};
}

std::string clear_lines (tsize_t from, tsize_t count) {
	if (count <= 0) [[unlikely]] return {};
	if (from < 0) [[unlikely]] from = 0;
	return std::format (VT_DECSC VT_CUP VT_DL VT_DECSR, from + 1, 1, count);
}

std::string cr () {
	return {CR};
}

std::string cursor_up (tsize_t dy) {
	if (dy == 0) [[unlikely]] return {};
	return std::format (VT_CUU, dy);
}

std::string cursor_down (tsize_t dy) {
	if (dy == 0) [[unlikely]] return {};
	return std::format (VT_CUD, dy);
}

std::string cursor_to (tpos_t pos) {
	return std::format (VT_CUP, pos.y + 1, pos.x + 1);
}

std::string cursor_to_col (tsize_t col) {
	return std::format (VT_CHA, col + 1);
}

std::string cursor_hide () {
	return {VT_DECTCEM_L};
}

std::string cursor_show () {
	return {VT_DECTCEM_H};
}

}

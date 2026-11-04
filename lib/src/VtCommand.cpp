#include "VtCommand.hpp"

#include <cstdio>

#define CR "\r"

#define ESC "\x1b"
#define CSI ESC"["

#define VT_DECSC ESC"7"
#define VT_DECSR ESC"8"

#define VT_CHA CSI"%dG"
#define VT_CUH CSI"H"
#define VT_CUP CSI"%d;%dH"
#define VT_CUU CSI"%dA"
#define VT_CUD CSI"%dB"
#define VT_DECTCEM_L CSI"?25l"
#define VT_DECTCEM_H CSI"?25h"
#define VT_DL  CSI"%dM"
#define VT_ED0 CSI"0J"
#define VT_ED2 CSI"2J"

namespace Basedline::VtCommand {

void clear () {
	std::printf (VT_CUH VT_ED2);
}

void clear_from_cursor () {
	std::printf (VT_ED0);
}

void clear_lines (tsize_t from, tsize_t count) {
	if (count <= 0) [[unlikely]] return;
	if (from < 0) [[unlikely]] from = 0;
	std::printf (VT_DECSC VT_CUP VT_DL VT_DECSR, from + 1, 1, count);
}

void cr () {
	std::printf (CR);
}

void cursor_up (tsize_t dy) {
	std::printf (VT_CUU, dy);
}

void cursor_down (tsize_t dy) {
	std::printf (VT_CUD, dy);
}

void cursor_to (tpos_t pos) {
	std::printf (VT_CUP, pos.y + 1, pos.x + 1);
}

void cursor_to_col (tsize_t col) {
	std::printf (VT_CHA, col + 1);
}

void cursor_hide () {
	std::printf (VT_DECTCEM_L);
}

void cursor_show () {
	std::printf (VT_DECTCEM_H);
}

}

#pragma once

#if defined(BASEDLINE_DEBUG)

#include <format>
#include "Basedlib/Core/LogFile.hpp"

namespace Basedline {

inline Basedlib::LogFile& fdbg_inst() {
	static Basedlib::LogFile dbg ("bl_debug.txt");
	return dbg;
}

}

#define BL_DEBUG(...) Basedline::fdbg_inst().print (std::format (__VA_ARGS__).c_str())

#else

#define BL_DEBUG(...)

#endif

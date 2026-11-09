#pragma once

#include <cstdint>
#include <span>
#include <string_view>

#include "Basedline/ScreenBuf.hpp"
#include "Basedline/TTYConf.hpp"

namespace Basedline {

class Console {
	TTYConf ttyConf;
	ScreenBuf screenBuf;

public:
	void clear ();
	void write (std::string_view str);
	void flush ();

	bool has_input ();
	std::span<uint8_t> read (std::span<uint8_t> dst);
};

}

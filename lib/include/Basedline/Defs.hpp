#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace Basedline {

using tsize_t = uint16_t;

struct tpos_t {
	tsize_t x, y;
};

using OptString = std::optional <std::string>;
using Inputs = std::vector <std::string>;

}

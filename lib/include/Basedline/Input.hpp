#pragma once

#include <cstdint>
#include <span>
#include <vector>

#include "Basedlib/Class.hpp"
#include "BasedVT/Parser.hpp"
#include "BasedVT/InputEvent/Event.hpp"

#include "Basedline/Console.hpp"
#include "Basedline/Defs.hpp"
#include "Basedline/Editor.hpp"

namespace Basedline {

class Input {
	Console& con;

	enum class InputEventType {
		Edit,
		Autocomplete,
		History
	};
	struct InputEvent {
		InputEventType type;
		BasedVT::InputEvent::Event ev;
	};
	using InputEvents = std::vector<InputEvent>;

	Editor ed;
	BasedVT::Parser vtparser;

	InputEvents decode (std::span<uint8_t> buf);
	OptString dispatch (const InputEvent& ev);
	OptString dispatch_edit (const BasedVT::InputEvent::KeyInput& k);

public:
	bool enabled = false;

	Inputs read ();
	const Editor& editor () const noexcept { return ed; }

	Input (Console& con);

	BASED_CLASS_NO_COPY_MOVE (Input);
};

}

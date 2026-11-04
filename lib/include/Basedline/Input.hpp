#pragma once

#include <span>
#include <vector>

#include "BasedVT/Parser.hpp"
#include "BasedVT/InputEvent/Event.hpp"

#include "Basedline/Editor.hpp"

namespace Basedline {

class Input {
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
	void dispatch (const InputEvent& ev);
	void dispatch_edit (const BasedVT::InputEvent::KeyInput& k);

public:
	void read ();
	const Editor& editor () const noexcept { return ed; }
};

}

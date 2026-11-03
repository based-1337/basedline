#pragma once

#include <span>
#include <vector>
#include <utility>

#include "BasedVT/Parser.hpp"
#include "BasedVT/InputEvent/Event.hpp"

#include "Basedline/Editor.hpp"

namespace Basedline {

class ScreenBuf;

class Input {
	enum class InputEventType {
		Edit,
		Autocomplete,
		History
	};
	using InputEvent = std::pair<InputEventType, BasedVT::InputEvent::Event>;
	using InputEvents = std::vector<InputEvent>;

	Editor ed;
	BasedVT::Parser vtparser;

	InputEvents decode (std::span<uint8_t> buf);
	void dispatch (const InputEvent& ev);
	void dispatch_edit (const BasedVT::InputEvent::KeyInput& k);

public:
	void read ();
	void dump (ScreenBuf& screenBuf);
};

}

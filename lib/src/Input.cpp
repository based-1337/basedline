#include "Basedline/Input.hpp"

#include <print>
#include <variant>

#ifdef __WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include "Basedlib/Meta/Overloaded.hpp"

#include "Basedline/ScreenBuf.hpp"

#include "Debug.hpp"

namespace Basedline {

static bool needs_flush (std::span<uint8_t> buf, uint8_t currByte) noexcept {
	return (buf.size() == 1 && buf[0] == '\e') // single ESC
	    || (buf.size() == 2 && buf[0] == '\e' && currByte == '[')  // CSI entry
	    || (buf.size() == 2 && buf[0] == '\e' && currByte == 'O'); // SS3 entry
}

Input::InputEvents Input::decode (std::span<uint8_t> buf) {
	Input::InputEvents evs;
	for (uint8_t b : buf) {
		vtparser.feed (b);
		auto event = needs_flush (buf, b) ? vtparser.flush() : vtparser.get();
		if (event) {
			InputEventType eventType = std::visit (Basedlib::Overloaded {
				[&] (BasedVT::InputEvent::KeyInput k) {
					// check for Tab etc.
					return InputEventType::Edit;
				}
			}, *event);
			evs.emplace_back (eventType, std::move (*event));
		}
	}
	return evs;
}

OptString Input::dispatch (const InputEvent& ev) {
	switch (ev.type) {
		case InputEventType::Edit:
			return dispatch_edit (std::get<BasedVT::InputEvent::KeyInput> (ev.ev));
	}
	return std::nullopt;
}

OptString Input::dispatch_edit (const BasedVT::InputEvent::KeyInput& k) {
	using namespace BasedVT::InputEvent;
	switch (k.key) {
		[[likely]]
		case KeyInput::Key::CHAR: ed.accumulate (k.byte); break;
		case KeyInput::Key::ENTER: return ed.commit();
		case KeyInput::Key::LEFT:
			if (!k.ctrl) [[likely]]
				ed.move_prev_grapheme();
			else
				ed.move_prev_word();
			break;
		case KeyInput::Key::RIGHT:
			if (!k.ctrl) [[likely]]
				ed.move_next_grapheme();
			else
				ed.move_next_word();
			break;
		case KeyInput::Key::HOME: ed.move_begin(); break;
		case KeyInput::Key::END: ed.move_end(); break;
	}
	return std::nullopt;
}

Outputs Input::read () {
	Outputs outs;
	uint8_t buf[64];
	ssize_t n = ::read (STDIN_FILENO, buf, sizeof (buf));
	InputEvents evs = decode (std::span (buf, n));
	for (const InputEvent& ev : evs) {
		OptString out = dispatch (ev);
		if (out) outs.push_back (std::move (*out));
	}
	return outs;
}

}

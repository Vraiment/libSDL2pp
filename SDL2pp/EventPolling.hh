/*
  libSDL2pp - C++11 bindings/wrapper for SDL2
  Copyright (C) 2017 Vraiment <jemc44@gmail.com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL2PP_EVENTPOLLING_HH
#define SDL2PP_EVENTPOLLING_HH

#include <SDL2pp/Private/EventDispatching.hh>

namespace SDL2pp {
namespace Event {
	template <typename... EventHandlers>
	bool PollEvent(EventHandlers&&... eventHandlers) {
		SDL_Event event;
		if (!SDL_PollEvent(&event)) {
			return false;
		}
		
		// TODO: Private::DispatchEvent(event, eventHandlers...);
		Private::DispatchEvent(event, eventHandlers...);
		
		return true;
	}
		
	template <typename... EventHandlers>
	int PollAllEvents(EventHandlers&&... eventHandlers) {
		int result;
		
		for (result = 0; PollEvent(eventHandlers...); result++);
		
		return result;
	}
}
}

#endif

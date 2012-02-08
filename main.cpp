#include <iostream>
#include "video.h"
#include "led_panel.h"
#include "FileFactory.h"

using namespace sdlpong;

int
main(void) {

    video vid(800, 400);
	led_panel leds(30, 5,800);
    FileFactory *fFactory = FileFactory::getFactoryInstance();
    fFactory->registerObject("led_on.png");
    fFactory->registerObject("led_off.png");

	int end = 0;
	SDL_Event event;
	Uint32 ticks;

	leds.set_offset(10, 10);
	ticks = SDL_GetTicks();

    leds.set_mode("static");
	leds.set_text("spadaj beju");
	while (end == 0) {
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
			end = 1;

		if (event.type == SDL_KEYDOWN)
			if (event.key.keysym.sym == SDLK_ESCAPE)
				end = 1;
		

		if (SDL_GetTicks() > ticks + 150) {
			ticks = SDL_GetTicks();
			vid.clear();

			if (leds.get_done()) {
				leds.set_text("za");
                std::cout << "juz\n";
			}
			leds.all_off();
			leds.scroll();

            leds.draw(vid.getScreen());
			vid.refresh();
			
		}

	}
	
}

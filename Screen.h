#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace Pong {

class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer; // Pixel memory
public:
	const static int SCREEN_WIDTH = 800; // standard: 800
	const static int SCREEN_HEIGHT = 600; // standard: 600
	const static int MIDLINE_WIDTH = SCREEN_WIDTH/100;
	const static int BORDER_WIDTH = MIDLINE_WIDTH;
	double rRate;
	int timeStart;
	int timeStop;
public:
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint32 red, Uint32 green, Uint32 blue);
	void clear();
	void close();
};

} /* namespace Pong */

#endif /* SCREEN_H_ */


#include "../includes/GraphicalUI.hpp"
#include <iostream>

GraphicalUI::GraphicalUI	(void) : _ww(750), _wh(450)
{
	_col_lines.r = 179;
	_col_lines.g = 179;
	_col_lines.b = 179;
	_col_lines.a = 0;
	_col_text.r = 59;
	_col_text.g = 59;
	_col_text.b = 59;
	_col_text.a = 0;
	_font_size = 11;
	_font_h = 33;
	_start_draw_x = 0;
	_start_draw_y = 0;
	_g_x = 0;
	_g_y = 0;
	if (TTF_Init() == -1)
		throw WinInitProblem();
	_font1 = TTF_OpenFont("./frameworks/OpenSans-Regular.ttf", _font_size);
}

GraphicalUI::GraphicalUI	(GraphicalUI const & inst)
{
	*this = inst;
}

GraphicalUI::~GraphicalUI	(void) {}

GraphicalUI &
GraphicalUI::GraphicalUI::operator=(GraphicalUI
const & inst)
{
	(void)inst;
	return *this;
}

void			GraphicalUI::sdl_init()
{
	if ((SDL_Init(SDL_INIT_EVERYTHING) != 0) ||
	((_win_ptr = SDL_CreateWindow("ft_gkrellm", 300, 300,
	_ww, _wh, 0)) == NULL) ||
	((_render = SDL_CreateRenderer(_win_ptr,
	-1, 0)) == NULL) || (TTF_Init() == -1))
		throw WinInitProblem();
	main_loop();
}

void		GraphicalUI::UsrInfo()
{
	int mw = _ww;
	int mh = 105;
	SDL_SetRenderDrawColor(_render, _col_lines.r, _col_lines.g,
	_col_lines.b, 0);
	SDL_Rect rect = {_start_draw_x, 0, mw, mh};
	_start_draw_y = mh - 1;
	SDL_RenderDrawRect(_render, &rect);
	SDL_RenderDrawLine(_render, 10, 35, 740, 35);
	SDL_RenderDrawLine(_render, 10, 70, 740, 70);

	std::string m1 = "User:          name";
	SDL_Surface *mess1 = TTF_RenderText_Solid(_font1, m1.c_str(), _col_text);
	SDL_Texture *Mess1 = SDL_CreateTextureFromSurface(_render, mess1);
	SDL_Rect Mess1_rect = {15, 1, m1.length() * 7, _font_h};
	std::string m2 = "Date:          date+time";
	SDL_Surface *mess2 = TTF_RenderText_Solid(_font1, m2.c_str(), _col_text);
	SDL_Texture *Mess2 = SDL_CreateTextureFromSurface(_render, mess2);
	SDL_Rect Mess2_rect = {15, 36,  m2.length() * 7, _font_h};
	std::string m3 = "WTF is here ";
	SDL_Surface *mess3 = TTF_RenderText_Solid(_font1, m3.c_str(), _col_text);
	SDL_Texture *Mess3 = SDL_CreateTextureFromSurface(_render, mess3);
	SDL_Rect Mess3_rect = {15, 71,  m3.length() * 8, _font_h};

	SDL_RenderCopy(_render, Mess1, NULL, &Mess1_rect);
	SDL_RenderCopy(_render, Mess2, NULL, &Mess2_rect);
	SDL_RenderCopy(_render, Mess3, NULL, &Mess3_rect);
}

void		GraphicalUI::draw_graph(int x, int y)
{
	SDL_SetRenderDrawColor(_render, 177, 23, 69, 0);
	int tmp_mw1;
	int pr1 = rand() % 100;
	tmp_mw1 = 195 * pr1 / 100;
	SDL_Rect rect = {x, y, tmp_mw1, 50};
	SDL_RenderDrawRect(_render, &rect);
	SDL_RenderFillRect(_render, &rect);
}

void		GraphicalUI::CPULoad()
{
	int mw = _ww;
	int mh = 155;

	SDL_SetRenderDrawColor(_render, _col_lines.r, _col_lines.g,
	_col_lines.b, 0);
	SDL_Rect rect = {_start_draw_x, _start_draw_y, mw, mh};
	SDL_Rect rect1 = {_start_draw_x, _start_draw_y, mw / 3, mh};
	SDL_Rect rect2 = {mw / 3 - 1, _start_draw_y, mw / 3, mh};
	SDL_RenderDrawRect(_render, &rect);
	SDL_RenderDrawRect(_render, &rect1);
	SDL_RenderDrawRect(_render, &rect2);

	SDL_RenderDrawLine(_render, _start_draw_x + 10,
	_start_draw_y + mh / 3, mw / 3 - 1, _start_draw_y + mh / 3);
	SDL_RenderDrawLine(_render, mw * 0.667 - 1,
	_start_draw_y + mh / 3, mw - 10, _start_draw_y + mh / 3);
	SDL_RenderDrawLine(_render, _start_draw_x + 10,
	_start_draw_y + mh * 0.667, mw / 3 - 1, _start_draw_y + mh * 0.667);
	SDL_RenderDrawLine(_render, mw * 0.667 - 1,
	_start_draw_y + mh * 0.667, mw - 10, _start_draw_y + mh * 0.667);
	SDL_RenderDrawLine(_render, mw / 3 + 11,
	_start_draw_y + mh / 3, mw * 0.667 - 11, _start_draw_y + mh / 3);

	std::string m1 = "System: ";
	SDL_Surface *mess1 = TTF_RenderText_Solid(_font1, m1.c_str(), _col_text);
	SDL_Texture *Mess1 = SDL_CreateTextureFromSurface(_render, mess1);
	SDL_Rect Mess1_rect = {15, _start_draw_y - 15 + _font_h, m1.length() * 7, _font_h};
	std::string m2 = "User: ";
	SDL_Surface *mess2 = TTF_RenderText_Solid(_font1, m2.c_str(), _col_text);
	SDL_Texture *Mess2 = SDL_CreateTextureFromSurface(_render, mess2);
	SDL_Rect Mess2_rect = {15, _start_draw_y - 15 + mh / 3 + _font_h, m2.length() * 7, _font_h};
	std::string m3 = "Idle: ";
	SDL_Surface *mess3 = TTF_RenderText_Solid(_font1, m3.c_str(), _col_text);
	SDL_Texture *Mess3 = SDL_CreateTextureFromSurface(_render, mess3);
	SDL_Rect Mess3_rect = {15, _start_draw_y - 15 + mh * 0.667 + _font_h, m3.length() * 7, _font_h};
	SDL_RenderCopy(_render, Mess1, NULL, &Mess1_rect);
	SDL_RenderCopy(_render, Mess2, NULL, &Mess2_rect);
	SDL_RenderCopy(_render, Mess3, NULL, &Mess3_rect);

	std::string m4 = "Bla1 ";
	SDL_Surface *mess4 = TTF_RenderText_Solid(_font1, m4.c_str(), _col_text);
	SDL_Texture *Mess4 = SDL_CreateTextureFromSurface(_render, mess4);
	SDL_Rect Mess4_rect = {15 + mw * 0.667, _start_draw_y - 15 + _font_h, m4.length() * 7, _font_h};
	std::string m5 = "Bla2 ";
	SDL_Surface *mess5 = TTF_RenderText_Solid(_font1, m5.c_str(), _col_text);
	SDL_Texture *Mess5 = SDL_CreateTextureFromSurface(_render, mess5);
	SDL_Rect Mess5_rect = {15 + mw * 0.667, _start_draw_y - 15 + mh / 3 + _font_h, m5.length() * 7, _font_h};
	std::string m6 = "Bla 3 ";
	SDL_Surface *mess6 = TTF_RenderText_Solid(_font1, m6.c_str(), _col_text);
	SDL_Texture *Mess6 = SDL_CreateTextureFromSurface(_render, mess6);
	SDL_Rect Mess6_rect = {15 + mw * 0.667, _start_draw_y - 15 + mh * 0.667 +
	_font_h, m6.length() * 7, _font_h};

	std::string CPU = "CPU load";
	SDL_Surface *cpu_surf = TTF_RenderText_Solid(_font1, CPU.c_str(), _col_text);
	SDL_Texture *cpu_tex = SDL_CreateTextureFromSurface(_render, cpu_surf);
	SDL_Rect cpu_rect = {105 + mw / 3, _start_draw_y - 15 +
	_font_h, m6.length() * 7, _font_h};

	SDL_RenderCopy(_render, Mess4, NULL, &Mess4_rect);
	SDL_RenderCopy(_render, Mess5, NULL, &Mess5_rect);
	SDL_RenderCopy(_render, Mess6, NULL, &Mess6_rect);
	SDL_RenderCopy(_render, cpu_tex, NULL, &cpu_rect);

	if (!_g_x && !_g_y)
	{
		_g_x = mw / 3;
		_g_y = _start_draw_y + mh / 2 + 7;
	}
}

void		GraphicalUI::render()
{
	SDL_SetRenderDrawColor(_render, 255, 255, 255, 0);
	SDL_Rect rect = {0, 0, _ww, _wh};
	SDL_RenderDrawRect(_render, &rect);
	SDL_RenderFillRect(_render, &rect);
	SDL_RenderClear(_render);
	UsrInfo();
	CPULoad();
}

void		GraphicalUI::main_loop()
{
	_sdl_done = SDL_FALSE;
	while (!_sdl_done)
	{
		render();
		if (_g_mw || _g_mh)
			draw_graph(_g_x, _g_y);
		while (SDL_PollEvent(&_event) && !_sdl_done)
		{
			if (_event.type == SDL_QUIT || (
			_event.key.keysym.scancode == SDL_SCANCODE_ESCAPE &&
			_event.type == SDL_KEYDOWN))
				_sdl_done = SDL_TRUE;
		}
		SDL_RenderPresent(_render);
		SDL_Delay(350);
	}
	SDL_RenderClear(_render);
	SDL_DestroyWindow(_win_ptr);
	SDL_Quit();
}

// exception
GraphicalUI::WinInitProblem::WinInitProblem (void)
{
	return ;
}

GraphicalUI::WinInitProblem::WinInitProblem(WinInitProblem
const & inst)
{
	*this = inst;
}

GraphicalUI::WinInitProblem::~WinInitProblem() throw()
{
	return ;
}

const char * GraphicalUI::WinInitProblem::what() const throw()
{
	return ("Some problem with SDL initialization occured!");
}

GraphicalUI::WinInitProblem &	
GraphicalUI::WinInitProblem::operator=(WinInitProblem
const & inst)
{
	(void)inst;
	return *this;
}

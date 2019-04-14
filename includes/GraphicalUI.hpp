
#ifndef GRAPHICALUI_HPP
# define GRAPHICALUI_HPP

#include <iostream>
# include "./../frameworks/SDL2.framework/Headers/SDL.h"
# include "./../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"

class GraphicalUI
{
public:

	GraphicalUI			(void);
	GraphicalUI			(GraphicalUI const & inst);
	~GraphicalUI		(void);

	GraphicalUI &		operator=(GraphicalUI const & inst);

	class WinInitProblem : public std::exception
	{
	public:
		WinInitProblem (void);
		WinInitProblem (WinInitProblem const & inst);
		virtual	~WinInitProblem() throw();
		WinInitProblem & operator=(WinInitProblem
		const & inst);
		virtual const char * what() const throw();
	};
	void				sdl_init();
	void				render();
	void				main_loop();
	void				draw_graph(int x, int y);

	// render modules
	void				UsrInfo();
	void				CPULoad();
private:

	int					_ww;
	int					_wh;
	int					_start_draw_x;
	int					_start_draw_y;
	
	SDL_Window			*_win_ptr;
	SDL_bool			_sdl_done;
	SDL_Renderer		*_render;
	SDL_Event			_event;

	SDL_Color			_col_lines;
	SDL_Color			_col_text;
	int					_font_size;
	int					_font_h;
	TTF_Font			*_font1;

	int					_g_x;
	int					_g_y;
	int					_g_mw;
	int					_g_mh;
};

#endif

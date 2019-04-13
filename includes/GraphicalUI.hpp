
#ifndef GRAPHICALUI_HPP
# define GRAPHICALUI_HPP

#include <iostream>
#include "../build/include/SDL2/SDL.h"

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
private:

	SDL_Window			*_win_ptr;
	SDL_bool			_done;
	SDL_Renderer		*_render;
	// SDL_Event			_event;
};

#endif


#ifndef GRAPHICALUI_HPP
# define GRAPHICALUI_HPP

#include <iostream>
# include "./../frameworks/SDL2.framework/Headers/SDL.h"
# include "./../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "IDisplayMonitor.hpp"
#include <vector>
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "TopInfo.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OsInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "IMonitorModule.hpp"

class GraphicalUI :  public virtual IDisplayMonitor
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

	void	displayGKrellm(std::vector<std::string> &flags);
	void	addModules(std::vector<std::string> &flags, TopInfo const &top, std::vector<IMonitorModule *> &modules);
	void	updateModules(std::vector<IMonitorModule *> & modules, TopInfo & top);
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
	std::vector<IMonitorModule *> modules;
	TopInfo 	 top;
};

#endif

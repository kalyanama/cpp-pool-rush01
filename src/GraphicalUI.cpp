
#include "../includes/GraphicalUI.hpp"
#include <iostream>

GraphicalUI::GraphicalUI	(void) {}

GraphicalUI::GraphicalUI	(GraphicalUI const & inst)
{
	*this = inst;
}

GraphicalUI::~GraphicalUI	(void) {}

GraphicalUI::GraphicalUI &	
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
	216, 256, 0)) == NULL) ||
	((_render = SDL_CreateRenderer(_win_ptr,
	-1, 0)) == NULL))
		throw WinInitProblem();
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

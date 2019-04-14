
#include <iostream>
#include "../includes/GraphicalUI.hpp"

int     main(void)
{
    GraphicalUI render;

    srand(time(NULL));
    try
    {
        render.sdl_init();
    }
    catch(GraphicalUI::WinInitProblem & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

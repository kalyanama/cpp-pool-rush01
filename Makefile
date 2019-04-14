# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 19:48:51 by akulaiev          #+#    #+#              #
#    Updated: 2019/04/01 19:48:53 by akulaiev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp\
		GraphicalUI.cpp \
		CpuModule.cpp \
        DateTimeModule.cpp \
        GraphicalUI.cpp \
        HostnameModule.cpp \
        NcursesDisplayMode.cpp \
        NetworkModule.cpp \
        OsInfoModule.cpp \
        RamModule.cpp \
        UsernameModule.cpp \
        TopInfo.cpp \


SRC_DIR = ./src/
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.cpp=.o))
NAME = rush
CFLAG = #-Wall -Wextra -Werror
CC = clang++
INC =	-I./includes/GraphicalUI.hpp\
		-I./frameworks/SDL2.framework/Versions/A/Headers\
		-I./frameworks/SDL2_ttf.framework/Versions/A/Headers\
		-I./frameworks/SDL2_image.framework/Versions/A/Headers \
		-I./includes/CpuModule.hpp \
        -I./includes/DateTimeModule.hpp \
        -I./includes/HostnameModule.hpp \
        -I./includes/IDisplayMonitor.hpp \
        -I./includes/IMonitorModule.hpp \
        -I./includes/NcursesDisplayMode.hpp \
        -I./includes/NetworkModule.hpp \
        -I./includes/OsInfoModule.hpp \
        -I./includes/RamModule.hpp \
        -I./includes/TopInfo.hpp \
        -I./includes/UsernameModule.hpp \
        -I./includes/


FRAMEWORKS = -F./frameworks \
			-rpath ./frameworks \
			-framework SDL2 -framework SDL2_ttf -framework SDL2_image

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME) $(FRAMEWORKS) $(INC)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CC) $(CFLAG)  $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

exe:
	./$(NAME)

re: fclean all

commit:
	make fclean
	git add -A
	git commit -m "$(MSG)"
	git push

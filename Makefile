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
		GraphicalUI.cpp
SRC_DIR = ./src/
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.cpp=.o))
NAME = rush
CFLAG = -Wall -Wextra -Werror
CC = clang++
INC =	../includes/GraphicalUI.hpp

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	sh ./install.sh
	$(CC) $(CFLAG) -lncurses  -L ./build/lib -lSDL2 -lm -liconv -L lib -l SDL2-2.0.0 $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(INC)
	$(CC) $(CFLAG) -I/includes -I./build/include/SDL2/ -c $< -o $@

dellib:
	rm -rf ./build

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -Rf ./Downloads

exe:
	./$(NAME)

re: fclean all

commit:
	make fclean
	git add -A
	git commit -m "$(MSG)"
	git push

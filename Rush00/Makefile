NAME        = ft_retro

CPP         = g++
FLAGS    =	-g #-g a enlever avant rendre -std=c++98 -Wall -Werror -Wextra
LNC         = -lncurses
SRC_DIR     = ./srcs/
INC_DIR     = ./includes/
OBJ_DIR     = ./obj/


SRCS_FILES = main.cpp Context.cpp AGameObject.cpp Player.cpp Game.cpp Coordinates.cpp

HPP_FILES = Context.hpp AGameObject.hpp Player.hpp Game.hpp Coordinates.hpp

OBJS_FILES = $(SRCS_FILES:.cpp=.o)

SRCS       = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS       = $(addprefix $(OBJ_DIR), $(OBJS_FILES))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@$(CPP) $(FLAGS) -I $(INC_DIR) -o $@ -c $< 

$(NAME): $(OBJS)
	@$(CPP) $(OBJS) -o $@ $(LNC)
	@echo "$(NAME) compiled"
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed"
re:	fclean all
.PHONY: all clean fclean format re
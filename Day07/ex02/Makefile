NAME        = array

CPP         = clang++
FLAGS    =	 -std=c++98 -Wall -Werror -Wextra

SRC_DIR     = ./
INC_DIR     = ./
OBJ_DIR     = ./obj/


SRCS_FILES = main.cpp

HPP_FILES = Array.tpp

OBJS_FILES = $(SRCS_FILES:.cpp=.o)

SRCS       = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS       = $(addprefix $(OBJ_DIR), $(OBJS_FILES))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@$(CPP) $(FLAGS) -I $(INC_DIR) -o $@ -c $< 

$(NAME): $(OBJS)
	@$(CPP) $(OBJS) -o $@
	@echo "$(NAME) compiled"
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed"
re:	fclean all
.PHONY: all clean fclean format re

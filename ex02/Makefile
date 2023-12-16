# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 02:57:35 by hael-mou          #+#    #+#              #
#    Updated: 2023/12/16 10:57:58 by hael-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= PmergeMe

#=== Directories : ============================================================
SRC_DIR		:= .
OBJ_DIR		:= .build

#=== SRC Files : ==============================================================
SRC_FILES	:= $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
SRC_FILES	:= $(notdir $(SRC_FILES))
OBJ_FILES	:= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

#=== INC files : ==============================================================
INC_FILES	:= $(wildcard $(SRC_DIR)/*/*.hpp) $(wildcard $(SRC_DIR)/*.hpp)
INC_DIR		:= $(sort $(dir $(INC_FILES)))

#=== Commands : ===============================================================
CPP			:= c++
RM			:= rm -rf
CFLAGS		:= -std=c++98 -g -fsanitize=address #-Wall -Wextra -Werror 
INCLUDE		:= $(addprefix -I, $(INC_DIR))

#=== Colors : =================================================================
DEF			:= \033[3;39m
GRAY		:= \033[3;90m
PINK		:= \033[3;38;5;199m
RED			:= \033[3;91m
GREEN		:= \033[3;32m
CYAN		:= \033[3;96m
PURPLE		:= \033[3;35m
YELLOW		:= \033[3;93m

#=== Pattern rules : ==========================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_FILES)
	@$(CPP) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]    $(PURPLE)Compiling --> $(DEF)$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.cpp $(INC_FILES)
	@$(CPP) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]    $(PURPLE)Compiling --> $(DEF)$<"

#=== Rules : ==================================================================
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	@$(CPP) $(CFLAGS) $(INCLUDE) $(OBJ_FILES) -o $@
	@echo "$(GREEN) [OK]    $(YELLOW)$@ is created !! $(DEF)"

run: all
	@clear
	@./$(NAME) 8 15 17 18 3 0 12 13 14 10 4 16 6 5 11 2 1 20 7 9 19
#@./$(NAME) `jot -r 21 1 21 | tr '\n' ' '`

clean:
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(GREEN) [OK]    $(RED) Object Files are Cleaned!$(DEF)";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GREEN) [OK]    $(RED) $(NAME) Cleaned!$(DEF)";\
	fi

re:	fclean all

#=== Create dir : =============================================================
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: all run clean fclean re

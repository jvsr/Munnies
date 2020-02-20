# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/20 20:45:02 by jvisser        #+#    #+#                 #
#    Updated: 2020/02/20 23:52:52 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = Munnies
CPP_FILES = main.cpp \
			init.cpp \
			loop.cpp \
			main_menu.cpp
O_FILES = $(CPP_FILES:%.cpp=%.o)
HEADER = init.h \
		loop.h \
		main_menu.h
CFLAGS = -Wall -Wextra -Werror -Wpedantic
CC = g++
SILENCE = &> /dev/null
LIB_DEP= -lncurses

ANSI_BOLD_RED=\033[1;31m
ANSI_BOLD_GREEN=\033[1;32m
ANSI_BOLD_MAGENTA=\033[1;35m
EOC=\033[0m

all: $(NAME)

%.o: %.cpp $(HEADER)
	@echo "$(ANSI_BOLD_GREEN) 🛠️  Building $@ from $< file $(EOC)"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(O_FILES)
	@echo "$(ANSI_BOLD_GREEN) 🛠️  Building $(NAME) from objects $(EOC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) $(LIB_DEP)
	@echo "$(ANSI_BOLD_MAGENTA) 🏁  Done building $(NAME) $(EOC)"

clean:
ifeq (,$(wildcard $(O_FILES)))
	@echo "$(ANSI_BOLD_RED) 🗑️  No objects to clean $(EOC)"
else
	@echo "$(ANSI_BOLD_RED) 🗑️  Cleaning library objects $(EOC)"
	@/bin/rm -f $(O_FILES)
endif

fclean: clean
ifeq (,$(wildcard $(NAME)))
	@echo "$(ANSI_BOLD_RED) 🗑️  No executable to clean $(EOC)"
else
	@echo "$(ANSI_BOLD_RED) 🗑️  Cleaning $(NAME) file $(EOC)"
	@/bin/rm -f $(NAME)
endif

re: fclean
	@echo "$(ANSI_BOLD_MAGENTA) 🏁  Start rebuilding $(NAME) $(EOC)"
	@make all
	@echo "$(ANSI_BOLD_MAGENTA) 🏁  Done rebuilding $(NAME) $(EOC)"

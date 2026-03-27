##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

UTILS		=	src/utils/

LIB			=	src/lib/

SHELL_S		=	src/shell/

BUILTINS	=	src/builtins/

WSTATUS		=	src/wstatus/

CC			:=	epiclang

CFLAGS  	:= 	-Wall -Wextra

CPPFLAGS 	:= 	-iquote ./include/

SRC	=		$(UTILS)init_sh.c					\
			$(UTILS)fill_env.c					\
			$(UTILS)push_back.c					\
			$(UTILS)print_list.c				\
			$(UTILS)my_getenv.c					\
			$(UTILS)free_sh.c					\
			$(UTILS)free_array.c				\
			$(UTILS)free_narray.c				\
			$(UTILS)push_env.c					\
			$(UTILS)concat_paths.c				\
			$(UTILS)list_to_array.c				\
			$(UTILS)init_cd.c					\
			$(UTILS)free_tab.c					\
			$(LIB)my_str_to_word_array.c		\
			$(LIB)my_dprintf.c					\
			$(LIB)is_nbr.c						\
			$(LIB)my_strlen.c					\
			$(LIB)my_strndup.c					\
			$(LIB)my_strdup.c					\
			$(LIB)my_strcmp.c					\
			$(LIB)my_strchr.c					\
			$(LIB)my_strcat.c					\
			$(LIB)my_strcpy.c					\
			$(LIB)my_getnbr.c					\
			$(LIB)my_strncmp.c					\
			$(LIB)array_to_array.c				\
			$(SHELL_S)get_input.c				\
			$(SHELL_S)shell_loop.c				\
			$(SHELL_S)shell_iteration.c			\
			$(SHELL_S)cmd_check.c				\
			$(SHELL_S)exec_cmd.c				\
			$(BUILTINS)my_exit.c				\
			$(BUILTINS)my_env.c					\
			$(BUILTINS)my_setenv.c				\
			$(BUILTINS)my_unsetenv.c			\
			$(BUILTINS)my_cd.c					\
			$(WSTATUS)check_wstatus.c			\
			$(WSTATUS)sigpart_one.c				\
			$(WSTATUS)sigpart_two.c				\
			$(WSTATUS)sigpart_three.c			\
			$(WSTATUS)sigpart_four.c			\
			$(WSTATUS)sigpart_five.c			\
			src/mysh.c							\
			main.c

OBJ			=	$(SRC:.c=.o)

NAME		=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug:	CFLAGS += -g3
debug: 	re

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re debug

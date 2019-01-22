##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

PATHSRC	= src/

SRC	=	malloc.c \
		calloc.c	\
		realloc.c	\
		free.c	\
		print_alloc_memory.c	\
#		main.c

SRCS	=	$(addprefix $(PATHSRC), $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-g3 -Wall -Wextra -I ./inc

NAME		=	malloc

LIB_NAME	=	libmy_malloc.so

RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BG_COLOR	=	\033[46m

all:    $(LIB_NAME)

bin: $(NAME)

$(NAME):	$(OBJ)
	@printf '${BG_COLOR}Flags: $(LDFLAGS) $(CFLAGS)${NC}\n'
	@printf '${GREEN}Create${NC}: ${GREY}./$(NAME)${NC}\n'
	@gcc -o $(NAME) $(OBJ)

$(LIB_NAME): $(OBJ)
	@gcc -shared $(OBJ) -o $(LIB_NAME)

%.o:	%.c
	@printf '${GREEN} [ OK ]${NC} Building : $<\n'
	@gcc -o $@ -c -fPIC $< $(LDFLAGS) $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@printf '${RED}Clean${NC} : OK\n'

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_NAME)
	@printf '${RED}Fclean${NC}: ./$(NAME) removed\n'
	find . -name *.dSYM -type d -exec rm -rf "{}" \;

re: fclean all

.PHONY: re fclean clean all

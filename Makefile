# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 16:45:33 by rle-mino          #+#    #+#              #
#    Updated: 2016/03/08 15:16:33 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME

NAME	=	ft_ls

#SOURCE
SRC		=	debug.c			\
			ft_ls.c			\
			ls_error.c		\
			ls_tools.c		\
			ls_tools2.c		\
			ls_tools3.c		\
			ls_cmp.c		\
			ls_set.c		\
			ls_cmp2.c		\
			ls_get.c		\
			ls_parsing.c	\
			ls_display.c	\
			ls_sort.c		\
			ls_sort2.c		\
			ls_master.c		\
			ls_filter.c		\
			ls_free.c		\
			main.c			\

DOTO	=	$(SRC:.c=.o)


#COLOR
KCYN	=		"\033[0;36m"
KRESET	=		"\033[0m"
KRED	=		"\033[0;31m"
KWHI	=		"\033[1;37m"


#FLAGS
FLAGS	=	-Wall -Wextra -Werror

#RULES

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(DOTO) 
	@make -C libft/
	@printf "\033[1;37mCompiling\033[0m ft_ls"
	@gcc $(FLAGS) -lft -L ./libft -o $(NAME) $(DOTO) -I includes
	@printf "\t\t[\033[0;36mSUCCESS\033[0m]\n"

%.o: %.c
	@gcc -c $(FLAGS) -I includes $< -o $@

clean:
	@make -C libft/ fclean
	@rm -rf $(DOTO)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

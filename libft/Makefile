# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:03:49 by otahirov          #+#    #+#              #
#    Updated: 2018/12/13 13:10:07 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

CC=gcc
CFLAGS= -Wall -Wextra -Werror

BIN = $(SRC:.c=.o)

INC = -I includes/

LOC? = ~/Programs/42/ft_gnl/libft

all : $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) $(INC)
	@ar rc $(NAME) $(BIN)
	@ranlib $(NAME)
	@echo "Library Generated!"

clean :
	@rm -f $(BIN)
	@echo "Deleted Object files"

fclean : clean
	@rm -rf $(NAME)
	@echo "Deleted Library"

rm :
	@make -C $(LOC) fclean
	@rm -f $(LOC)/*.c
	@rm -f $(LOC)/Makefile
	@rm -f $(LOC)/includes/*
	@echo "Cleaned The $(LOC)"

copy : fclean rm
	@cp *.c $(LOC)
	@cp Makefile $(LOC)
	@cp includes/* $(LOC)/includes
	@echo "Distributed new Libft"

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 18:14:00 by otahirov          #+#    #+#              #
#    Updated: 2019/01/09 18:35:21 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

SRCDIR		= ./src
INCDIR		= ./includes
OBJDIR		= ./obj

SRC			= mainfract.c \
			  fract.c \
			  hook_keyboard.c \
			  hook_mouse.c \
			  fractal_matcher.c \
			  image.c \
			  colors.c \
			  palletes.c \
			  render.c \
			  view.c \
			  $(addprefix fractals/,$(shell ls $(SRCDIR)/fractals | grep -E ".+\.c"))

OBJ			= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O2

MLX			= ./minilibx
MLX_LINK	= -L $(MLX) -lmlx -framework OpenGL -framework AppKit
MLX_INC		= -I $(MLX)
MLX_LIB		= $(addprefix $(MLX),mlx.a)

FTDIR		= ./libft
FT			= $(addprefix $(FTDIR),/)
FT_LIB		= $(addprefix $(FT),libft.a)
FT_INC		= -I $(FTDIR)/includes
FT_LINK		= -L $(FTDIR) -lft -lpthread

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LINK) $(FT_LINK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all

git :
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"

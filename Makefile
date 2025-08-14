# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 13:51:49 by chomobon          #+#    #+#              #
#    Updated: 2025/08/14 19:12:12 by chomobon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c so_long_utils.c map_check.c hook_utils.c put_sprites.c\
		ft_err.c movements.c map_check_utils.c movements_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft/libft.a

MINI = minilibx-linux
MINI_LIB = minilibx-linux/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MINI)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -L$(MINI) -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)
$(LIBFT_LIB):
	@make -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)
	@make clean -C $(MINI)
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	
re: fclean all

.PHONY: all clean fclean re
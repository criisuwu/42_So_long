# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 13:51:49 by chomobon          #+#    #+#              #
#    Updated: 2025/04/23 14:05:07 by chomobon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
SRCS = so_long.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
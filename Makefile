# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 17:20:23 by ekoljone          #+#    #+#              #
#    Updated: 2023/02/03 15:04:08 by ekoljone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = errors.c free.c list_utils.c make_stack.c operations.c smart_rotate.c sort_utils.c sorter.c utils.c
LIBFT = libft
OBJECT = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) main.c $(OBJECT) $(LIBFT)/libft.a -o $(NAME)
	
clean:
	$(RM) $(OBJECT)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:28:33 by mzridi            #+#    #+#              #
#    Updated: 2022/08/24 22:38:29 by mzridi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc

SRC = push_swap.c ft_split.c ft_join.c ft_atoi.c ft_lis.c swap.c rotate.c ft_utils.c rotate_stacks.c operations.c printer.c ft_free.c tab_operations.c push_swap_helper.c parser.c small_array.c
BONUS_SRC = ft_split.c ft_join.c ft_atoi.c ft_lis.c swap.c rotate.c ft_utils.c rotate_stacks.c operations.c printer.c ft_free.c tab_operations.c  get_next_line.c get_next_line_utils.c checker.c push_swap_helper.c parser.c

OBJ = $(SRC:.c=.o) 

BONUS_OBJ = $(BONUS_SRC:.c=.o) 

all: $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o checker

$(NAME): $(OBJ)
	$(CC) $(OBJ) -g -o $(NAME)
	
	
%.o: %.c push_swap.h
	$(CC) -Wall -Wextra -Werror -g -c $< -o $@
	
clean :
	@rm -rf $(OBJ) $(BONUS_OBJ) 
	
fclean : clean
	@rm -rf $(NAME) push_swap push_swap_bonus

re : fclean all

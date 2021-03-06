# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:28:33 by mzridi            #+#    #+#              #
#    Updated: 2022/07/03 12:34:33 by mzridi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc

SRC = push_swap.c ft_split.c ft_join.c ft_atoi.c ft_lis.c swap.c rotate.c ft_utils.c
BONUS_SRC = push_swap_bonus.c ft_split.c ft_join.c ft_lis.c swap.c rotate.c ft_utils.c

OBJ = $(SRC:.c=.o) 

BONUS_OBJ = $(BONUS_SRC:.c=.o) 

all: $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o push_swap_bonus

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	
	
%.o: %.c push_swap.h
	$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f *.o *.out
	
clean :
	@rm -rf $(OBJ) $(BONUS_OBJ) 
	
fclean : clean
	@rm -rf $(NAME) push_swap push_swap_bonus

re : fclean all

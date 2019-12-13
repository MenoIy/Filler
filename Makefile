# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 17:26:52 by kdaou             #+#    #+#              #
#    Updated: 2019/12/13 17:02:27 by kdaou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kdaou.filler

FLAG = -Wall -Wextra -Werror

FLR =	ft_filler.c\
		ft_filler_piece.c\
		ft_ini_struct.c\
		ft_read_stdin.c\
		main.c

LIBFT = libft/libft.a

SRC_FLR = $(addprefix filler/,$(FLR))


OBJ_FLR = $(SRC_FLR:.c=.o)

INC = -I includes/ -I /usr/local/Include 
INC_SRCS = includes/libft.h includes/ft_mlx.h includes/filler.h includes/mathlibft.h

all: $(NAME)

$(NAME): $(OBJ_FLR)
	@make -C libft
	@gcc $(OBJ_FLR) $(LIBFT) -o $(NAME)

$(OBJ_FLR): %.o : %.c $(INC_SRCS)
	gcc -o $@ -c $< $(FLAG) $(INC)


clean:
	@make -C libft/ clean
	@rm -f $(OBJ_FLR)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
re: fclean all

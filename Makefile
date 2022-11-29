# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 18:20:56 by elfetoua          #+#    #+#              #
#    Updated: 2019/10/15 00:31:25 by hiantrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =  ft_ls.c check.c help.c just_ls.c ls_time.c ls_time_help.c ls_l.c \
		create_list.c print_per.c make_str.c ls_r.c list_help.c \
		help_to_transfer.c help2.c

OUT=$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OUT) ft_ls.h
	make -C libft
	gcc $(CFLAGS) $(OUT) -L./libft -lft -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -f $(OUT)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

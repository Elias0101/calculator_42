#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkarri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 17:13:01 by tkarri            #+#    #+#              #
#    Updated: 2019/03/17 17:15:45 by tkarri           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = eval_expr

OUT = eval_expr

all: $(OUT)

$(OUT):
		gcc -Wall -Wextra -Werror -o $(NAME) *.c

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(OUT)

re: fclean all
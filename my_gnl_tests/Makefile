# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 08:04:03 by djagusch          #+#    #+#              #
#    Updated: 2022/11/21 17:16:45 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_gnl

CC = cc

CFLAGS = -Wall -Werror -Wextra

BONUS_NAME = my_gnl_bonus

FILES = get_next_line get_next_line_utils main

SRC_FILES = $(addsuffix .c, $(FILES))

BONUS_FILES = $(addsuffix _bonus.c, $(FILES))

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) -o $(NAME) $(SRC_FILES) $(CFLAGS) -I get_next_line.h

$(BONUS_NAME): $(BONUS_FILES)
	$(CC) -o $(BONUS_NAME) $(BONUS_FILES) $(CFLAGS) -D BUFFER_SIZE=42 -I get_next_line_bonus.h

bonus: $(BONUS_NAME)

clean:
	rm -f $(NAME) $(BONUS_NAME)

fclean: clean

re: clean all
	
.PHONY: all clean fclean re bonus
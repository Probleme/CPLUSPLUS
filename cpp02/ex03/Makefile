# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 02:14:07 by ataouaf           #+#    #+#              #
#    Updated: 2023/11/17 03:30:28 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = bsp
OBJECTS = ./obj
INCLUDES = ./inc
SRCS = $(addprefix src/, main.cpp Fixed.cpp Point.cpp bsp.cpp)
OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJECTS)/%.o: %.cpp $(INCLUDES)/Fixed.hpp $(INCLUDES)/Point.hpp
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
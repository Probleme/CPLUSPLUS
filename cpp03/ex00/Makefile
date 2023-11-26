# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 03:51:23 by ataouaf           #+#    #+#              #
#    Updated: 2023/11/26 00:21:51 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = claptrap
OBJECTS = ./obj
INCLUDES = ./inc
SRCS = $(addprefix src/, main.cpp ClapTrap.cpp)
OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJECTS)/%.o: %.cpp $(INCLUDES)/ClapTrap.hpp
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
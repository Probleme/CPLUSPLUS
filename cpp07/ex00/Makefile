# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 19:50:08 by ataouaf           #+#    #+#              #
#    Updated: 2024/04/25 17:36:48 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = execute
OBJECTS = ./obj
INCLUDES = ./inc
SRCS = $(addprefix src/, main.cpp)
OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJECTS)/%.o: %.cpp $(addprefix $(INCLUDES)/, whatever.hpp)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
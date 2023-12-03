# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 04:54:07 by ataouaf           #+#    #+#              #
#    Updated: 2023/12/03 16:06:21 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
NAME = AAnimal
OBJECTS = ./obj
INCLUDES = ./inc
SRCS = $(addprefix src/, main.cpp AAnimal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp)
OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJECTS)/%.o: %.cpp $(INCLUDES)/Cat.hpp $(INCLUDES)/Dog.hpp $(INCLUDES)/AAnimal.hpp $(INCLUDES)/WrongAnimal.hpp $(INCLUDES)/WrongCat.hpp $(INCLUDES)/Brain.hpp
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 09:27:13 by ataouaf           #+#    #+#              #
#    Updated: 2023/11/25 02:47:13 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
NAME = Animal
OBJECTS = ./obj
INCLUDES = ./inc
SRCS = $(addprefix src/, main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp)
OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJECTS)/%.o: %.cpp $(INCLUDES)/Cat.hpp $(INCLUDES)/Dog.hpp $(INCLUDES)/Animal.hpp $(INCLUDES)/WrongAnimal.hpp $(INCLUDES)/WrongCat.hpp
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
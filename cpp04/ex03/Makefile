# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 15:58:44 by ataouaf           #+#    #+#              #
#    Updated: 2023/12/06 09:33:17 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 #-g -fsanitize=address,undefined
NAME = AMateria
OBJECTS = ./obj
INCLUDES = ./inc
SRCS = $(addprefix src/, AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp main.cpp)
OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJECTS)/%.o: %.cpp $(addprefix $(INCLUDES)/, AMateria.hpp ICharacter.hpp Cure.hpp Ice.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re


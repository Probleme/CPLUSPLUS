# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 20:29:59 by ataouaf           #+#    #+#              #
#    Updated: 2023/10/20 03:42:01 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = phonebook
OBJECTS = ./obj
INCLUDES = ./inc
SRCS = $(addprefix srcs/, main.cpp Contact.cpp PhoneBook.cpp)
OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJECTS)/%.o: %.cpp $(INCLUDES)/Contact.hpp $(INCLUDES)/PhoneBook.hpp
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 13:00:13 by nsouchal          #+#    #+#              #
#    Updated: 2024/08/23 08:32:30 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC_FILE =	main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp

DIR_BUILD		=	.build/
DIR_SRCS 		= 	srcs/
DIR_HEADERS		=	includes/

HEADERFILES =	$(DIR_HEADERS)Bureaucrat.hpp \
				$(DIR_HEADERS)AForm.hpp \
				$(DIR_HEADERS)ShrubberyCreationForm.hpp \
				$(DIR_HEADERS)RobotomyRequestForm.hpp \
				$(DIR_HEADERS)PresidentialPardonForm.hpp \
				$(DIR_HEADERS)Intern.hpp

OBJS			=	$(patsubst %.cpp, $(DIR_BUILD)%.o, $(SRCS))
SRCS			=	$(addprefix $(DIR_SRCS),$(SRC_FILE))

FLAGS		=	-Wall -Werror -Wextra -std=c++98

CC = c++

.PHONY: all
all: $(NAME)

$(NAME): $(HEADERFILES) $(OBJS)
			$(CC) $(OBJS) -o $(NAME)

$(DIR_BUILD)%.o: %.cpp $(HEADERFILES) Makefile
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -c $< -o $@ -Iincludes

.PHONY: clean
clean:
	rm -rf $(DIR_BUILD)

.PHONY: fclean
fclean: clean
		rm -rf $(NAME)

.PHONY: re
re: fclean
	$(MAKE) all

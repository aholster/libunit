# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/21 14:55:10 by dsaripap      #+#    #+#                  #
#    Updated: 2019/04/21 23:08:54 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = gcc -Wall -Wextra -Werror
SRC = ft_atoi/atoi_test01.c ft_atoi/atoi_test02.c ft_atoi/atoi_test03.c \
	  ft_atoi/ft_atoi.c ft_atoi/atoi_launcher.c \
	  ../framework/init_test.c ../framework/ft_error.c \
	  ../framework/start_test.c \
	  ../framework/executioner.c ../framework/lu_lstdel.c \
	  ../framework/lu_putendl.c ../framework/lu_putnbr.c \
	  ../framework/lu_lstaddend.c \
	  ../framework/lu_putstr.c ../framework/lu_strlen.c \
	  ft_isalpha/isalpha_test01.c ft_isalpha/isalpha_test02.c \
	  ft_isalpha/isalpha_test03.c ft_isalpha/isalpha_launcher.c \
	  ft_isalpha/ft_isalpha.c \
	  ft_isdigit/isdigit_test01.c ft_isdigit/isdigit_test02.c \
	  ft_isdigit/isdigit_test03.c ft_isdigit/ft_isdigit.c \
	  ft_isdigit/isdigit_launcher.c \
	  ft_strcmp/strcmp_test01.c ft_strcmp/strcmp_test02.c \
	  ft_strcmp/strcmp_test03.c ft_strcmp/ft_strcmp.c \
	  ft_strcmp/strcmp_launcher.c \
	  ft_strlen/strlen_test01.c ft_strlen/strlen_test02.c \
	  ft_strlen/strlen_test03.c ft_strlen/ft_strlen.c \
	  ft_strlen/strlen_launcher.c \

OBJ = atoi_test01.o atoi_test02.o atoi_test03.o \
	  ft_atoi.o atoi_launcher.o \
	  init_test.o ft_error.o lu_lstaddend.o \
	  start_test.o executioner.o lu_lstdel.o \
	  lu_putendl.o lu_putnbr.o lu_putstr.o lu_strlen.o \
	  isalpha_test01.o isalpha_test02.o isalpha_test03.o \
	  isalpha_launcher.o ft_isalpha.o \
	  isdigit_test01.o isdigit_test02.o isdigit_test03.o \
	  isdigit_launcher.o ft_isdigit.o \
	  strcmp_test01.o strcmp_test02.o strcmp_test03.o \
	  ft_strcmp.o strcmp_launcher.o \
	  strlen_test01.o strlen_test02.o strlen_test03.o \
	  ft_strlen.o strlen_launcher.o \

INCL = header.h

all: $(NAME)
	Make all -C ./../framework/

$(NAME): $(OBJ)
	$(CC) -o $(NAME) main.c $(OBJ)

$(OBJ): $(SRC) $(INCL)
	$(CC) -c $(SRC)

.PHONY: clean

clean:
	rm -f $(OBJ)
	Make clean -C ./../framework/

fclean: clean
	rm -f $(NAME)
	Make fclean -C ./../framework/

re: fclean all

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1

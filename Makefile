# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:50:59 by aholster       #+#    #+#                 #
#    Updated: 2019/04/22 15:40:26 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DATE := $(shell date)

SOURCEPATH := ./

SOURCEFILES := ft_atoi ft_isalpha.c

00LOC = ./tests/ft_atoi/

TESTS00 = atoi_test01 atoi_test02 atoi_test03 atoi_launcher

01LOC = ./tests/ft_isalpha/

TESTS01 = isalpha_test01.c isalpha_test02.c isalpha_test03.c isalpha_launcher.c

02LOC =

TESTS02 = ft_isdigit/isdigit_test01.c ft_isdigit/isdigit_test02.c \
	  ft_isdigit/isdigit_test03.c ft_isdigit/ft_isdigit.c \
	  ft_isdigit/isdigit_launcher.c

03LOC = 

TESTS03 = ft_strcmp/strcmp_test01.c ft_strcmp/strcmp_test02.c \
	  ft_strcmp/strcmp_test03.c ft_strcmp/ft_strcmp.c \
	  ft_strcmp/strcmp_launcher.c

04LOC = 

TESTS04 = 

SRC =   \
	   \
	   \
	  ft_strlen/strlen_test01.c ft_strlen/strlen_test02.c \
	  ft_strlen/strlen_test03.c ft_strlen/ft_strlen.c \
	  ft_strlen/strlen_launcher.c \



SOURCE := $(TESTS00:%=$(00LOC)%.c) $(TESTS01:%=$(01LOC)%.c) $(SOURCEFILES:%=$(SOURCEPATH)%)

FRAMEPATH := ./../framework

FILEC = $(SOURCE:%=./%.c)

HEAD = header.h

NAME = test

NORM = norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1

CC = gcc -Wall -Werror -Wextra

print:
	@echo $(SOURCE)

all: $(NAME)

$(NAME):
	@make all -C $(FRAMEPATH)
	@echo "\033[0;33mStarting assembly of $(NAME)…\033[0;00m"
	@$(CC) $(SOURCE) -o $(NAME)
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m\n"
	./$(NAME)

clean:
	@make clean -C $(FRAMEPATH)
	@echo "\033[0;33mInitializing Summary Deletions...\033[0;00m"
	@find "./" -type f \( -name '*~' -o -name '\#*\#' -o -name '.DS_Store' \)\
	 -exec rm -rfv {} \;
	@echo "\033[0;31m	Executed!\033[0;00m\n"

fclean: clean
	@make fclean -C $(FRAMEPATH)
	@rm -rf $(NAME)
	@echo "\033[0;31mObituary of $(NAME): Deceased on $(shell date).\
	\033[0;00m\n"

re: fclean all
	@make re -C $(FRAMEPATH)

norm:
	@echo "**+++=====*=====*=====*=====*{\033[0;31mOUT\033[0;00m}\
	*=====*=====*=====*=====+++**\033[0;33m"
	@$(NORM) || TRUE 
	@echo "\033[0;00m**+++=====*=====*=====*=====*\
=====*=====*===*=====*=====+++**"

add:
	@git add $(FILEC) $(HEAD) Makefile
	git status

push: norm
ifdef MSG
	@git commit -m "$(MSG)"
	git push
else
	@git commit
	git push
endif
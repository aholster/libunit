# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:50:59 by aholster       #+#    #+#                 #
#    Updated: 2019/05/20 17:33:08 by jesmith       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DATE := $(shell date)

TESTS := $(shell find . -name '[0-9][0-9]_*.c') ./main.c

SOURCEPATH := ./

FRAMEPATH := ./../framework/

TEST_FUNCTIONS_PATH := $(FRAMEPATH)/test_functions

FILEC = $(TESTS)

HEAD = header.h

NAME = test

NORM = norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1

CC = gcc -Wall -Werror -Wextra


all: $(NAME)

init:
	@$(FRAMEPATH)/scripts/protoextract ./$(HEAD) ./$(HEAD)
	
$(NAME):
	@make all -C $(FRAMEPATH)
	@echo "\033[0;33mStarting assembly of $(NAME)…\033[0;00m"
	@$(CC) $(FILEC) -o $(NAME) -I ./ -I $(FRAMEPATH) -L $(FRAMEPATH) -lunit \
	-I ./$(TEST_FUNCTIONS_PATH) -I $(SOURCEPATH)
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m\n"
	@./$(NAME)

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
#	@make re -C $(FRAMEPATH)

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
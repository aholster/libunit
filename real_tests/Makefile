# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:50:59 by aholster       #+#    #+#                 #
#    Updated: 2019/04/24 13:33:13 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DATE := $(shell date)

SOURCEPATH := ./

SOURCEFILES := ft_atoi ft_isalpha ft_isdigit ft_strcmp ft_strlen

00LOC = ./ft_atoi/

TESTS00 = atoi_test01 atoi_test02 atoi_test03 atoi_launcher

01LOC = ./ft_isalpha/

TESTS01 = isalpha_test01 isalpha_test02 isalpha_test03 isalpha_launcher

02LOC = ./ft_isdigit/

TESTS02 = isdigit_test01 isdigit_test02 isdigit_test03 isdigit_launcher

03LOC = ./ft_strcmp/

TESTS03 = strcmp_test01 strcmp_test02 strcmp_test03 strcmp_launcher

04LOC = ./ft_strlen/

TESTS04 = strlen_test01 strlen_test02 strlen_test03 strlen_launcher

SOURCE := $(TESTS00:%=$(00LOC)%) $(TESTS01:%=$(01LOC)%) \
			$(TESTS02:%=$(02LOC)%) $(TESTS03:%=$(03LOC)%) \
			$(TESTS04:%=$(04LOC)%) $(SOURCEFILES:%=$(SOURCEPATH)%) \
			main

FRAMEPATH := ./../framework/

FILEC = $(SOURCE:%=%.c)

HEAD = header.h

NAME = test

NORM = norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1

CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make all -C $(FRAMEPATH)
	@echo "\033[0;33mStarting assembly of $(NAME)…\033[0;00m"
	@$(CC) $(FILEC) -o $(NAME) -I $(FRAMEPATH) -L $(FRAMEPATH) -lunit \
	-I $(SOURCEPATH)
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
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/20 15:50:06 by aholster       #+#    #+#                 #
#    Updated: 2019/04/20 21:58:55 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DATE := $(shell date)

SOURCE := ft_error executioner init_test lu_lstaddend lu_lstdel lu_putendl\
		lu_putstr lu_putnbr lu_strlen start_test

FILEC = $(SOURCE:%=./%.c)

OBJ =	$(SOURCE:%=./%.o)

HEAD = libunit.h

NAME = libunit.a

NORM = norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1

GCCC = ${CC} -c
CC = gcc -Wall -Werror -Wextra
AR = ar rcs

all: $(NAME)

assemble: $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

$(NAME):
	@echo "\033[0;33mStarting assembly of $(NAME)…\033[0;00m"
	@time make assemble
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m\n"

%.o: %.c
	@$(GCCC) -o $@ $<

clean:
	@echo "\033[0;33mInitializing Summary Deletions...\033[0;00m"
	@rm -rf $(OBJ)
	@find "./" -type f \( -name '*~' -o -name '\#*\#' -o -name '.DS_Store' \)\
	 -exec rm -rfv {} \;
	@echo "\033[0;31m	Executed!\033[0;00m\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31mObituary of $(NAME): Deceased on $(shell date).\
	\033[0;00m\n"

re: fclean all

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
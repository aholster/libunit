# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/20 15:50:06 by aholster       #+#    #+#                 #
#    Updated: 2019/05/31 19:49:35 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DATE := $(shell date)

BACKEND := ft_error lu_putendl lu_putstr lu_putnbr lu_strlen lu_lstaddend\
 lu_lstdel lu_putstrstr lu_atoi lu_putstr_fd lu_putendl_fd lu_putstrstr_fd\
 lu_putnbr_fd lu_strdup lu_memjoin lu_memcpy lu_lstlen lu_strcmp lu_strncmp\
 lu_strnequ lu_putcaret lu_putcaret_fd lu_putchar lu_putchar_fd

ASSERT := lu_assert assert_format 
#extractors lu_longprint extract_d extract_u

TESTFUNC := capture_fd reset_fd retrieve_text

TESTFUNCPATH := ./test_functions/

SOURCE := executioner init_test init_advtest start_test loadlaunch\
 activate_launchers launcherparser get_logfilefd putresult logresult

FILEC = $(SOURCE:%=./%.c) $(BACKEND:%=./backend/%.c)\
		$(TESTFUNC:%=$(TESTFUNCPATH)/%.c) $(ASSERT:%=./assert/%.c)

OBJ =	$(FILEC:%.c=%.o)

HEAD = libunit.h ./test_functions/test_functions.h ./assert/lu_assert.h

NAME = libunit.a

SCRIPTS = ./scripts/protoextract ./scripts/maingen ./scripts/launchgen

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
	@$(GCCC) -o $@ $< -I ./

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
	@git add $(FILEC) $(HEAD) $(SCRIPTS) Makefile
	git status

push: norm
ifdef MSG
	@git commit -m "$(MSG)"
	git push
else
	@git commit
	git push
endif
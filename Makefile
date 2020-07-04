##
## EPITECH PROJECT, 2020
## CCP_PLAZZA_2019
## File description:
## Makefile
##

NAME	=	strace

SRCNAME	=	main.c		\
		args/args.c	\
		ptrace/take_process.c	\
		ptrace/trace.c	\
		syscall_name/print_name.c	\
		syscall_name/display.c	\
		syscall_name/display2.c	\

OBJFLAG	=	-c

CCFLAG	=	-Iinclude

CCWARN	=	-Wall -Wextra

DBGFLAG	=	-g -Weverything

SRCPATH	=	$(addprefix source/, $(SRCNAME))
OBJPATH	=	$(patsubst %.c, %.o, $(SRCPATH))

all	:$(OBJPATH)
	@echo -e "\e[1;32mMaking Executable $(NAME)\e[0m"
	@$(CC) -o $(NAME) $(OBJPATH) $(CCFLAG) $(CCWARN) $(LDFLAG) -O0

%.o	:%.c
	@echo -e "\e[1;36mMaking Object $@\e[0m"
	@$(CC) -o $@ $< $(CCFLAG) $(OBJFLAG) $(CCWARN) $(OBJRULE) -O0

debug	:
	@echo -e "\e[1;31mDeleting Debug Executable $(NAME)\e[0m"
	clang -o $(NAME) $(SRCPATH) $(CCFLAG) $(CCWARN) $(DBGFLAG) -Wno-cast-qual

clean	:
	@echo -e "\e[1;31mDeleting Object $(OBJ)\e[0m"
	@-$(RM) -f $(OBJPATH)

fclean	: clean
	@echo -e "\e[1;31mDeleting Executable $(NAME)\e[0m"
	@-$(RM) -f $(NAME)

re	: fclean all

.PHONY: all clean fclean re debug

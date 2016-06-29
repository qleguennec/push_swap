# Directories
PROJECT		=	push_swap
BINDIR		?=	.
BUILDDIR	?=	build
NAME		=	$(BINDIR)/push_swap $(BINDIR)/checker

# Compiler options
CC			=	clang
CFLAGS		=	$(addprefix -I,$(INCLUDE)) -Wall -Wextra -Werror -g

# Color output
BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

SRC += cmp.c
SRC += exit.c
SRC += sort_quick.c
SRC += stack_apply_op.c
SRC += stack_build.c
SRC += stack_io.c
SRC += stack_ops.c
SRC += stack_ops_combined.c

LIB += libvect.a
LIB += libgnl.a
LIB += libft.a

OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))
LIBRARIES	=	$(addprefix $(BUILDDIR)/, $(LIB))
LIBLINK		=	$(addprefix -l, $(LIB:lib%.a=%))

all: $(NAME)

$(BUILDDIR)/%.a: %
	@echo -n $(BLUE)$(PROJECT)$(END)'\t'
	BINDIR=$(CURDIR)/$(BUILDDIR) BUILDDIR=$(CURDIR)/$(BUILDDIR) \
		   make --no-print-directory -C $<

$(BUILDDIR)/%.o: %.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	@echo -n $(BLUE)$(PROJECT)$(END)'\t'
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)/push_swap: $(OBJECTS) $(BUILDDIR)/push_swap.o $(LIBRARIES)
	@echo -n $(BLUE)$(PROJECT)$(END)'\t'
	@$(CC) $(CFLAGS) -L$(BUILDDIR)									\
		$(LIBLINK) $(BUILDDIR)/push_swap.o $(OBJECTS) $(LIBLINK)	\
		-o $(BINDIR)/push_swap
	@echo "OK\tpush_swap"

$(BINDIR)/checker: $(OBJECTS) $(BUILDDIR)/checker.o $(LIBRARIES)
	@echo -n $(BLUE)$(PROJECT)$(END)'\t'
	@$(CC) $(CFLAGS) -L$(BUILDDIR)									\
		$(LIBLINK) $(BUILDDIR)/checker.o $(OBJECTS) $(LIBLINK)		\
		-o $(BINDIR)/checker
	@echo "OK\tchecker"

.PHONY: clean fclean re

clean:
	@echo -n $(BLUE)$(PROJECT)$(END)'\t'
	rm -rf $(BUILDDIR)

fclean: clean
	@echo -n $(BLUE)$(PROJECT)$(END)'\t'
	rm -rf $(NAME)

re: fclean all

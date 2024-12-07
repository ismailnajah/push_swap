NAME = push_swap
BNAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRC = main.c\
	  push_swap_small.c\
	  push_swap_insts.c\
	  push_swap_utils.c\
	  ft_insts.c\
	  ft_moves.c\
	  ft_parse.c\
	  ft_stack.c\
	  ft_stack_ops.c\
	  ft_utils.c

BSRC = checker_bonus.c\
	  checker_insts.c\
	  ft_insts.c\
	  ft_moves.c\
	  ft_parse.c\
	  ft_stack.c\
	  ft_stack_ops.c\
	  ft_utils.c


OBJDIR = obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
BOBJ := $(BSRC:%.c=$(OBJDIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -s -C $(LIBFTDIR)

$(OBJDIR):
	mkdir -p obj

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -o $@ -c $^

bonus: $(BOBJ) $(LIBFT) push_swap.h
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJ) $(LIBFT)

clean:
	make -s -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -s -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus
.SECONDARY: $(OBJDIR) $(OBJ) $(BOBJ)

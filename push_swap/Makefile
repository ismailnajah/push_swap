NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRC = main.c\
	  ft_stack_instructions.c\

OBJDIR = obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -s -C $(LIBFTDIR)

$(OBJDIR):
	mkdir -p obj

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -o $@ -c $^

clean:
	make -s -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -s -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
.SECONDARY: $(OBJDIR) $(OBJ)

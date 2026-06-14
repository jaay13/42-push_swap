CC = cc

NAME = push_swap

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

INC = -Iinc -I$(LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = src/main.c \
	src/algo/choose_algo.c \
	src/algo/complex.c \
	src/algo/medium.c \
	src/algo/simple.c \
	src/algo/sort_three.c \
	src/bench/disorder.c \
	src/bench/output.c \
	src/ops/push.c \
	src/ops/reverse_rotate.c \
	src/ops/rotate.c \
	src/ops/swap.c \
	src/parse/flags.c \
	src/parse/input.c \
	src/parse/numbers.c \
	src/parse/validation.c \
	src/stack/stack_setup.c \
	src/stack/stack_free.c \
	src/stack/stack_utils.c \
	src/utils/error_handle.c \
	src/utils/helpers.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test:
	./$(NAME) 4 1 3 2

count:
	./$(NAME) 4 1 3 2 | wc -l

.PHONY: all clean fclean re test count

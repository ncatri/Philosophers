SRCS_FOLDER = src/
SRCS_LIST = parsing.c 				\
			parsing_utils.c			\
			setup_functions.c		\
			dinner.c				\
			utils.c					\
			check_ending.c
SRCS = $(addprefix $(SRCS_FOLDER), $(SRCS_LIST))
NAME = philo
HEADER = includes
OBJS = $(SRCS:.c=.o)
RM = rm -f
CC = clang
CFLAGS = -Werror -Wall -Wextra -g -pthread -I $(HEADER)

%.o: %.c $(HEADER)/philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS) $(HEADER) main.c
	$(CC) $(CFLAGS) $(OBJS) main.c -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(NAME).dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

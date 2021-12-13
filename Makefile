NAME = libftprintf.a

CC = gcc
GFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC = print_nbr_base.c \
		ft_printf.c    \
		print_str.c 	

OBJS = ${SRC:.c=.o}

all : ${NAME}

${NAME}: ${OBJS}
		ar rcs $@ ${OBJS}

%.o: %.c ${HEADER}
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
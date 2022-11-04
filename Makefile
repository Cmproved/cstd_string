CC=gcc

NAME=libcstdstr.a

SRC = src/cstr.c\
	src/init_cstr.c\
	src/cstr_next.c\
	src/tools.c\

CFLAGS 	+= -g2

OBJ=$(SRC:.c=.o)

RM=rm -r

all: ${NAME}

${NAME}: ${OBJ}
	ar rc $(NAME) $^

tests: ${NAME}
	gcc -Wall -g2 main.c -L. -lstringc

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME} a.out

re: fclean all

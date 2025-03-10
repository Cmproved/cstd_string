CC=gcc

NAME=libcstdstring.a

SRC = src/cstd_string.c\
	src/cstr_next.c\
	src/init_cstr.c\
	src/tools.c\
	src/capacity.c

CFLAGS 	+= -O3 -Ofast -Wall

CFLAGS_DEBUG += ${CFLAGS} -g2 -fanalyzer -Wextra -Wundef

OBJ=${patsubst %c, %o, ${SRC}}
OBJ_DEBUG=${patsubst %c, %o_debug, ${SRC}}

RM=rm -rf

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.o_debug: %.c
	${CC} ${CFLAGS_DEBUG} -c -o $@ $<

all: ${NAME}

${NAME}: ${OBJ}
	ar rc $(NAME) $^

debug: ${OBJ_DEBUG}
	ar rc ${NAME} $^

tests: debug
	gcc ${CFLAGS_DEBUG} tests/main.c -L. -lcstdstring

clean:
	${RM} ${OBJ} ${OBJ_DEBUG}

fclean: clean
	${RM} ${NAME} a.out

re: fclean all

.PHONY: all ${NAME} debug tests clean re fclean

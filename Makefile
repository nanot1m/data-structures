all: main

main: main.c
	clang -Wall -Wextra -Werror -std=gnu99 -O3 -o main main.c

clean:
	rm -f main

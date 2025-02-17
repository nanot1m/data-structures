all: main

main: main.c linked_list.h
	clang -Wall -Wextra -Werror -O3 -o main main.c

clean:
	rm -f main

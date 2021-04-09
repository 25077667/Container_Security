jb: jb.o
	$(CC) $^ -Wall -Wextra -std=c99 -o $@

clean:
	rm -f jb.o jb

indent:
	clang-format -i jb.c

.PHONY: clean

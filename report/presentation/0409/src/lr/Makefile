lr: lr.o
	$(CC) $^ -Wall -Wextra -std=c99 -o $@

clean:
	rm -f lr.o lr

indent:
	clang-format -i lr.c

.PHONY: clean

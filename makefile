all:
	set -xe
	clang -Wall -Wextra -o nn nn.c -lm
run:
	./nn

CC = clang
CFLAGS = -Wall -O3

build: link

add:
	nasm -felf64 add.asm

sub:
	nasm -felf64 sub.asm

mul:
	nasm -felf64 mul.asm

div:
	nasm -felf64 div.asm

main:
	$(CC) -c main.c $(CFLAGS)

link: main add sub mul div
	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 \
        /usr/lib/x86_64-linux-gnu/crt1.o \
        /usr/lib/x86_64-linux-gnu/crti.o \
        -lc add.o \
		-lc sub.o \
		-lc mul.o \
		-lc div.o \
		-lc main.o \
        /usr/lib/x86_64-linux-gnu/crtn.o \
        -o bignum
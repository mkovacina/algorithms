all: generate-sequence

generate-sequence: main.c
	$(CC) $(CFLAGS) -o generate-sequence main.c

DEPS = input.h

programa: main.o input.o
	gcc -o programa main.o input.o $(DFLAGS)

main.o: main.c $(DEPS)
	gcc -c main.c $(DFLAGS)

input.o: input.c $(DEPS)
	gcc -c input.c $(DFLAGS)

# Compila usando opciones que facilitan la depuración
.PHONY: debug
debug: DFLAGS = -g -fsanitize=address,undefined
debug: clean programa

.PHONY: clean
clean:
	rm -rf programa *.o
CFLAGS=-Wall -Wextra -Werror -g

SOLUTION=solution.test

all: $(SOLUTION)

$(SOLUTION):
	gcc -o $(SOLUTION) $(CFLAGS) $(SOLUTION).c

clean:
	rm -f *.o

fclean: clean
	rm $(SOLUTION)


re: fclean all

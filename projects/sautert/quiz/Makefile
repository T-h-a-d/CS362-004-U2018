CFLAGS = -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c -g  $(CFLAGS)

clean:
	rm -rf *.gcda *.gcno *.o *.dSYM testme
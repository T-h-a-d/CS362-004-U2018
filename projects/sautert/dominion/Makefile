CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unitTest: unittest1.c dominion.o rngs.o	
	gcc -o unittest1.c dominion.o rngs.o $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

cardtest1coverage: cardtest1
	./cardtest1 &> cardtest1coverage.out
	gcov dominion.c >> cardtest1coverage.out
	cat dominion.c.gcov >> cardtest1coverage.out

cardtest2coverage: cardtest2
	./cardtest2 &> cardtest2coverage.out
	gcov dominion.c >> cardtest2coverage.out
	cat dominion.c.gcov >> cardtest2coverage.out

cardtest4coverage: cardtest4
	./cardtest4 &> cardtest4coverage.out
	gcov dominion.c >> cardtest4coverage.out
	cat dominion.c.gcov >> cardtest4coverage.out

## Assignment 4 section

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1coverage: randomtestcard1
	./randomtestcard1 &> randomtestcard1coverage.out
	gcov dominion.c >> randomtestcard1coverage.out
	cat dominion.c.gcov >> randomtestcard1coverage.out

randomtestcard2coverage: randomtestcard2
	./randomtestcard2 &> randomtestcard2coverage.out
	gcov dominion.c >> randomtestcard2coverage.out
	cat dominion.c.gcov >> randomtestcard2coverage.out

randomtestadventurercoverage: randomtestadventurer
	./randomtestadventurer &> randomtestadventurercoverage.out
	gcov dominion.c >> randomtestadventurercoverage.out
	cat dominion.c.gcov >> randomtestadventurercoverage.out

## End assignment 4 section

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -f randomtestcard1 randomtestcard2 randomtestadventurer cardtest1 cardtest2 cardtest4
	rm -rf *.dSYM

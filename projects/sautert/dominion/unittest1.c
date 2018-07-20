#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"

//Unit test for buyCard
int main(int argc, char **argv)
{
    printf("----Unit Test 1: buyCard----\n");

    struct gameState* state = malloc(sizeof(struct gameState*));
    int* cards = kingdomCards(adventurer, smithy, council_room, feast, gardens, mine, remodel, 
                                village, baron, great_hall);
    
    initializeGame(2, cards, 100, state);

    //Make sure player has enough money to buy cards
    state->coins = 100;

    //Test for card in game
    state->numBuys = 1;
    printf("Card in Game...");
    if (buyCard(smithy, state) == -1)
        printf("Buy Failed\n");
    else
        printf("Buy Passed\n");

    //Test for card not in game
    state->numBuys = 1;
    printf("Card Not in Game...");
    if(buyCard(tribute, state) == -1)
        printf("Buy Failed\n");   
    else
        printf("Buy Passed\n");   

    //Test for none of that type of card left
    state->numBuys = 1;
    state->supplyCount[adventurer] = 0;
    printf("None of that Card Left...");
    if (buyCard(adventurer, state) == -1)
        printf("Buy Failed\n");
    else
        printf("Buy Passed\n");

    //Test for no buys left this turn
    state->numBuys = 0;
    printf("No Buys Left this Turn...");
    if (buyCard(adventurer, state) == -1)
        printf("Buy Failed\n");
    else
        printf("Buy Passed\n");

    //Test for not enough money
    state->coins = 0;
    state->numBuys = 1;
    printf("Not Enough Money...");
    if (buyCard(adventurer, state) == -1)
        printf("Buy Failed\n");
    else
        printf("Buy Passed\n");
}
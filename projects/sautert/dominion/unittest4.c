#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"

//Unit test for handCard
int main(int argc, char **argv)
{
    printf("----Unit Test 4: handCard----\n");

    struct gameState state;
    int *cards = kingdomCards(adventurer, smithy, council_room, feast, gardens, mine, remodel,
                              village, baron, great_hall);

    initializeGame(2, cards, 100, &state);

    // //Test if card just added to hand can be retrieved by handCard
    // printf("Check Retrieval by Hand Card...\n");
    // printf("Expected: 7\n");

    // //Add card to players hand 
    // gainCard(adventurer, &state, 2, 0);

    // //Get num cards in first players hand
    // int numCardsInHand = numHandCards(&state);

    // int card = handCard(0, &state);

    // if(card == adventurer)
    // {
    //     printf("%s%d\n" "Actual: ", card);
    //     printf("** Test Passed **\n\n");
    // }
    
    // else
    // {
    //     printf("%s%d\n" "Actual: ", card);
    //     printf("** Test Failed **\n\n"); 
    // }
}
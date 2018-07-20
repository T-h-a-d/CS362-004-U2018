#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"

//Unit test for fullDeckCount
int main(int argc, char **argv)
{
    printf("----Unit Test 2: fullDeckCount----\n");

    struct gameState *state = malloc(sizeof(struct gameState *));
    int *cards = kingdomCards(adventurer, smithy, council_room, feast, gardens, mine, remodel,
                              village, baron, great_hall);

    initializeGame(2, cards, 100, state);

    //Check if added card is counted in deck
    printf("Check Added Card Counted in Deck...");

    //Make sure card is not yet in deck
    assert(fullDeckCount(0, smithy, state) == 0);

    //Make sure adding the card did not fail (this happens every so often for some reason)
    assert(gainCard(smithy, state, 1, 0) != -1);

    int smithy_count = fullDeckCount(0, smithy, state);

    if (smithy_count == 1)
        printf("Test Passed\n");
    else
    {
        printf("%d\n", smithy_count);
        printf("Test Failed\n");
    }

    //Check if added card is counted in hand
    printf("Check Added Card Counted in Hand...");

    //Make sure card is not yet in hand
    assert(fullDeckCount(0, council_room, state) == 0);

    //Make sure adding the card did not fail (this happens every so often for some reason)
    assert(gainCard(council_room, state, 2, 0) != -1);

    int council_room_count = fullDeckCount(0, council_room, state);

    if (council_room_count == 1)
        printf("Test Passed\n");
    else
    {
        printf("%d\n", council_room_count);
        printf("Test Failed\n");
    }

    //Check if added card is counted is discard pile
    printf("Check Added Card Counted in Discard Pile...");

    //Make sure card is not yet in discard pile
    assert(fullDeckCount(0, adventurer, state) == 0);

    //Make sure adding the card did not fail (this happens every so often for some reason)
    assert(gainCard(adventurer, state, 3, 0) != -1);

    int adventurer_count = fullDeckCount(0, adventurer, state);

    if (adventurer_count == 1)
        printf("Test Passed\n");
    else
    {
        printf("%d\n", adventurer_count);
        printf("Test Failed\n");
    }
}
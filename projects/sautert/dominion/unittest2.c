#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"

//Unit test for fullDeckCount
int main(int argc, char **argv)
{
    printf("----Unit Test 2: fullDeckCount----\n");

    struct gameState state;
    int *cards = kingdomCards(adventurer, smithy, council_room, feast, gardens, mine, remodel,
                              village, baron, great_hall);

    initializeGame(2, cards, 100, &state);

    //Check if added card is counted in deck
    printf("Check Added Card Counted in Deck...\n");
    printf("Expected: Smithy Deck Count at 1\n");

    //Make sure card is not yet in deck
    assert(fullDeckCount(0, smithy, &state) == 0);

    gainCard(smithy, &state, 1, 0);

    int smithy_count = fullDeckCount(0, smithy, &state);

    if (smithy_count == 1)
    {
        printf("%s%d\n", "Actual: Smithy Deck Count at ", smithy_count);
        printf("** Test Passed ** \n\n");
    }
    else
    {
        printf("%s%d\n", "Actual: Smithy Deck Count at ", smithy_count);
        printf("** Test Failed **\n\n");
    }

    //Check if added card is counted in hand
    printf("Check Added Card Counted in Hand...\n");
    printf("Expected: Council Room Hand Count at 1\n");

    //Make sure card is not yet in hand
    assert(fullDeckCount(0, council_room, &state) == 0);

    gainCard(council_room, &state, 2, 0);

    int council_room_count = fullDeckCount(0, council_room, &state);

    if (council_room_count == 1)
    {
        printf("%s%d\n", "Actual: Council Room Hand Count at ", council_room_count);
        printf("** Test Passed ** \n\n");
    }
    else
    {
        printf("%s%d\n", "Actual: Council Room Hand Count at ", council_room_count);
        printf("** Test Failed **\n\n");
    }

    //Check if added card is counted is discard pile
    printf("Check Added Card Counted in Discard Pile...\n");
    printf("Expected: Adventurer Discard Pile Count at 1\n");

    //Make sure card is not yet in discard pile
    assert(fullDeckCount(0, adventurer, &state) == 0);

    gainCard(adventurer, &state, 3, 0);

    int adventurer_count = fullDeckCount(0, adventurer, &state);

    if (adventurer_count == 1)
    {
        printf("%s%d\n", "Actual: Adventurer Discard Pile Count at ", adventurer_count);
        printf("** Test Passed ** \n\n");
    }
    else
    {
        printf("%s%d\n", "Actual: Adventurer Discard Pile Count at ", adventurer_count);
        printf("** Test Failed **\n\n");
    }
}
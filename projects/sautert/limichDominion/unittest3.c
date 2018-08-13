#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"

//Unit test for isGameOver
int main(int argc, char **argv)
{
    printf("----Unit Test 3: isGameOver----\n");

    struct gameState state;
    int *cards = kingdomCards(adventurer, smithy, council_room, feast, gardens, mine, remodel,
                              village, baron, great_hall);

    initializeGame(2, cards, 100, &state);

    //Test where province cards are gone
    printf("Province Cards Gone...\n");
    printf("Expected: Game Over\n");
    state.supplyCount[province] = 0;

    if(isGameOver(&state))
    {
        printf("Actual: Game Over\n");
        printf("** Test Passed **\n\n");
    }
        
    else
    {
        printf("Actual: Game Not Over\n");
        printf("** Test Failed **\n\n");
    }

    //Check for empty supply piles

    //Case where 2 supply piles are empty (should keep playing and return false)
    printf("2 Supply Piles Empty...\n");
    printf("Expected: Game Not Over\n");
    state.supplyCount[province] = 8;
    state.supplyCount[adventurer] = 0;
    state.supplyCount[smithy] = 0;

    if(isGameOver(&state))
    {
        printf("Actual: Game Over\n");
        printf("** Test Failed **\n\n");
    }
    else 
    {
        printf("Actual: Game Not Over\n");
        printf("** Test Passed **\n\n");
    }

    //Case where 3 supply piles are empty (should end game and return true)
    printf("3 Supply Piles Empty...\n");
    printf("Expected: Game Over\n");
    state.supplyCount[province] = 8;
    state.supplyCount[adventurer] = 0;
    state.supplyCount[smithy] = 0;
    state.supplyCount[mine] = 0;

    if (isGameOver(&state))
    {
        printf("Actual: Game Over\n");
        printf("** Test Passed **\n\n");
    }
    else
    {
        printf("Actual: Game Not Over\n");
        printf("** Test Failed **\n\n");
    }
}
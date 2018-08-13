#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"

//Unit test for handCard
int main(int argc, char **argv)
{
    printf("----Unit Test 4: handCard----\n");

    const char *kingdomCardNames[10];
    kingdomCardNames[0] = "Adventurer";
    kingdomCardNames[1] = "Council Room";
    kingdomCardNames[2] = "Feast";
    kingdomCardNames[3] = "Gardens";
    kingdomCardNames[4] = "Mine";
    kingdomCardNames[5] = "Remodel";
    kingdomCardNames[6] = "Smithy";
    kingdomCardNames[7] = "Village";
    kingdomCardNames[8] = "Baron";
    kingdomCardNames[9] = "Great Hall";

    struct gameState state;
    int *cards = kingdomCards(adventurer, smithy, council_room, feast, gardens, mine, remodel,
                              village, baron, great_hall);

    initializeGame(2, cards, 100, &state);

    //Test if card just added to hand can be retrieved by handCard
    printf("Check Retrieval by Hand Card...\n");
    printf("Expected: Adventurer\n");

    //Add card to players hand 
    gainCard(adventurer, &state, 2, 0);

    //Get num cards in first players hand
    int numCardsInHand = numHandCards(&state);

    int card = handCard(numCardsInHand - 1, &state);

    if(card == adventurer)
    {
        printf("Actual: %s\n", kingdomCardNames[card - 7]);
        printf("** Test Passed **\n\n");
    }
    
    else
    {
        printf("Actual: %s\n", kingdomCardNames[card - 7]);
        printf("** Test Failed **\n\n"); 
    }
}
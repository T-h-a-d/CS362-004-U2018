#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"

//Card test for Village
int main(int argc, char **argv)
{
    printf("----------Card Test 4: Village----------\n\n");

    struct gameState state, testState;
    int *cards = kingdomCards(adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall);

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

    const char *victoryCardNames[3];
    victoryCardNames[0] = "Estate";
    victoryCardNames[1] = "Duchy";
    victoryCardNames[2] = "Province";

    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player = 0;

    int cardsDrawn = 1, cardsDiscarded = 1, cardsShuffled = 0, coinsGained = 0;

    initializeGame(2, cards, 1000, &state);

    //Test if current player
    printf("Player Draws 1 Card and Gains 2 Actions...\n");
    memcpy(&testState, &state, sizeof(struct gameState));

    cardEffect(village, choice1, choice2, choice3, &testState, handPos, &bonus);

    printf("Hand count = %d, Expected = %d\n", testState.handCount[player], state.handCount[player] + cardsDrawn - cardsDiscarded);
    if (testState.handCount[player] == state.handCount[player] + cardsDrawn - cardsDiscarded)
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    printf("Deck count = %d, Expected = %d\n", testState.deckCount[player], state.deckCount[player] - cardsDrawn + cardsShuffled);
    if (testState.deckCount[player] == state.deckCount[player] - cardsDrawn + cardsShuffled)
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    printf("Coin Count = %d, Expected = %d\n", testState.coins, state.coins + coinsGained);
    if (testState.coins == state.coins + coinsGained)
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    //Test that player who played village was awarded 2 additional actions
    printf("Action Count = %d, Expected = %d\n", testState.numActions, state.numActions + 2);
    if (testState.numActions == state.numActions + 2)
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    //Test that there was no state change to other player
    printf("Checking for State Change in Other Players...\n");

    printf("Hand count = %d, Expected = %d\n", testState.handCount[player + 1], state.handCount[player + 1]);
    if (testState.handCount[player + 1] == state.handCount[player + 1])
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    printf("Deck count = %d, Expected = %d\n", testState.deckCount[player + 1], state.deckCount[player + 1]);
    if (testState.deckCount[player + 1] == state.deckCount[player + 1])
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    testState.whoseTurn = 1;
    state.whoseTurn = 1;

    printf("Coin Count = %d, Expected = %d\n", testState.coins, state.coins);
    if (testState.coins == state.coins)
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    printf("Action Count = %d, Expected = %d\n", testState.numActions, state.numActions + 2);
    if (testState.numActions == state.numActions + 2)
        printf("** Test Passed **\n\n");
    else
        printf("** Test Failed **\n\n");

    //Test that no state change occurs in victory and kingdom card piles
    printf("Checking for State Change in Victory Card Pile...\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%s Card Count = %d, Expected = %d\n", victoryCardNames[i], testState.supplyCount[i + 1], state.supplyCount[i + 1]);
        if (testState.supplyCount[i + 1] == state.supplyCount[i + 1])
            printf("** Test Passed **\n\n");
        else
            printf("** Test Failed **\n\n");
    }

    printf("Checking for State Change in Kingdom Card Pile...\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%s Card Count = %d, Expected = %d\n", kingdomCardNames[i], testState.supplyCount[i + 7], state.supplyCount[i + 7]);
        if (testState.supplyCount[i + 7] == state.supplyCount[i + 7])
            printf("** Test Passed **\n\n");
        else
            printf("** Test Failed **\n\n");
    }
}
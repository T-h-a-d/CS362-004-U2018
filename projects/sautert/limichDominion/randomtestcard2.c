#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

//Random test for village
int main(int argc, char **argv)
{
    srand(time(NULL));

    printf("----Random Test: Village ----\n");

    int *cards = kingdomCards(adventurer, smithy, council_room, feast, gardens, mine, remodel,
                              village, baron, great_hall);

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

    int temphand[MAX_HAND];
    int drawntreasure = 0;
    int z = 0;

    struct gameState state, testState;
    int numPlayers, randSeed, playerTurn, deckSize, handSize;

    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player = 0;

    int cardsDrawn = 1, cardsDiscarded = 1, cardsShuffled = 0, coinsGained = 0;

    int handCountFailed = 0, deckCountFailed = 0, coinCountFailed = 0, actionCountFailed = 0;

    //Perform 200000 random unit tests
    for (int i = 0; i < 200000; i++)
    {

        //Clear states
        memset(&state, 0, sizeof(struct gameState));
        memset(&testState, 0, sizeof(struct gameState));

        //Randomly generate number of players and seed for initialize game
        numPlayers = (rand() % (4 + 1 - 2)) + 2;

        randSeed = rand() % 10000 + 1;

        initializeGame(numPlayers, cards, randSeed, &state);

        playerTurn = rand() % numPlayers + 1;
        playerTurn = playerTurn - 1;
        state.whoseTurn = playerTurn;

        //Fill players deck and hands with random cards
        deckSize = rand() % (MAX_DECK + 1);

        for (int i = 0; i < numPlayers; i++)
        {
            state.deckCount[i] = deckSize;
        }

        for (int i = 0; i < numPlayers; i++)
        {
            for (int j = 0; j < state.deckCount[i]; j++)
            {
                int randomTreasureCard = rand() % (50 + 1);
                int randomCard = rand() % 10;

                if (randomTreasureCard == 1)
                    state.deck[i][j] = copper;
                else if (randomTreasureCard == 2)
                    state.deck[i][j] = silver;
                else if (randomTreasureCard == 3)
                    state.deck[i][j] = gold;
                else
                    state.deck[i][j] = cards[randomCard];
            }
        }

        memcpy(&testState, &state, sizeof(struct gameState));

        cardEffect(village, choice1, choice2, choice3, &testState, handPos, &bonus);

        //Compare pre and post states
        //Test if current player drew 1 card and gained 2 actions
        printf("Player Draws 1 Card and Gains 2 Actions...\n");

        printf("Hand count = %d, Expected = %d\n", testState.handCount[player], state.handCount[player] + cardsDrawn - cardsDiscarded);
        if (testState.handCount[player] == state.handCount[player] + cardsDrawn - cardsDiscarded)
            printf("** Test Passed **\n\n");
        else
        {
            printf("** Test Failed **\n\n");
            handCountFailed++;
        }

        printf("Deck count = %d, Expected = %d\n", testState.deckCount[player], state.deckCount[player] - cardsDrawn + cardsShuffled);
        if (testState.deckCount[player] == state.deckCount[player] - cardsDrawn + cardsShuffled)
            printf("** Test Passed **\n\n");
        else
        {
            printf("** Test Failed **\n\n");
            deckCountFailed++;
        }

        printf("Coin Count = %d, Expected = %d\n", testState.coins, state.coins + coinsGained);
        if (testState.coins == state.coins + coinsGained)
            printf("** Test Passed **\n\n");
        else
        {
            printf("** Test Failed **\n\n");
            coinCountFailed++;
        }

        //Test that player who played village was awarded 2 additional actions
        printf("Action Count = %d, Expected = %d\n", testState.numActions, state.numActions + 2);
        if (testState.numActions == state.numActions + 2)
            printf("** Test Passed **\n\n");
        else
        {
            printf("** Test Failed **\n\n");
            actionCountFailed++;
        }
    }

    printf("Village Failed Hand Count: %d times\n", handCountFailed);
    printf("Village Failed Deck Count: %d times\n", deckCountFailed);
    printf("Village Failed Coin Count: %d times\n", coinCountFailed);
    printf("Village Failed Action Count: %d times\n", actionCountFailed);
}
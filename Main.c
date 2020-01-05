/*=============================================================================$
|   Source code: Main.c
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #4 Stud Poker
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [10/29/2019], at the beginning of class
|
|    I hereby certify that this collective work is my own
|   and none of it is the work of any other person or entity.
|   ______________________________________ [Alejandro Martinez]
|
|  Language:  [C]
|  Compile/Run:
|
|   COMPILATION NOT USING MAKEFILE:
|
|       The following source files and header files must be 
|       in the same directory
|
|       Source Files: inputValidation.c poker.c Main.c
|       Header File: cardConstants.h
|
|       The command to compile will be: 
|           
|           gcc inputValidation.c poker.c Main.c -o pokerHand.out
|
|       To Run:
|
|           ./pokerHand.out x y
|
|           x = Any number from [CARD_BOUND_ONE-CARD_BOUND_THIRTEEN],
|                    [1-13], however the value will eventually
|                    change to FIVE_POKER_CARDS or 5.
|           y = [TWO_PLAYERS-TEN_PLAYERS] or [2-10](Players allowed to play)
|
|           Note: Recall that the first input should always be five
|                 as we are playing poker.
|
|           If the user does not comply with the input an error message
|           will be displayed.
|
|   COMPILATION USING THE MAKEFILE:
|
|           This file must be in the same directory as the 
|           following source/hearder/executable files: 
|
|               inputValidation.c poker.c Main.c cardConstants.h
|               pokerHand.out
|               
|       To compile execute this comand: 
|
|                make build
|
|       To run execute the following comand: 
|
|                ./pokerHand.out x y
|                x = Any number from [CARD_BOUND_ONE-CARD_BOUND_THIRTEEN], 
|                    [1-13], however the value will eventually
|                    change to FIVE_POKER_CARDS or 5.
|
|                y = [TWO_PLAYERS-TEN_PLAYERS] or [2-10](Players allowed to play)
|           
|   
|       As explained previously:
|
|           Note: Recall that the first input should always be five
|                 as we are playing poker.
|
|           If the user does not comply with the input an error message
|           will be displayed.
|  +-------------------------------------------------------------------------
|
|  Description: This program simulates a game of poker. All the hands
|               are displayed, then they are shuffled, then the are given
|               to the players, then each player sorts each hand, then each 
|               hand is classified according to ranks given in poker stars,
|               then we find a winner. Lastly we have pre-determined hands
|               that will be reviewed and classified their poker rank output. 
|               
|               The input as described above should be within the boundaries
|               described.
|
|               After the input is validated, the program will generate a deck
|               of cards structs. This deck of cards structs is generated from 
|               (1) toc(53). The reason why this
|               deck array did not started at 0 was to facilitate further
|               computations.
|
|               After the array is generated, internal manipulation was done
|               to order the deck. Then the modern algorithm of shuffling
|               documented below was used to shuffle the deck of card structs.
|
|               Then a struct of hands was created to store the hands of each 
|               player. Then these structs of hands were delt. Then they were 
|               sorted using the algorithm of insertion sort.
|
|               Then using poker starts we classified each hand. With this 
|               process we were able to seelect a winner.
|              
|               Lastly, we used pre-determined hands and classified them with
|               the same algorithms previously described.
|
|
|        Input:  Program will receive two inputs from the command line. 
|                First Command: Range could be from [1-13] but the program will
|                               always change it to 5 as we are playing poker.
|                Second Command: The number of players that will play the game
|                                The range should go from [TWO_PLAYERS-TEN_PLAYERS]
|
|
|       Output:  These are the different type of outputs that will be displayed
|
|                 - Legend of the Cards
|                 - Original ordered deck
|                 - Random Shuffle Deck
|                 - Player Hands dealt from the top
|                 - Player Hands Sorted
|                 - Players Hands Ranked
|                 - Player Hands winner(s)
|                 - Poker Hands Test
|
|     Process:   The program's steps are as follows:
|
|                1. The user in executing should put in the command line the
|                   number of cards and the number of players.
|                2. There would be a user validation in this step. 
|                   Note that the only acceptable input is:
|                   2.1 Input #1 [1-13] then it is changed to 5 
|                   2.1 Input #2 [2-10]
|                3. If the input is valid, the ordered deck of card structs is 
|                   generated.
|                4. Then the deck is shuffle and printed.
|                5. Then hands structs are created and given to the players 
|                   according to the input.
|                6. Then these structs of hands are sorted
|                7. Then with the poker stars sources that will be stated below
|                   we classify each hand.
|                8. Then though a poker rank number we find a winner
|                9. Lastly we do this same process to some pre determined hands.
|
|.  Source of Formulas Required For Calculations:
|                Refer to the link below for full explanation on how to
|                  shuffle a deck of cards
| https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
|
|                Refer to the link below for full explanation on how to
|                   classify each deck
|               https://www.pokerstars.net/poker/
|               
|                Recall that both of these books were used in the program for
|                  ideas, ways to code, and code examples:
|                   C How to Program Paul Deitel | Harvey Deitel
|                   The C Programming Language Brian W. Kernigham Dennis M. Ritchie
|
|   Required Features Not Included:
|                Not included: All required features are included.
|
|   Known Bugs:  Not know Bugs in this program
|
|  *=====================================================================*/


#include <stdio.h>
#include "cardConstants.h"

int main(int argc, char* argv[])
{
        srand(time(NULL));

        const char SUITSARRAY[SUITS] = {'H', 'D', 'C', 'S'};

        char RANKARRAY[FACES] = {'A','2', '3','4','5', '6','7', '8', '9',
                                                         'T', 'J', 'Q', 'K'};
        if(validateInput(argc, argv))
        {
                const int CARDS_PER_PLAYER = FIVE_POKER_CARDS;
                const int PLAYERS_IN_THE_GAME = atoi(argv[ARGUMENT_TWO]);
                Card deck[CARDDECKSIZE] = {0};
                Hand numberOfHands[PLAYERS_IN_THE_GAME];
                explainTheLegend(SUITSARRAY, RANKARRAY);
                populateDeckOfCards(deck);
                printDeckOfCards(deck, SUITSARRAY, RANKARRAY);
                shuffle(deck);
                printDeckOfCards(deck, SUITSARRAY, RANKARRAY);
                createTheHands(numberOfHands, deck, PLAYERS_IN_THE_GAME);
                printTheHands(numberOfHands,SUITSARRAY,RANKARRAY,
                                        PLAYERS_IN_THE_GAME);
                insertionSort(numberOfHands, PLAYERS_IN_THE_GAME);
                printTheHands(numberOfHands,SUITSARRAY,RANKARRAY,
                                        PLAYERS_IN_THE_GAME);
                assignRanks (numberOfHands, PLAYERS_IN_THE_GAME);
                printResults(numberOfHands,SUITSARRAY,RANKARRAY,
                                                PLAYERS_IN_THE_GAME);
                printWinner(numberOfHands,SUITSARRAY,RANKARRAY,
                                                        PLAYERS_IN_THE_GAME);
                Hand testingHands[NUMBER_OF_HANDS] = {0};
                pokerTest (testingHands);
                printTestingHands(testingHands, SUITSARRAY,RANKARRAY);
                return NO_ERROR;
        }
    else
    {
                messageToPrintForError ();
                return ERROR;
        }

}

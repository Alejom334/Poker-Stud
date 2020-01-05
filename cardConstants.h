/*=============================================================================$
|   Header File: cardConstants.h
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #3 Dealer Card
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [10/29/2019], at the beginning of class
|
|   Description: This header file holds the constant and function prototypes
|               shared by the source files of Main.c, poker.c and inputValidation.c
|				
|
|   Important Things to Mention:
|
|			In the structure of our program we will be using to structs 
|			described below. 
|			- Struct of Cards will store two integers (Rank, Suit)
|			- Struct of Hand will store and array of struct cards and an int
|				with the poker rank. (poker rank is a number that describes
|				the type of hand)

=============================================================================$*/

#include <stdio.h>
#include <stdlib.h> //used for atoi in numberInputValidation
#include <time.h> // Used to make the seed of random in relation to time

#define TRUE 1 //Used for readability
#define FALSE 0 //Used for readability
#define NO_ERROR 0 //Exit with no error
#define ERROR 1 //Exit with error
#define TWO_PLAYERS 2 //used for lower bound of min players
#define TEN_PLAYERS 10 //used for higher bound of max players
#define FIVE_POKER_CARDS 5 //poker is required to provide five cards
#define COUNTER_ONE 1 //used to initialize counter of arrays that start at 1
#define SUITS 4 //Maximum number of suits
#define FACES 13 //Maximum numbers of different faces
#define CARDS 52 //Maximum number of cards
#define MAXIMUM_PLAYERS_ALLOWED 13 //Maximum number of players allowed
#define MAXIMUM_CARDS_ALLOWED 13 //Maximum number of cards allow per player
#define CARD_BOUND_ONE 1 //Bound one for full array of cards
#define CARD_BOUND_THIRTEEN 13 // Bound thirteen for full array of cards
#define CARD_BOUND_TWENTYSIX 26 // Bound twenty six for full array of cards
#define CARD_BOUND_THIRTYNINE 39 // Bound thirty nine for full array of cards
#define TOTAL_NUMBER_OF_CARDS 52 //Maximum Number of Cards in the game
#define ARGUMENT_ONE 1 //First Parameter
#define ARGUMENT_TWO 2 //Second Parameter
#define ONE_CHAR_INPUT 1 //Used to count the char of input
#define TWO_CHAR_INPUT 2 //Used to count the char of input
#define TWO_DIGIT_MAX 2 //Max two digit parameter
#define MAXIMUM_ARGUMENT 3 //Max amount of arguments
#define CARDDECKSIZE 53 //Total Size of the card array
#define SUM_ONE 1 //Used in operation of Straight
#define CARD_ONE 0 //first card in the deck
#define CARD_TWO 1 //second card in the deck
#define CARD_THREE 2 //third card in the deck
#define CARD_FOUR 3 //forth card in the deck
#define CARD_FIVE 4 //fifth card in the deck

#define RESULT_HIGH_CARD 0 //result of a high card
#define RESULT_ONE_PAIR 1 //result of one pair
#define RESULT_TWO_PAIR 2 //result of two pairs
#define RESULT_THREE_OF_A_KIND 3 //result of three of a kind
#define RESULT_OF_A_STRAIGHT 4 //result of a straight
#define RESULT_OF_A_FLUSH 5 //result of a flush
#define RESULT_OF_A_FULL_HOUSE 6 //result of a full house
#define RESULT_OF_A_FOUR_OF_KIND 7 //result of four of a kind
#define RESULT_OF_A_STRAIGHT_FLUSH 8 //result of a straight flush

#define HAND_ONE 0 //Testing hand one
#define HAND_TWO 1 //Testing hand two
#define HAND_THREE 2 //Testing hand three
#define HAND_FOUR 3 //Testing hand four
#define HAND_FIVE 4 //Testing hand five
#define HAND_SIX 5 //Testing hand six
#define HAND_SEVEN 6 //Testing hand seven
#define HAND_EIGHT 7 //Testing hand eight
#define HAND_NINE 8 //Testing hand nine

#define NUMBER_OF_HANDS 9 //Total Testing hands

enum suitsConstants {HEARTS = 0, DIAMONDS, CLUBS, SPADES};
enum facesConstants {A = 0, TWO, THREE, FOUR, FIVE, SIX,
        SEVEN, EIGHT, NINE, TEN, J, Q, K};

//Struct used to save each card
struct card
{
        int rank;
        int suit;
};

typedef struct card Card;

//Struct used to save each hand
struct hand
{
        Card handGiven[FIVE_POKER_CARDS];
        int rankInPoker;
};

typedef struct hand Hand;

/*----------------Function prototypes-------------------------- **/
int validateInput (int argc, char *argv[]);
int checkArgumentCount(int argc);
int checkInputLength(char *argv[]);
int checkStringToInt(char *argv[]);
int checkNumberRange(char *argv[]);
void messageToPrintForError ();
void explainTheLegend(const char SUITSARRAY[SUITS],
                       const char RANKARRAY[FACES]);
void populateDeckOfCards(Card deck[]);
int whatCard (int cardInTheDeck);
int whatSuit (int cardInDeck);
void printDeckOfCards (Card mdeck[], const char SUITSARRAY[],
                       const char RANKARRAY[]);
void shuffle (Card deck []);
void swap (Card *currentPosition, Card *newPosition);
void createTheHands(Hand handPerPlayer[], Card deck[CARDDECKSIZE],
                                const int playersInTheGame);
void printTheHands(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES],const int numberOfPlayers);
void insertionSort(Hand handPerPlayer[], const int playersToSort);
int highCard(Hand handProvided);
int isItOnePair (Hand handProvided);
int isItTwoPair (Hand handProvided);
int isItThreeOfAKind (Hand handProvided);
int isItAStraight (Hand handProvided);
int isItAFlush (Hand handProvided);
int isItAFullHouse (Hand handProvided);
int isItFourOfAKind (Hand handProvided);
int straightFlush(Hand handProvided);
void printResults(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES],const int numberOfPlayers);
void classificationOfHands (Hand *handsAtTable);
void printWinner(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES],const int numberOfPlayers);
int determineAWinner (Hand handPerPlayer[], const int numberOfPlayers);
void printRankMessage(Hand handsAtTable);
void assignRanks (Hand playersInTheGame[], const int players);
void pokerTest (Hand pokerHands[]);
void printTestingHands(Hand pokerHands[], const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES]);


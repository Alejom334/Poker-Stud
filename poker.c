/*=============================================================================$
|   Source File: poker.c
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #4 Poker Stud
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [10/29/2019], at the beginning of class
|
|   Description: This source file hold the functions for creating 
|                the deck of card structs, printing this deck of
|                card structs, dealing hands, shuffling the hands,
|                classifyng the hands, determining winners, analyzing
|                pre-dertemined hands.
|
|       Note: To have more detailed of each function please refer to 
|           the individual documentation of each function.

=============================================================================$*/



#include <stdio.h>
#include "cardConstants.h" //Hearder file for constants and func prototypes

/*------ explainTheLegend(const char SUITSARRAY[SUITS],-------------
                       const char RANKARRAY[FACES])
|   Function void explainTheLegend(const char SUITSARRAY[SUITS],
|                       const char RANKARRAY[FACES])
|
|   Purpose:  This function explains the legend of the cards.
|
|   Explanation: This function will be using the enums in the header
|                file
|
|    @param suits[], char,  array of suits
|            face[], char,  array of face
|
|    @return  none
*-------------------------------------------------------------------*/

void explainTheLegend(const char SUITSARRAY[SUITS],
                       const char RANKARRAY[FACES])
{
    printf("\n%s\n", "The legend is as follows: ");
    printf("\tSuits: Hearts = '%c', Diamonds: '%c', Clubs: '%c', "
           " and Spades: '%c' \n" , SUITSARRAY[HEARTS],
           SUITSARRAY[DIAMONDS], SUITSARRAY[CLUBS],
           SUITSARRAY[SPADES]);
    printf("\tRanks: Ace='%c', Two='%c', Three='%c', Four='%c',"
           " Five='%c', Six='%c'\n \t  Seven='%c', Eight='%c', Nine='%c',"
           " Ten='%c', Jack='%c', Queen='%c', King='%c'\n",
           RANKARRAY[A], RANKARRAY[TWO], RANKARRAY[THREE],
           RANKARRAY[FOUR], RANKARRAY[FIVE], RANKARRAY[SIX],
           RANKARRAY[SEVEN],RANKARRAY[EIGHT], RANKARRAY[NINE],
           RANKARRAY[TEN], RANKARRAY[J],RANKARRAY[Q], RANKARRAY[K]);

}

/*-------void populateDeckOfCards(Card deck[CARDDECKSIZE])------------
|   Function void populateDeckOfCards(Card deck[CARDDECKSIZE])
|
|   Purpose:  This function will populate an array of Card structs
|
|   Explanation: Started the array at index COUNTER_1 (1), as it in
|               later functions it will be easier to manipulate to
|               print the order array of structs
|
|               Recall that the struct of cards he have has
|               a rank and a suit.
|
|    @param deck[CARDDECKSIZE], Card, this is the array of structs
|
|    @return  none
*-------------------------------------------------------------------*/
void populateDeckOfCards(Card deck[CARDDECKSIZE])
{
    int counter = 0;
    int rankNum = 0;
    int suitNum = 0;
    for (counter = COUNTER_ONE; counter <= TOTAL_NUMBER_OF_CARDS; counter++)
    {
        rankNum = whatCard(counter);
        suitNum = whatSuit(counter);
        deck[counter].rank = rankNum;
        deck[counter].suit = suitNum;
    }
    printf("%s\n", "");
    printf("%s","Original Ordered Deck:");
}

/*-void printDeckOfCards (Card mdeck[], const char SUITSARRAY[SUITS],--
                       const char RANKARRAY[FACES])
|
|   Function void printDeckOfCards (Card mdeck[],
|                        const char SUITSARRAY[SUITS],
|                                const char RANKARRAY[FACES])
|
|   Purpose:  This function will print the array of structs using
|               the constant arrays of suits and ranks defined at the
|               main.
|
|               This will be the genereic function used to print all
|               the cards.
|
|   Explanation: Started the array at index COUNTER_1 (1), as it in
|               later functions it will be easier to manipulate to
|               print the order array of structs
|
|               Recall that the struct of cards he have has
|               a rank and a suit.
|
|    @param deck[CARDDECKSIZE], Card, this is the array of structs
|    @param SUITSARRAY[SUITS], const char, constant array of suits
|    @param RANKARRAY[FACES], const char, constant array of ranks
|
|    @return  none
*-------------------------------------------------------------------*/

void printDeckOfCards (Card mdeck[], const char SUITSARRAY[SUITS],
                       const char RANKARRAY[FACES])
{
        int counter = 0;
        int outsideCounter = 0;
        int rankNumber = 0;
        int suitNumber = 0;
        int printCounter = 0;

        printf("%s\n", "");

        for (counter = COUNTER_ONE; counter <= CARDS; counter++)
        {
                rankNumber = mdeck[counter].rank;
                suitNumber = mdeck[counter].suit;
                printf("[%c-", RANKARRAY[rankNumber]);
                printf("%c] ", SUITSARRAY[suitNumber]);
                printCounter++;
                if (printCounter == FACES)
                {
                        puts("");
                        printCounter = 0;
                }
        }
}


/*---------- whatCard (int cardInTheDeck) ------------------------
|   Function int whatCard (int cardInTheDeck)
|
|   Purpose:  This function will return the index of what card
|               to pick in the faces array.
|
|    @param cardInTheDeck, int, card in the deck array
|
|    @return  actualIndexInFaceArray, int, index in constant face
|                                           array.
*-------------------------------------------------------------------*/
int whatCard (int cardInTheDeck)
{
    int actualIndexInFaceArray = 0;
    int indexOfCardArray = 0;
    indexOfCardArray = cardInTheDeck % FACES;

    if (indexOfCardArray == 0)
    {
        actualIndexInFaceArray = FACES - COUNTER_ONE;
        return actualIndexInFaceArray;
    }
    else
    {
        actualIndexInFaceArray = indexOfCardArray - COUNTER_ONE;
        return  actualIndexInFaceArray;
    }

}

/*---------- whatSuit (int cardInDeck)) ------------------------
|   Function int whatSuit (int cardInDeck)
|
|   Purpose:  This function will return the index of what suit
|               to pick in the suit array.
|
|    @param cardInTheDeck, int, card in the deck array
|
|    @return  suitNumber, int, index in constant suit array.
*-------------------------------------------------------------------*/
int whatSuit (int cardInDeck)
{
    int suitNumber = 0;

    if (cardInDeck <= CARD_BOUND_THIRTEEN)
    {
     	suitNumber = HEARTS;
        return  suitNumber;
    }
    else if (cardInDeck > CARD_BOUND_THIRTEEN &&
             cardInDeck <= CARD_BOUND_TWENTYSIX)
    {
     	suitNumber = DIAMONDS;
        return  suitNumber;
    }
    else if (cardInDeck > CARD_BOUND_TWENTYSIX &&
             cardInDeck <=CARD_BOUND_THIRTYNINE)
    {
     	suitNumber = CLUBS;
        return  suitNumber;
    }
    else
    {
     	suitNumber = SPADES;
        return  suitNumber;
    }
}

/* -------------------void shuffle(Card deck[])--------------------------
|   Function void shuffle (Card deck [])
|
|   Purpose:  The purpose of this function is to shuffle the deck of Cards.
|
|   Explanation:
|           1. Here we used the srandom(time(NULL))defined in main
|               to generate a seed that really is random, as it is attached to
|               time.
|           2. We loop through our original array of cards and we
|              shuffle the array with this seed generated using the
|              formula:
|              randomLocation = COUNTER_ONE + (rand() % CARDS);
|              To know more about the procedure of creating a
|              a random seed the link below will show:
|
|https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
|
|           3. Function swap is used to swap the element random and the
|               iterating element
|
|    @param deck[CARDDECKSIZE], Card, this is the array of structs
|
|    @return  none
*-------------------------------------------------------------------*/

void shuffle (Card deck [])
{

    unsigned int counter = 0;
    int randomLocation = 0;
    int cardInTheDeck = 0;
    int printCounter = 0;
    int indexOfConstantArrayOfFaces = 0;
    int indexOfConstantArrayOfSuits = 0;

    for (counter = COUNTER_ONE; counter <= CARDS; counter++)
    {
        randomLocation = COUNTER_ONE + (rand() % CARDS);
        swap(&deck[counter], &deck[randomLocation]);
    }
    printf("%s\n", "");
    printf("%s","Random Shuffle Deck: ");
}


/*----swap (int *currentPosition, int *newPosition)-------------
|
|   Function void swap (int *currentPosition, int *newPosition)
|
|   Purpose:  The purpose of this function is swap the pointers.
|
|    @param  *currentPosition, int*, index of for loop array
|            *newPosition, int*, index of random position.
|
|    @return  none
*----------------------------------------------------------------*/

void swap (Card *currentPosition, Card *newPosition)
{
    Card temporaryPosition = *currentPosition;
    *currentPosition = *newPosition;
    *newPosition = temporaryPosition;
}

/* ---------------------------------------------------------------------
|   void createTheHands (Hand handPerPlayer[], Card deck[CARDDECKSIZE],
|                                const int playersInTheGame)
|
|   Function void createTheHands (Hand handPerPlayer[],
|                                       Card deck[CARDDECKSIZE],
|                                               const int playersInTheGame)
|
|   Purpose:  The purpose of this function is create the array of hands
|               that the game will have.
|
|   Explanation:
|               - Loop through the total number of players
|               - In each player crete the hand
|               - The cards come from the shuffle array
|
|    @param  handPerPlayer[], Hand, struct of hands
|    @param  deck[CARDDECKSIZE], Card, array of structs
|    @param  playersInTheGame, const int, number of players in the game
|
|    @return  none
*-------------------------------------------------------------------*/

void createTheHands (Hand handPerPlayer[], Card deck[CARDDECKSIZE],
                                const int playersInTheGame)
{

    int counter = 0;
    int nestedCounter = 0;
    int deckCounter = COUNTER_ONE;

    for (counter = 0; counter < playersInTheGame; counter++)
    {
        for (nestedCounter = 0;
             nestedCounter < FIVE_POKER_CARDS; nestedCounter++)
        {
                handPerPlayer[counter].handGiven[nestedCounter]
                                = deck[deckCounter];
                deckCounter++;
        }
    }
    printf("%s\n", "");
    printf("%s\n", "Player Hand: (dealt from top/front of deck)");
}


/* ---------------------------------------------------------------------
|   void printTheHands(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
|                const char RANKARRAY[FACES],const int numberOfPlayers)
|
|   Function void printTheHands(Hand handPerPlayer[],
|                               const char SUITSARRAY[SUITS],
|                                       const char RANKARRAY[FACES],
|                                               const int numberOfPlayers)
|
|   Purpose:  The purpose of this function is to print the hands in the
|               hand array.
|
|   Explanation:
|               - Loop through the total number of players
|               - Inside Loop of total number of cards
|               - Use constant arrays to print the actual cards
|
|    @param  handPerPlayer[], Hand, struct of hands
|    @param SUITSARRAY[SUITS], const char, constant array of suits
|    @param RANKARRAY[FACES], const char, constant array of ranks
|    @param  playersInTheGame, const int, number of players in the game
|
|    @return  none
*-------------------------------------------------------------------*/
void printTheHands(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES],const int numberOfPlayers)
{
        int counter = 0;
        int insideCounter = 0;
        int rankNumber = 0;
        int suitNumber = 0;
        int printCounter = 0;

        for(counter = 0; counter < numberOfPlayers; counter++)
        {
                printf("%s %2d ", "Player", counter + COUNTER_ONE);

                for (insideCounter = 0; insideCounter < FIVE_POKER_CARDS;
                        insideCounter++)
                {
                    rankNumber = handPerPlayer[counter].
                                        handGiven[insideCounter].rank;
                    suitNumber = handPerPlayer[counter].
                                        handGiven[insideCounter].suit;

                    printf("[%c-", RANKARRAY[rankNumber]);
                    printf("%c] ", SUITSARRAY[suitNumber]);
                    printCounter++;
                    if (printCounter == (FIVE_POKER_CARDS))
                    {
                        puts("");
                        printCounter = 0;
                    }
                }
        }
}

/* ---------------------------------------------------------------------
|   void insertionSort(Hand handPerPlayer[], const int playersToSort)
|
|   Function void insertionSort(Hand handPerPlayer[],
|                                       const int playersToSort)
|
|   Purpose:  The purpose of this function was to sort the Hands
|
|   Explanation:
|               Insertion sort was used to sort the hand array.
|               The source used to guide the insertion sort
|               procedure was from the following sources:
|
|               https://www.geeksforgeeks.org/insertion-sort/
|
|               https://courses.cs.vt.edu/~csonline/Algorithms
|                       /Lessons/InsertionSort/index.html
|
|   Procedure of the Insertion Sort According to Documentation:
|
|               - Get a list of unsorted numbers
|               - Set a marker for the sorted section after
|                 the first number in the list
|               - Repeat steps 4 through 6 until the unsorted
|                 section is empty.
|               - Select the first unsorted number.
|               - Swap this number to the left until it arrives at
|                 the correct sorted position.
|               - Advance the marker to the right one position
|               - Stop
| 
|
|    @param  handPerPlayer[], Hand, struct of hands
|    @param  playersInTheGame, const int, number of players in the game
|
|    @return  none
*-------------------------------------------------------------------*/

void insertionSort(Hand handPerPlayer[], const int playersToSort)
{
    int counter = 0;

    int insideCounter1 = 0;

    int insideCounter2 = 0;

    Card key;

    for (counter = 0; counter < playersToSort; counter++)
    {
        for (insideCounter1 = COUNTER_ONE; insideCounter1 < FIVE_POKER_CARDS;
                insideCounter1++)
        {
               key = handPerPlayer[counter].handGiven[insideCounter1];

               insideCounter2 = insideCounter1 - COUNTER_ONE;

               while (insideCounter2 >= 0 &&
               handPerPlayer[counter].handGiven[insideCounter2].rank >
                                                                key.rank)
               {
                        handPerPlayer[counter].handGiven[insideCounter2 +
                                                                COUNTER_ONE]
                                = handPerPlayer[counter].
                                                handGiven[insideCounter2];
                        insideCounter2 = insideCounter2 - COUNTER_ONE;
               }

               handPerPlayer[counter].handGiven[insideCounter2 + COUNTER_ONE]
                                                                         = key;
        }
    }

    printf("%s\n", "");
    printf("%s\n", "Player Hand: sorted");
}


/* ---------------------highCard(Hand handProvided)--------------------
|
|   Function int highCard(Hand handProvided)
|
|   Purpose:  This is a default function for the classification of
|              hands. If none of the classification of pairs is true,
|              then this concept will apply.
|
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having a high
|           card is as follows:
|           "Any hand that does not qualify under the categories
|           listed. In the event of a tie, the highest card wins,
|           such as “ace-high”"
|
|    IMPORTANT NOTE: These cards can be compared as the algorithm
|                   above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE, int, depending if is ever called.
*-------------------------------------------------------------------*/

int highCard(Hand handProvided)
{
    return TRUE;
}

/* ------------------isItOnePair (Hand handProvided)--------------------
|
|   Function int isItOnePair (Hand handProvided)
|
|   Purpose:  The purpose of this function is to classify if the
|               hand is a pair or not.
|
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having a pair 
|           is as follows:
|           "Two cards of matching rank, and three unrelated side cards. 
|           In the event of a tie, the highest pair wins the pot."
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|           
|           - Method will receive the hand to classify
|           - Assign the rank value of each card to an int
|           - As we happened to have sorted cards the following 
|             algorithm will apply:
|               * If CardOne is equal to CardTwo and the rest of the
|                 the cards are not the same then we have a pair.
|               * If CardTwo is equal to CardThree and the rest of the
|                 the cards are not the same then we have a pair.
|               * If CardThree is equal to CardFour and the rest of the
|                 the cards are not the same then we have a pair.
|               * If CardFour is equal to CardFive and the rest of the
|                 the cards are not the same then we have a pair.
|           - If none of this conditions are met then we do not have a
|             a pair.
|   
|    IMPORTANT NOTE: These cards can be compared as the algorithm 
|                   above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/

int isItOnePair (Hand handProvided)
{
    int cardOne = handProvided.handGiven[CARD_ONE].rank;
    int cardTwo = handProvided.handGiven[CARD_TWO].rank;
    int cardThree = handProvided.handGiven[CARD_THREE].rank;
    int cardFour = handProvided.handGiven[CARD_FOUR].rank;
    int cardFive = handProvided.handGiven[CARD_FIVE].rank;

    if ((cardOne == cardTwo) && (cardTwo != cardThree) &&
        (cardThree != cardFour) && (cardFour != cardFive))
    {
        return TRUE;
    }//end of if

    else if ((cardTwo == cardThree) && (cardOne != cardTwo) &&
        (cardThree != cardFour) && (cardFour != cardFive))
    {
        return TRUE;
    }//end of else if

    else if ((cardThree == cardFour) && (cardOne != cardTwo) &&
        (cardTwo != cardThree) && (cardFour != cardFive))
    {
        return TRUE;
    }//end of else if

    else if ((cardFour == cardFive) && (cardOne != cardTwo) &&
        (cardTwo != cardThree) && (cardThree != cardFour))
    {
        return TRUE;
    }//end of else if

    else
    {
        return FALSE;
    }//end of else
}


/* ------------------isItTwoPair (Hand handProvided)--------------------
|
|   Function int isItTwoPair (Hand handProvided)
|
|   Purpose:  The purpose of this function is to classify if the
|               hand has to two pairs or not
|
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having two pairs 
|           is as follows:
|           "Two cards of matching rank, two cards of different 
|            matching rank, and one side card. In the event of a tie, 
|            the highest pair wins"
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|           
|           - Method will receive the hand to classify.
|           - Assign the rank value of each card to an int.
|           - As we happened to have sorted cards the following. 
|             algorithm will apply:
|               * If CardOne is equal to CardTwo, and CardThree is
|                 equal to CardFour and CardFive is not equal to 
|                 CardFour and CardThree is not equal to CardTwo,
|                 we have two distinct pairs.
|               * If CardTwo is equal to CardThree, and CardFour is
|                 equal to CardFive and CardOne is not equal to 
|                 CardTwo and CardThree is not equal to CardFour,
|                 we have two distinct pairs.
|
|           - If none of this conditions are met then we do not have a
|             two pairs.
|
|           IMPORTANT NOTE: These cards can be compared as the
|               algorithm above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/

int isItTwoPair (Hand handProvided)
{
    int cardOne = handProvided.handGiven[CARD_ONE].rank;
    int cardTwo = handProvided.handGiven[CARD_TWO].rank;
    int cardThree = handProvided.handGiven[CARD_THREE].rank;
    int cardFour = handProvided.handGiven[CARD_FOUR].rank;
    int cardFive = handProvided.handGiven[CARD_FIVE].rank;

    if ((cardOne == cardTwo) && (cardThree == cardFour) &&
        (cardFour != cardFive) && (cardTwo != cardThree))
    {
        return TRUE;
    }//end of if

    else if ((cardTwo == cardThree) && (cardFour == cardFive) &&
        (cardOne != cardTwo) && (cardThree != cardFour))
    {
        return TRUE;
    }//end of else if

    else
    {
        return FALSE;
    }//end of else
}

/* -------------isItThreeOfAKind (Hand handProvided)-------------------
|
|   Function int isItThreeOfAKind (Hand handProvided)
|
|   Purpose:  The purpose of this function is to classify if the
|               hand has three of a kind
|
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having three of 
|           a kind is as follows:
|           "Three cards of the same rank, and two unrelated side cards. 
|            In the event of a tie, the highest ranking three of a kind 
|            wins."
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|
|
|           Scenarios of the Algorithm to be true:
|
|           (For simplicity, numbers will be used in the following 
|            explanation for the reader)
|   
|           1. As we have sorted cards, the first three cards could be
|               the same, and the following two are different.
|           2. As we have sorted cards, cards #2 #3 #4 coudl be the
|               the smae, and the card #1 and #5 are different.
|           3. As we have sorted cards, cards #3, #4, #5 are the same
|               and cards #1 and #2 are different.
|           
|           - Method will receive the hand to classify.
|           - Assign the rank value of each card to an int.
|           - As we happened to have sorted cards the following. 
|             algorithm will apply:
|               * If CardOne is equal to CardTwo, and CardTwo is
|                 equal to CardThree and CardThree is not equal to 
|                 CardFour and CardFour is not equal to CardFive,
|                 we have three of a kind.
|               * If CardTwo is equal to CardThree, and CardThree is
|                 equal to CardFour and CardOne is not equal to 
|                 CardTwo and CardFour is not equal to CardFive,
|                 we have three of a kind.
|               * If CardThree is equal to CardFour, and CardFour is
|                 equal to CardFive and CardOne is not equal to 
|                 CardTwo and CardTwo is not equal to CardThree,
|                 we have three of a kind.
|
|           - If none of this conditions are met then we do not have a
|             three cards of the same kind.
|
|           IMPORTANT NOTE: These cards can be compared as the
|               algorithm above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/

int isItThreeOfAKind (Hand handProvided)
{
    int cardOne = handProvided.handGiven[CARD_ONE].rank;
    int cardTwo = handProvided.handGiven[CARD_TWO].rank;
    int cardThree = handProvided.handGiven[CARD_THREE].rank;
    int cardFour = handProvided.handGiven[CARD_FOUR].rank;
    int cardFive = handProvided.handGiven[CARD_FIVE].rank;

    if ((cardOne == cardTwo) && (cardTwo == cardThree) &&
        (cardThree != cardFour) && (cardFour != cardFive))
    {
        return TRUE;
    }//end of if

    else if ((cardTwo == cardThree) && (cardThree == cardFour) &&
        (cardOne != cardTwo) && (cardFour != cardFive))
    {
        return TRUE;
    }//end of else if

    else if ((cardThree == cardFour) && (cardFour == cardFive) &&
        (cardOne != cardTwo) && (cardTwo != cardThree))
    {
        return TRUE;
    }//end of else if

    else
    {
        return FALSE;
    }//end of else
}


/* -------------isItAStraight (Hand handProvided)-------------------
|
|   Function int isItAStraight (Hand handProvided)
|
|   Purpose:  The purpose of this hand is classify if the hand
|             is a straight.
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having a 
|           straight is as follows:
|
|           "Five non-suited cards in sequence. In the event 
|            of a tie, the highest ranking card at the top of the 
|            sequence wins."
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|
|           Scenarios of the Algorithm to be true:
|
|           (For simplicity, numbers will be used in the following 
|            explanation for the reader)
|   
|           1. As we have sorted cards, the algorithm will compare
|              if the following card equals the previous card 
|              plus one.
|           
|           - Method will receive the hand to classify.
|           - Assign the rank value of each card to an int.
|           - As we happened to have sorted cards the following. 
|             algorithm will apply:
|               * If CardTwo is equal to CardOne plus one, 
|                 and CardThree is equal to CardTwo plus one,
|                 and CardFour is equal to CardThree plus one,
|                 and CardFive is equal to CardFour plus one,
|                 return True, and we have a straight.
|
|           - If none of this conditions are met then we do not have a
|             a straight.
|
|           IMPORTANT NOTE: These cards can be compared as the
|               algorithm above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/
int isItAStraight (Hand handProvided)
{
    int cardOne = handProvided.handGiven[CARD_ONE].rank;
    int cardTwo = handProvided.handGiven[CARD_TWO].rank;
    int cardThree = handProvided.handGiven[CARD_THREE].rank;
    int cardFour = handProvided.handGiven[CARD_FOUR].rank;
    int cardFive = handProvided.handGiven[CARD_FIVE].rank;

    if ((cardTwo == (cardOne + SUM_ONE)) &&
        (cardThree == (cardTwo + SUM_ONE)) &&
        (cardFour == (cardThree + SUM_ONE)) &&
        (cardFive == (cardFour + SUM_ONE)))
    {
        return TRUE;
    }

    else if ( (cardOne == TEN) && (cardTwo == J) && (cardThree == Q)
                && (cardFour == K) && (cardFive == A) )
    {
        return TRUE;
    }

    else
    {
        return FALSE;
    }
}


/* -------------isItAFlush (Hand handProvided)-------------------
|
|   Function int isItAFlush (Hand handProvided)
|
|   Purpose:  The purpose of this hand is classify if the hand
|             is a flush.
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having a 
|           flush is as follows:
|
|           "Five cards of the same suit, not in sequence. In the 
|            event of a tie, the player holding the highest ranked 
|            card wins."
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|
|           Scenarios of the Algorithm to be true:
|
|           (For simplicity, numbers will be used in the following 
|            explanation for the reader)
|   
|           1. Comparing if the suit number of the cards is the 
|              same. If that is the case then we have a flush
|           
|           - Method will receive the hand to classify.
|           - Assign the suit value of each card to an int.
|           - As we happened to have sorted cards the following. 
|             algorithm will apply:
|               * If CardOne is equal to CardTwo, 
|                 and CardTwo is equal to CardThree,
|                 and CardThree is equal to CardFour,
|                 and CardFour is equal to CardFive,
|                 return True, and we have a flush.
|
|           - If none of this conditions are met then we do not have a
|             a flush.
|
|           IMPORTANT NOTE: These cards can be compared as the
|               algorithm above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/
int isItAFlush (Hand handProvided)
{
    int cardOne = handProvided.handGiven[CARD_ONE].suit;
    int cardTwo = handProvided.handGiven[CARD_TWO].suit;
    int cardThree = handProvided.handGiven[CARD_THREE].suit;
    int cardFour = handProvided.handGiven[CARD_FOUR].suit;
    int cardFive = handProvided.handGiven[CARD_FIVE].suit;

    if ((cardOne == cardTwo) &&
        (cardTwo == cardThree) &&
        (cardThree == cardFour) &&
        (cardFour == cardFive))
    {
        return TRUE;
    }//end of if
    else
    {
        return FALSE;
    }//end of else
}

/* -------------isItAFullHouse (Hand handProvided)----------------
|
|   Function int isItAFullHouse(Hand handProvided)
|
|   Purpose:  The purpose of this hand is classify if the hand
|             is a full house.
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having a 
|           flush is as follows:
|
|           "Three cards of the same rank, and two cards of a 
|            different, matching rank. In the event of a tie, 
|            the highest three matching cards wins."
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|
|           Scenarios of the Algorithm to be true:
|   
|           1. If we have both a three of a kind and one pair
|               we have a full house
|           
|           - Method will receive the hand to classify.
|           - If the methods isItOnePair(handProvided) && 
|              isItThreeOfAKind(handProvided) return True then we
|              have a full house.
|
|           - If none of this conditions are met then we do not have a
|             a full house.
|
|           IMPORTANT NOTE: These cards can be compared as the
|               algorithm above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/

int isItAFullHouse (Hand handProvided)
{
    if ((isItOnePair(handProvided)) &&
                        (isItThreeOfAKind(handProvided)))
    {
        return TRUE;
    }//end of if

    else
    {
        return FALSE;
    }//end of else
}

/* -------------isItFourOfAKind (Hand handProvided)-------------------
|
|   Function int isItFourOfAKind (Hand handProvided)
|
|   Purpose:  The purpose of this function is to classify if the
|               hand has four of a kind
|
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having three of 
|           a kind is as follows:
|           "Four cards of the same rank, and one side card or ‘kicker’. 
|            In the event of a tie, the highest four of a kind wins."
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|
|           Scenarios of the Algorithm to be true:
|
|           (For simplicity, numbers will be used in the following 
|            explanation for the reader)
|   
|           1. As we have sorted cards, if the rank of card #1, #2,
|               #3, #4 are the same then we have a full house.
|           2. As we have sorted cards, if the rank of card #2, #3,
|               #4, #5 are the same then we have a full house.
|           
|           - Method will receive the hand to classify.
|           - Assign the rank value of each card to an int.
|           - As we happened to have sorted cards the following. 
|             algorithm will apply:
|               * If CardOne is equal to CardTwo, and CardTwo is
|                 equal to CardThree and CardThree is equal to 
|                 CardFour and CardFour is not equal to CardFive,
|                 we have four of a kind.
|               * If CardTwo is equal to CardThree, and CardThree is
|                 equal to CardFour and CardFour is equal to 
|                 CardFive and CardOne is not equal to CardTwo,
|                 we have four of a kind.
|
|           - If none of this conditions are met then we do not have a
|             four cards of the same kind.
|
|           IMPORTANT NOTE: These cards can be compared as the
|               algorithm above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/

int isItFourOfAKind (Hand handProvided)
{
    int cardOne = handProvided.handGiven[CARD_ONE].rank;
    int cardTwo = handProvided.handGiven[CARD_TWO].rank;
    int cardThree = handProvided.handGiven[CARD_THREE].rank;
    int cardFour = handProvided.handGiven[CARD_FOUR].rank;
    int cardFive = handProvided.handGiven[CARD_FIVE].rank;

    if ((cardOne == cardTwo) && (cardTwo == cardThree) &&
        (cardThree == cardFour) && (cardFour != cardFive))
    {
        return TRUE;
    }//end of if

    else if ((cardTwo == cardThree) && (cardThree == cardFour) &&
        (cardFour == cardFive) && (cardOne != cardTwo))
    {
        return TRUE;
    }//end of else if

    else
    {
        return FALSE;
    }//end of else
}


/* -------------straightFlush(Hand handProvided)----------------
|
|   Function int isItAFullHouse(Hand handProvided)
|
|   Purpose:  The purpose of this hand is classify if the hand
|             is a straight flush.
|
|   Sources: https://www.pokerstars.net/poker/
|
|   Explanation:
|           According to poker stars, the definition of having a 
|           flush is as follows:
|
|           "Five cards in sequence, of the same suit. In the 
|            event of a tie, the highest rank at the top of the 
|            sequence wins."
|
|           Due that we only have to compare five cards the 
|           following algorithm will be addressed:
|
|           Scenarios of the Algorithm to be true:
|   
|           1. If function isItAStaright(handProvided) and
|               isItAFlush(handProvided) are true then we have
|               a straight flush.
|           
|           - Method will receive the hand to classify.
|           - If the methods isItAStaright(handProvided) && 
|              isItAFlush(handProvided) return True then we
|              have a straight flush.
|
|           - If none of this conditions are met then we do not have a
|             a straight flush.
|
|           IMPORTANT NOTE: These cards can be compared as the
|               algorithm above explains due that they are sorted.
|
|    @param  handProvided, Hand, hand to analyze
|
|    @return  TRUE or FALSE, int, depending if condition is met.
*-------------------------------------------------------------------*/

int straightFlush(Hand handProvided)
{
    if(isItAStraight(handProvided) &&
        isItAFlush(handProvided))
    {
        return TRUE;
    }

    else
    {
        return FALSE;
    }
}

/* ---------------------------------------------------------------------
|   printResults(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
|                const char RANKARRAY[FACES],const int numberOfPlayers)
|
|   Function void printResults(Hand handPerPlayer[],
|                                  const char SUITSARRAY[SUITS],
|                                         const char RANKARRAY[FACES],
|                                               const int numberOfPlayers)
|
|   Purpose:  The purpose of this function is to print the hands in the
|               hand array with their respective results
|
|   Explanation:
|               - Loop through the total number of players
|               - Inside Loop of total number of cards
|               - Use constant arrays to print the actual cards
|               - After going through each hand print the result
|
|    @param  handPerPlayer[], Hand, struct of hands
|    @param SUITSARRAY[SUITS], const char, constant array of suits
|    @param RANKARRAY[FACES], const char, constant array of ranks
|    @param  playersInTheGame, const int, number of players in the game
|
|    @return  none
*-------------------------------------------------------------------*/

void printResults(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES],const int numberOfPlayers)
{
        int counter = 0;
        int insideCounter = 0;
        int rankNumber = 0;
        int suitNumber = 0;
        int printCounter = 0;


        printf("%s\n", " ");
        printf("%s\n", "Players Hands: ranked");
        for(counter = 0; counter < numberOfPlayers; counter++)
        {
                printf("%s %2d ", "Player", counter + COUNTER_ONE);

                for (insideCounter = 0; insideCounter < FIVE_POKER_CARDS;
                        insideCounter++)
                {
                    rankNumber = handPerPlayer[counter].
                                        handGiven[insideCounter].rank;
                    suitNumber = handPerPlayer[counter].
                                        handGiven[insideCounter].suit;

                    printf("[%c-", RANKARRAY[rankNumber]);
                    printf("%c] ", SUITSARRAY[suitNumber]);
                    printCounter++;
                    if (printCounter == (FIVE_POKER_CARDS))
                    {
                        printRankMessage(handPerPlayer[counter]);
                        puts("");
                        printCounter = 0;
                    }
                }
        }
}


/* -----------classificationOfHands(Hand *handsAtTable)-----------------
|
|   Function void classificationOfHands(Hand *handsAtTable)
|
|   Purpose:  The purpose of this function is to populate the poker rank
|             number in each hand calling the nine states a hand
|             can be at. Then print the state
|
|   Explanation:
|
|           Due that we only have to compare nine cases the
|           following algorithm will be addressed:
|
|           - Method will receive the hand to classify through a pointer
|           - If any of the eight conditions stated above is true
|              the rankInPoker varibale will recieve a number.
|           - If the hand does not qualify for any of the eight given
|             states then we provide the defaulr state high card.
|
|
|    @param  *handProvided, Hand, hand to analyze
|
|    @return  none.
*-------------------------------------------------------------------*/
void classificationOfHands (Hand *handsAtTable)
{
    if (straightFlush(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_OF_A_STRAIGHT_FLUSH;
    }
    else if (isItFourOfAKind(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_OF_A_FOUR_OF_KIND;
    }
    else if (isItAFullHouse(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_OF_A_FULL_HOUSE;
    }
    else if (isItAFlush(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_OF_A_FLUSH;
    }
    else if (isItAStraight(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_OF_A_STRAIGHT;
    }
    else if (isItThreeOfAKind(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_THREE_OF_A_KIND;
    }
    else if (isItTwoPair(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_TWO_PAIR;
    }
    else if(isItOnePair(*handsAtTable))
    {
        (*handsAtTable).rankInPoker = RESULT_ONE_PAIR;
    }
    else
    {
        (*handsAtTable).rankInPoker = RESULT_HIGH_CARD;
    }
}


/* printWinner(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
|        const char RANKARRAY[FACES],const int numberOfPlayers)----------
|
|   Function void printWinner(Hand handPerPlayer[],
|                   const char SUITSARRAY[SUITS],
|                            const char RANKARRAY[FACES],
|                                    const int numberOfPlayers)
|
|   Purpose:  The purpose of this fucnction is print the winner of
|               the game according to the poker rank each hand has.
|               Recall that we could have multiple winners in a game.
|
|   Explanation:
|               - Loop through the total number of players
|               - Inside Loop of total number of cards
|               - Use constant arrays to print the actual cards
|               - After going through each hand print the result
|               - If the player matches the highest rank called in 
|                 method determine a winner. The 'winner' will print.
|
|    @param  handPerPlayer[], Hand, struct of hands
|    @param SUITSARRAY[SUITS], const char, constant array of suits
|    @param RANKARRAY[FACES], const char, constant array of ranks
|    @param  playersInTheGame, const int, number of players in the game
|
|    @return  none
*-------------------------------------------------------------------*/


void printWinner(Hand handPerPlayer[],const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES],const int numberOfPlayers)
{
        int counter = 0;
        int insideCounter = 0;
        int rankNumber = 0;
        int suitNumber = 0;
        int printCounter = 0;

        int winnerInTable = determineAWinner(handPerPlayer, numberOfPlayers);
        printf("%s\n", "");
        printf("%s\n", "Players Hands: winners(s)");

        for(counter = 0; counter < numberOfPlayers; counter++)
        {
                printf("%s %2d ", "Player", counter + COUNTER_ONE);

                for (insideCounter = 0; insideCounter < FIVE_POKER_CARDS;
                        insideCounter++)
                {
                    rankNumber = handPerPlayer[counter].
                                        handGiven[insideCounter].rank;
                    suitNumber = handPerPlayer[counter].
                                        handGiven[insideCounter].suit;

                    printf("[%c-", RANKARRAY[rankNumber]);
                    printf("%c] ", SUITSARRAY[suitNumber]);
                    printCounter++;
                    if (printCounter == (FIVE_POKER_CARDS))
                    {
                        printRankMessage(handPerPlayer[counter]);

                        if(winnerInTable == handPerPlayer[counter].rankInPoker)
                        {
                            printf("%s", " - Winner");
                        }
                        puts("");
                        printCounter = 0;
                    }
                }
        }
}

/* -determineAWinner (Hand handPerPlayer[], const int numberOfPlayers)-
|
|   Function int determineAWinner (Hand handPerPlayer[], 
|                                   const int numberOfPlayers)
|
|   Purpose:  The purpose of this function is to go through all the poker
|               ranks to see who was a winner.
|
|
|   Explanation:
|
|               - Loop thorough each hand and compare the pokerRank
|               - As the poker ranks are compared. The one with the
|                   highest number is stored.
|
|    @param  handPerPlayer[], Hand, array of hands 
|    @param  numberOfPlayers, int, total number if players
|
|    @return  winner, int, max poker rank number.
*-------------------------------------------------------------------*/

int determineAWinner (Hand handPerPlayer[], const int numberOfPlayers)
{
    int counter = 0;

    int winner = 0;

    for (counter = 0; counter < numberOfPlayers; counter++)
    {
        if (handPerPlayer[counter].rankInPoker > winner)
        {
            winner = handPerPlayer[counter].rankInPoker;
        }    
    }

    return winner;    
}

/* -----------printRankMessage(Hand handsAtTable)-----------------
|
|   Function void printRankMessage(Hand handsAtTable)
|
|   Purpose:  This function will print the poker rank classification
|
|   Explanation:
|
|       - Assign to an int the poker rank
|       - Compare it to the 9 different outcomes and state message
|
|
|    @param  handsAtTable, Hand, each hand given
|
|    @return  none.
*-------------------------------------------------------------------*/


void printRankMessage(Hand handsAtTable)
{
    int pokerRank = handsAtTable.rankInPoker;

    if (pokerRank == RESULT_ONE_PAIR)
    {
        printf("%s", " - One Pair");
    }
    else if (pokerRank == RESULT_TWO_PAIR)
    {
        printf("%s", " - Two Pair");
    }
    else if (pokerRank == RESULT_THREE_OF_A_KIND)
    {
        printf("%s", " - Three of a Kind");
    }
    else if (pokerRank == RESULT_OF_A_STRAIGHT)
    {
        printf("%s", " - Straight");
    }
    else if (pokerRank == RESULT_OF_A_FLUSH)
    {
        printf("%s", " - Flush");
    }
    else if (pokerRank == RESULT_OF_A_FULL_HOUSE)
    {
        printf("%s", " - Full House");
    }
    else if (pokerRank == RESULT_OF_A_FOUR_OF_KIND)
    {
        printf("%s", " - Four of a Kind");
    }
    else if (pokerRank == RESULT_OF_A_STRAIGHT_FLUSH)
    {
        printf("%s", " - Straight Flush");
    }
    else
    {
        printf("%s", " - High Card");
    }
}
/*----- assignRanks(Hand playersInTheGame[], const int players)----------
|
|   Function void assignRanks (Hand playersInTheGame[], 
|                                       const int players)
|
|   Purpose:  The purpose of this function is act as the brain of the 
|               classifying hands. 
|
|   Explanation:
|
|               - Loop thorough each hand 
|               - Call function classificationOfHands passing a pointer
|                  to each hand.
|
|    @param  handPerPlayer[], Hand, array of hands 
|    @param  numberOfPlayers, int, total number if players
|
|    @return  none.
*-------------------------------------------------------------------*/

void assignRanks (Hand playersInTheGame[], const int players)
{
    int counter = 0;

    for (counter = 0; counter < players; counter++)
    {
        classificationOfHands(&playersInTheGame[counter]);
    }
}


/* -----------pokerTest(Hand pokerHands[])---------------------------
|
|   Function void pokerTest(Hand pokerHands[])
|
|   Purpose:  The purpose of this function assign the hand values to
|               an array of testing hands created in the main
|
|   Explanation:
|
|           - This Hands were explicitily typed from the 
|               specifications. 
|           - Assign each hand to each valued of the array.
|
|
|    @param  pokerHands[], Hand, Array of hands
|
|    @return  none.
*-------------------------------------------------------------------*/

void pokerTest (Hand pokerHands[])
{
        Hand firstHand = {{{TWO, DIAMONDS}, {3,CLUBS},
                {4,DIAMONDS},{6, SPADES}, {Q, HEARTS}}};

        Hand secondHand = {{{FOUR, HEARTS}, {FIVE,HEARTS},
                {FIVE, DIAMONDS},{SEVEN, HEARTS}, {TEN,SPADES}}};

        Hand thirdHand = {{{THREE, DIAMONDS}, {THREE,HEARTS},
                {TEN, CLUBS},{TEN, DIAMONDS}, {Q, CLUBS}}};

        Hand fourHand = {{{THREE, DIAMONDS}, {THREE,HEARTS},
                {THREE, SPADES},{TEN, DIAMONDS}, {Q, CLUBS}}};

        Hand fifthHand = {{{A, SPADES}, {TWO,DIAMONDS},
                {THREE,CLUBS},{FOUR, DIAMONDS},{FIVE,DIAMONDS}}};

        Hand sixthHand = {{{TWO, CLUBS}, {THREE,CLUBS},
                {FOUR, CLUBS},{SIX, CLUBS}, {Q, CLUBS}}};

        Hand sevenHand = {{{THREE, DIAMONDS}, {THREE,HEARTS},
                {THREE, SPADES},{TEN, DIAMONDS}, {TEN, CLUBS}}};

        Hand eightHand = {{{THREE, DIAMONDS},{THREE,HEARTS},
                {THREE, SPADES},{THREE, SPADES}, {Q, CLUBS}}};

        Hand nineHand = {{{TEN, DIAMONDS}, {J,DIAMONDS},
                {Q, DIAMONDS},{K, DIAMONDS}, {A, DIAMONDS}}};

        pokerHands[HAND_ONE] = firstHand;

        pokerHands[HAND_TWO] = secondHand;

        pokerHands[HAND_THREE] = thirdHand;

        pokerHands[HAND_FOUR] = fourHand;

        pokerHands[HAND_FIVE] = fifthHand;

        pokerHands[HAND_SIX] = sixthHand;

        pokerHands[HAND_SEVEN] = sevenHand;

        pokerHands[HAND_EIGHT] = eightHand;

        pokerHands[HAND_NINE] = nineHand;

}


/* -------- printTestingHands(Hand pokerHands[], ----------------------
|                    const char SUITSARRAY[SUITS],
|                                const char RANKARRAY[FACES])
|
|   Function void printTestingHands(Hand pokerHands[], 
|                       const char SUITSARRAY[SUITS],
|                               const char RANKARRAY[FACES])
|
|   Purpose:  The purpose of this fucnction is print the testing hands
|                of with their required rank type.
|
|   Explanation:
|               - Loop through the total number of hands
|               - Assign a poker rank throught a classification of 
|                   hands function.
|               - Loop throught the total number of hands again
|               - Loop through each card to print them
|               - Print the rank number name.
|
|    @param  handPerPlayer[], Hand, struct of hands
|    @param SUITSARRAY[SUITS], const char, constant array of suits
|    @param RANKARRAY[FACES], const char, constant array of ranks
|    @param  playersInTheGame, const int, number of players in the game
|
|    @return  none
*-------------------------------------------------------------------*/

void printTestingHands(Hand pokerHands[], const char SUITSARRAY[SUITS],
                const char RANKARRAY[FACES])
{
    int counter = 0;
    int insideCounter = 0;
    int rankNumber = 0;
    int suitNumber = 0;
    int printCounter = 0;

    for (counter = 0; counter < NUMBER_OF_HANDS; counter++)
    {
        classificationOfHands(&pokerHands[counter]);
    }

    printf("%s\n", "");
    printf("%s\n", "PokerHands: test");

    for(counter = 0; counter < NUMBER_OF_HANDS; counter++)
    {
        printf("%s", "Hands:  ");

                for (insideCounter = 0; insideCounter < FIVE_POKER_CARDS;
                        insideCounter++)
                {
                    rankNumber = pokerHands[counter].
                                        handGiven[insideCounter].rank;
                    suitNumber = pokerHands[counter].
                                        handGiven[insideCounter].suit;

                    printf("[%c-", RANKARRAY[rankNumber]);
                    printf("%c] ", SUITSARRAY[suitNumber]);
                    printCounter++;
                    if (printCounter == (FIVE_POKER_CARDS))
                    {
                        printRankMessage(pokerHands[counter]);
                        puts("");
                        printCounter = 0;
                    }

                }
        }
}











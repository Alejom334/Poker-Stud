/*=============================================================================$
|   Source File: inputValidation.c 
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #4 Poker Stud
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [10/29/2019], at the beginning of class
|
|   Description: This source file will hold all the user validaiton 
|				 functions. The user validation functions will 
|				 prevent the program to crash if the user inputs 
|				 any input that is not the correct one. The program
|				 will exit stating a message in the console with the
|				 required instructions. 
|
|				 The required user input is as follows:
|
|				 1. Input will come from the command line as:
|				 	./pokerHand 5 9
|				 	As it can be seen there are 3 inputs. Any other
|				 	input amount will exit the program
|				 2. Input cannot be a character or string.
|				 3. First input should be the number of cards that 
|				    should always be '5' and the second input is the
|				    number of players ranging from [0-10]
|				 4. If the user inputs something else not withtin
|				    the parameter stated the program will exit.
|
|	Explanation of Libraries and Special Functions 
|	(header file will contain will contain these libraries)
|			
|			<string.h> used for strlen function checkInputLength(char *argv[])
|			Refer to function for explanation of function strlen.
|
|			<stdlib.h> used for atoi at checkNumberRange(char *argv[])
|			Refer to function for explanation of function atoi
|
|			<ctype.h> //used for isdigit at checkStringToInt (char *argv[])
|			Refer to function for explanation of function isdigit
=============================================================================$*/



#include <stdio.h>
#include <stdlib.h> //used for atoi at checkNumberRange(char *argv[])
#include <string.h> //used for strlen at checkInputLength (char *argv[])
#include <ctype.h> //used for isdigit at checkStringToInt (char *argv[])
#include "cardConstants.h" //Library of Constants 

/*------ validateInput (int argc, char *argv[]) ----------------
|   Function int validateInput (int argc, char *argv[])
|
|   Purpose:  This function will call functions checkArgument,
|			  checkInputLength, checkStringToInt, checkNumberRange.
|
|   Explanation: If all of these functions stated in the above
|			  comment are return TRUE. Then this function will 
|			  return true. Else it will return false.
|
|    @param  argc, int, total amount of input from the command line
|            argv[], char*, pointer to array of command line
|
|    @return  int, TRUE or FALSE, returns true or false depending 
|			  if the other functions called are true.
*------------------------------------------------------------*/

int validateInput (int argc, char *argv[])
{
        if( checkArgumentCount(argc) &&
                checkInputLength(argv) &&
                checkStringToInt (argv)&&
                checkNumberRange(argv))
        {
                return TRUE;
        }
	else
	{
                return FALSE;
        }
}

/*------------------checkArgumentCount(int argc)---------------------
|   Function int checkArgumentCount(int argc)
|
|   Purpose:  The purpose of this function is to count the number of
|			  inputs.
|
|   Explanation: Parameter argc coming from main returns the number 
|				 of inputs from the command line. If inputs equal to
|				 three then it returns true. Otherwise, it will
|				 return false.
|
|    @param  argc, int, total amount of input from the command line
|
|    @return  int, TRUE or FALSE, returns true or false depending 
|				if this check was valid or not
*-------------------------------------------------------------------*/

int checkArgumentCount(int argc)
{
        if (argc == MAXIMUM_ARGUMENT)
        {
                return TRUE;
        }
	else
	{
                return FALSE;
        }
}

/*------------------checkInputLength (char *argv[])-------------------
|   Function int checkInputLength (char *argv[])
|
|   Purpose:  The purpose of this function is count the number of
|			  chars that an input has.
|
|   Explanation: This function will return true if the number of
|				 chars is one or two in both inputs.
|				
|				 The function strlen from library <string.h> is being
|				 used to count the number of chars in an string.
|
|    @param  argv, char*, pointer to the first index of array argv
|
|    @return  int, TRUE or FALSE, returns true or false depending 
|				if this check was valid or not
*-------------------------------------------------------------------*/

int checkInputLength (char *argv[])
{
        int stringLength = 0;
        int counter = 0;

        for (counter = COUNTER_ONE; counter < MAXIMUM_ARGUMENT; counter++)
        {
                stringLength = strlen (argv[counter]);

                if (stringLength < ONE_CHAR_INPUT ||
                                        stringLength > TWO_CHAR_INPUT)
                {
                        return FALSE;
                }
        }

	return TRUE;

}

/*------------------checkStringToInt (char *argv[])-------------------
|   Function int checkStringToInt (char *argv[])
|
|   Purpose:  The purpose of this function is to check if the user 
|			  input a character or an integer.
|
|   Explanation: This function will return true if characters are 
|				 integers or false is they are not.
|				
|				 The function isdigit() is used from the <ctype.h>.
|				 This function tell us if the character is an integer
|				 or not. We are loopingg through the string until
|				 we encounter the '\0' or end of string character.
|
|    @param  argv, char*, pointer to the first index of array argv
|
|    @return  int, TRUE or FALSE, returns true or false depending 
|				if this check was valid or not
*-------------------------------------------------------------------*/

int checkStringToInt (char *argv[])
{
        int counter = 0;
        int counter2 = 0;
        int isDigitResult1 = 0;
        int isDigitResult2 = 0;

        while (argv[ARGUMENT_ONE][counter] != '\0')
        {
                isDigitResult1 = isdigit(argv[ARGUMENT_ONE][counter]);

                if (!isDigitResult1)
                {
                        return FALSE;
                }

                counter++;
        }

	while (argv[ARGUMENT_TWO][counter2] != '\0')
        {
                isDigitResult2 = isdigit(argv[ARGUMENT_TWO][counter2]);

                if (!isDigitResult2)
                {
                        return FALSE;
                }

                counter2++;
        }

	return TRUE;
}

/*------------------checkNumberRange(char *argv[])-------------------
|   Function int checkNumberRange(char *argv[])
|
|   Purpose:  The purpose of this function is to check if the numbers
|			  entered are in the correct range.
|
|   Explanation: This function will return true if characters are 
|				 integers that are in the specified range:
|				
|				 Input One = [One - Thirteen] Then changed to 5
|				 Input Two = [two-ten]
|				
|				 The function atoi from library <stdlib.h> is being
|				 used to convert the strings into integer numbers.
|				 
|
|    @param  argv, char*, pointer to the first index of array argv
|
|    @return  int, TRUE or FALSE, returns true or false depending 
|				if this check was valid or not
*-------------------------------------------------------------------*/

int checkNumberRange(char *argv[])
{
        int numberOfCards = atoi(argv[ARGUMENT_ONE]);
        int numberOfPlayers = atoi(argv[ARGUMENT_TWO]);

        if ((numberOfCards >= CARD_BOUND_ONE) &&
                (numberOfCards <= CARD_BOUND_THIRTEEN)&&
                ((numberOfPlayers >= TWO_PLAYERS) &&
                 (numberOfPlayers <= TEN_PLAYERS)) &&
                 (numberOfPlayers*numberOfCards <= TOTAL_NUMBER_OF_CARDS))
        {
           return TRUE;
        }

        else
    {
           return FALSE;
        }

}


/*--------------------messageToPrintForError() ----------------------
|   Function void messageToPrintForError()
|
|   Purpose:  The purpose of this function is to print the parameters
|			  of user input validation if the user does not have
|			  a correct input. 
|
|    @param  none
|
|    @return  none
*-------------------------------------------------------------------*/
void messageToPrintForError ()
{
        printf("%s\n", "------------------------ERROR----------------------");
        printf("%s\n","Error! As stated in the documentation of this");
        printf("%s\n","program. The user input should have the");
        printf("%s\n","following parameters:");
        printf("%s\n","1. You must have two inputs besides the ./pokerHand");
        printf("%s\n","   For Example, ./pokerHand 5 10.");
        printf("%s\n","2. You must not input characters or strings.");
        printf("%s\n","3. Your inputs should consist on the number of cards");
        printf("%s\n","   and the number of players.");
        printf("%s\n","4. First input will be converted to 5");
        printf("%s\n","5. The second input should be the number of players.");
        printf("%s\n","   The number of players should range from [2-10].");
        printf("%s\n","Run the program again following these parameters.");
        printf("%s\n","Thank you for playing poker with us !");
        printf("%s\n", "---------------------------------------------------");
}






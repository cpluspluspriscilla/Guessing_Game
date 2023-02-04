#ifndef GUESSINGGAME_H
#define GUESSINGGAME_H

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

class GuessingGame
{
      private:
        //random number that will be guessed
        int randomNum;
        //most current user guess
        int userGuess;
        //stores user's score
        int UserScore;
        //stores CPU's score
        int CPUScore;


    public:
        //Constructor
        GuessingGame();

        //stores user's first entry within the Options() function and determines which function is called afterwards.
        int firstEntry;
        //stores user's chosen difficulty level which in turn either sets the CPU's guess limit or quits the game
        int Difficulty;
        //stores the number of times the CPU can guess the random number
        int GuessLimit;
        //stores up to 20 of the CPU's random guesses in an array
        int CPUGuess[20];
        //stores the status of whether the correct number has been guessed
        string CorrectOrNot;
        //stores the status of whether the user wants to quit or continue playing
        int quit;
        //stores the status of whether the game has began for the first time or not.
        int beginning;


        /***************************************************
        * @pre  GuessingGame Class has been initialized
        * @post Options functions is called
        ***************************************************/
        void Welcome();


        /**************************************************
        @post beginning variable has been incremented by 1,
                user has entered a valid firstEntry, function
                calls Quit, GetDifficulty, or Scoreboard.
        ***************************************************/
        void Options();


        /**********************************************
        @pre  firstEntry is 1.
        @post user has entered a valid Difficulty,
                if Difficulty is 4, Quit function is called,
                if Difficulty is 1-3 GuessLimit has been set,
                NewRandomNumber() generates random number,
                UserGuessNumber() is called.
        *********************************************/
        void GetDifficulty();


        /************************************************
        @pre  Difficulty is 1-3.
                GuessLimit has been stored.
        @post New random number is generated
                and stored in randomNum.
        *************************************************/
        void newRandomNumber();


         /************************************************
        @pre userGuess is not equal to randomNum
                and userGuess is not equal to 0
        @post Random numbers are generated a number of
                times that is equal to the GuessLimit.
                If the correct number is guessed,
                the CPU's score is incremented by 1 using
                IncrementScore() and control is passed to the
                Options() function. If the number is not guessed
                by the CPU, it is then the user's turn and
                control is passed to the UserGuessNumber() function.
        ********************************************/
        void CPUGuessNumber();


        /********************************************************
          @pre  Difficulty and GuessLimit has been set.
          @post userGuess is validated using ValidateEntry().
                If userGuess equals 0, Quit() is called.
                If userGuess is not equal to randomNum, CPUGuessNumber() is called.
                If userGuess is equal to randomNum, the user's score is incremented
                by 1 using IncrementScore() and control is passed to the Options() function.
        *************************************************************/
        void UserGuessNumber();


        /**********************************************************************
           @pre An invalid entry has been entered for one of the following
                variables: firstEntry, Difficulty, userGuess, or quit.
        @post An "Invalid Entry!" message has been displayed to the
                user and control is passed back to of the following functions
                for the invalid entry to be corrected, respectively:
                Options(), GetDifficulty(), UserGuessNumber(), Quit().
        ***********************************************************************/
        void ValidateEntry();


        /***************************************************************************
        * @pre Either the CPU or the user has guessed the randomNum correctly.
        * @post Either the CPU or the user's score has been incremented by 1.
        *****************************************************************************/
        void IncrementScore();


       /***********************************************************
         @pre   firstEntry equals 2.
         @post  The user's score and the CPU's score has been displayed.
                If quit equals 1, control is passed to the Options() function.
                If quit equals 2, control is passed to the Quit() function.
        ****************************************************************/
        void Scoreboard();


        /****************************************************************
           @pre Either firstEntry = 3, Difficulty = 4, quit = 2, or userGuess = 0.
          @post if quit equals 2, control is passed to the Options() function.
                If quit equals 1, the winner of the game is displayed and the program is terminated.
        ********************************************************************/
        void Quit();




};

#endif // GUESSINGGAME_H

#include "GuessingGame.h"

GuessingGame::GuessingGame()
{
     {
    //INITALIZE THE FOLLOWING VARIABLES SO THEY MAY BE USED IN THE PROGRAM
    randomNum = 0;
    userGuess = 1;
    UserScore = 0;
    CPUScore = 0;
    beginning = 0;
    }
}



void GuessingGame::Welcome()
    {
    //OUTPUT WELCOME MESSAGE TO USER
    cout << "*************WELCOME TO THE CSC GAMES!*************" << endl;
    //PASS CONTROL TO Options().
    Options();
    }

    void GuessingGame::Options()
    {
    //OUTPUT MENU OPTIONS TO USER
    cout << "***********************MENU************************" << endl;
    cout << "Guessing Game . . . . . . press 1" << endl;
    cout << "Scoreboard . . . . . . .  press 2" << endl;
    cout << "Quit . . . . . . . . . .  press 3" << endl;
    cout << "***************************************************" << endl;

    //GET USER'S INPUT AND STORE IN firstEntry.
    cin >> firstEntry;

    if (firstEntry < 1 || firstEntry > 3) //IF firstEntry IS NOT BETWEEN 1 AND 3
    ValidateEntry();                     //PASS CONTROL TO ValidateEntry().

    if (firstEntry == 3) //IF firstEntry IS 3
    Quit();             //PASS CONTROL TO Quit().

    if (firstEntry == 1) //IF firstEntry IS 1
    GetDifficulty();    //PASS CONTROL TO GetDifficulty().

    if (firstEntry == 2) //IF firstEntry IS 2
    Scoreboard();        //PASS CONTROL TO Scoreboard().
    }

    void GuessingGame::GetDifficulty()
    {
        //OUTPUT DIFFICULTY OPTIONS TO USER
    cout << "********************DIFFICULTY*********************" << endl;
    cout << "Easy Peasy! (5 Guesses) . . . . . . . . . press 1" << endl;
    cout << "Challenging! (10 Guesses) . . . . . . . . press 2" << endl;
    cout << "Nearly Impossible! (20 Guesses) . . . . . press 3" << endl;
    cout << "Quit . . . . . . . . . . . . . . . . . .  press 4" << endl;
    cout << "***************************************************" << endl;
    //GET USER'S INPUT AND STORE IN Difficulty.
    cin >> Difficulty;

    //IF Difficulty IS NOT BETWWEN 1 AND 4 PASS CONTROL TO ValidateEntry().
    if (Difficulty < 1 || Difficulty > 4)
    ValidateEntry();

        //IF Difficulty IS EQUAL TO 1, SET GuessLimit TO 5.
         if (Difficulty == 1)
            GuessLimit = 5;

        //IF Difficulty IS EQUAL TO 2, SET GuessLimit TO 10.
         if (Difficulty == 2)
            GuessLimit = 10;

        //IF Difficulty IS EQUAL TO 3, SET GuessLimit TO 20.
         if (Difficulty == 3)
            GuessLimit = 20;

        //IF Difficulty IS EQUAL TO 4, PASS CONTROL TO Quit().
         if (Difficulty == 4)
            Quit();

    //GENERATE NEW RANDOM NUMBER USING newRandomNumber().
    newRandomNumber();

    //BEGIN USER'S TURN TO GUESS NUMBER USING UserGuessNumber().
    UserGuessNumber();
    }

    void GuessingGame::Scoreboard()
    {
    //OUTPUT USER'S SCORE AND CPU'S SCORE
    cout << "*******************SCOREBOARD**********************" << endl;
    cout << "Your Score: " << UserScore << "pts" << endl;
    cout << "CPU Score: " << CPUScore << "pts" << endl;
    cout << "***************************************************" << endl << endl;

    //ASK USER IF THEY WOULD LIKE TO CONTINUE PLAYING
    cout << "***************************************************" << endl;
    cout << "Would you like to continue playing?" << endl;
    cout << "Return To Menu . . . . . . . . . . . . press 1" << endl;
    cout << "Quit . . . . . . . . . . . . . . . . . press 2" << endl;
    cout << "***************************************************" << endl;
    //GET USER'S INPUT AND STORE IN quit.
    cin >> quit;

    //IF quit EQUALS 1, PASS CONTROL TO Options().
    if (quit == 1)
    Options();

    //IF quit EQUALS 1, PASS CONTROL TO Quit().
    if (quit == 2)
    Quit();
    }

    void GuessingGame::UserGuessNumber()
    {
    //PROMPT USER TO GUESS A NUMBER OR QUIT GAME
    cout << "******************YOUR TURN************************" << endl;
    cout << "Pick a number between 1-100: " << endl;
    cout << "Quit . . . . . . . . . press 0" << endl;
    cout << "***************************************************" << endl;

    //STORE THE USER'S INPUT IN userGuess
    cin >> userGuess;

    //IF userGuess is 0, PASS CONTROL TO Quit().
    if (userGuess == 0)
        Quit();

    //IF userGuess is GREATER THAN 100, PASS CONTROL TO ValidateEntry().
    if (userGuess > 100)
    ValidateEntry();

    //IF userGuess IS NOT EQUAL TO randomNum and userGuess IS NOT 0
    if (userGuess != randomNum && userGuess != 0)
    {
       //IF userGuess IS GREATER THAN randomNum and userGuess IS NOT 0
       if (userGuess > randomNum && userGuess != 0)

       //OUTPUT "TOO HIGH" AND BEGIN CPU'S TURN BY PASSING CONTROL TO CPUGuessNumber().
       {cout << "Too High!" << endl;
       cout << "***************************************************" << endl;
       CPUGuessNumber();}

       //IF userGuess IS LESS THAN randomNum and userGuess IS NOT 0
       if (userGuess < randomNum && userGuess != 0)

       //OUTPUT "TOO LOW" AND BEGIN CPU'S TURN BY PASSING CONTROL TO CPUGuessNumber().
       {cout << "Too Low!" << endl;
       cout << "***************************************************" << endl;
       CPUGuessNumber();}
    }

    //IF userGuess IS EQUAL TO randomNum and userGuess IS NOT 0
    if (userGuess == randomNum && userGuess != 0)

    //OUTPUT "CORRECT" AND INCREMENT USER'S SCORE BY 1 BY PASSING CONTROL TO IncrementScore().
    {cout << "Correct!" << endl;
    IncrementScore();
    cout << "***************************************************" << endl;

    //RETURN TO MENU OPTIONS BY PASSING CONTROL TO Options().
    Options();}
    return;
    }

    void GuessingGame::ValidateEntry()
    {
    //IF firstEntry IS LESS THAN 1 OR GREATER THAN 3
    if (firstEntry < 1 || firstEntry > 3)

    //OUTPUT "INVALID ENTRY" AND PASS CONTROL BACK TO Options() FOR A VALID ENTRY.
     {cout << "Invalid Entry!" << endl << endl;
     Options();}

     //IF Difficulty IS LESS THAN 1 OR GREATER THAN 4
     if (Difficulty < 1 || Difficulty > 4)

     //OUTPUT "INVALID ENTRY" AND PASS CONTROL BACK TO GetDifficulty() FOR A VALID ENTRY.
     {cout << "Invalid Entry!" << endl << endl;
     GetDifficulty();}

     //IF userGuess IS LESS THAN 1 OR GREATER THAN 100
     if (userGuess < 1 || userGuess > 100)

     //OUTPUT "INVALID ENTRY" AND PASS CONTROL BACK TO UserGuessNumber() FOR A VALID ENTRY.
     {cout << "Invalid Entry!" << endl << endl;
     UserGuessNumber();}

     //IF quit IS LESS THAN 1 OR GREATER THAN 2
     if (quit < 1 || quit > 2)

     //OUTPUT "INVALID ENTRY" AND PASS CONTROL BACK TO Quit() FOR A VALID ENTRY.
     {cout << "Invalid Entry!" << endl << endl;
     Quit();}

    }

    void GuessingGame::newRandomNumber()
    {
        //GENERATE RANDOM NUMBER AND STORE IN randomNum
        srand(time(0));
        randomNum = rand()%100;

        //IF RANDOM NUMBER GENERATED is 0, INCREMENT BY 1
        if (randomNum == 0)
            randomNum = randomNum + 1;
    }
    void GuessingGame::CPUGuessNumber()
    {
        cout << endl <<  "***********************CPU TURN********************" << endl;
        srand(time(NULL));

        //FOR LOOP TO GENERATE N AMOUNT OF GUESSES IN WHICH N REPRESENTS THE GuessLimit
        for (int i = 0; i < GuessLimit; i++ )
        {
        CPUGuess[i] = rand()%100;
        }

        //FOR LOOP TO DETERMINE WHETHER EACH OF THE CPU'S GUESSES EQUAL randomNum
        //FOR LOOP IS TERMINATED BY ITERATIONS EQUALING GuessLimit OR CORRECT NUMBER BEING GUESSED BY THE CPU
        for (int i = 0; i < GuessLimit || CorrectOrNot == "Correct"; i++ )
        {
        //IF THE NTH CPUGuess DOES NOT EQUAL randomNum
        if (CPUGuess[i] != randomNum)

        //SET CorrectOrNot TO "INCORRECT", OUTPUT CPUGuess, AND OUTPUT STATUS OF CorrectOrNot
        {CorrectOrNot = "Incorrect";
        cout << "CPU guess: " << setw(2) << CPUGuess[i] << setw(2) << " . . . . " << CorrectOrNot << endl;}

        //IF THE NTH CPUGuess DOES EQUAL randomNum
        if (CPUGuess[i] == randomNum)

        //SET CorrectOrNot TO "CORRECT", OUTPUT CPUGuess, AND OUTPUT STATUS OF CorrectOrNot
        {CorrectOrNot = "Correct";
        cout << "CPU guess: " << setw(2) << CPUGuess[i] << setw(2) << " . . . . " << CorrectOrNot << endl;

        //IF THE NTH CPUGuess DOES EQUAL randomNum, INCREMENT CPU'S SCORE USING IncrementScore().
         if (CPUGuess[i] == randomNum)
        {IncrementScore();
        cout << "***************************************************" << endl << endl;

        //RETURN TO MENU OPTIONS BY PASSING CONTROL TO Options().
        Options();}
        break;
        break;}
        }

        //IF CorrectOrNot EQUALS "INCORRECT", BEGIN USER'S TURN BY PASSING CONTROL TO UserGuessNumber().
        if (CorrectOrNot == "Incorrect")
        {cout << "***************************************************" << endl << endl;
        UserGuessNumber();}
    }

    void GuessingGame::IncrementScore()
    {
    //IF CorrectOrNot EQUALS "CORRECT" INCREMENT CPUScore BY 1
     if (CorrectOrNot == "Correct")
        CPUScore = CPUScore + 1;

    //IF userGuess EQUALS randomNum INCREMENT UserScore BY 1
     if (userGuess == randomNum)
        UserScore = UserScore + 1;
    }

    void GuessingGame::Quit()
    {
        //OUTPUT PROMPT TO ABORT QUIT PROCESS
        cout << "***************************************************" << endl;
        cout << setw(27) <<  "Leaving already?" << endl;
        cout << "Yes . . . . . . . . . . . . press 1" << endl;
        cout << "No  . . . . . . . . . . . . press 2" << endl;
        cout << "***************************************************" << endl;

        //GET USER'S INPUT AND STORE IN quit.
        cin >> quit;


        if (quit < 1 || quit > 2) //IF quit IS LESS THAN 1 OR GREATER THAN 2
        ValidateEntry();         //PASS CONTROL TO ValidateEntry().

        if (quit == 2) //IF quit IS EQUALS 2
        Options(); //PASS CONTROL TO Options().

        //IF quit EQUALS 1, OUTPUT WINNER TO USER
        if (quit == 1)
        {cout << "***************************************************" << endl;

        //IF UserScore IS GREATER THAN CPUScore OUTPUT USER AS THE WINNER
        if (UserScore > CPUScore)
        cout << setw(30) << " You won! You're a guessing whiz!" << endl;

        //IF UserScore IS LESS THAN CPUScore OUTPUT CPU AS THE WINNER
        if (UserScore < CPUScore)
        cout << setw(30) << "You lost! Better luck next time!" << endl;

        //IF UserScore IS EQUAL TO CPUScore OUTPUT A TIE.
        if (UserScore == CPUScore)
        cout << setw(35) << "It's a tie! You're just as good as the computer!" << endl;

        //OUTPUT GOODBYE MESSAGE TO USER
        cout<<setw(44) << "Thank you for playing the Guessing Game!" << endl;
        cout<<setw(30) << "Come back soon!" << endl;


        cout << "***************************************************" << endl;}

        //TERMINATE PROGRAM
        exit(0);
        abort();
    }

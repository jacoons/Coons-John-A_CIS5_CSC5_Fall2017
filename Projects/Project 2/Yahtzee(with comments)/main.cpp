#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

// Function declarations sum() is called each game to determine who 
//in a group of players starts. rollDie() is called for each dice roll.
int sum(long t2);
int rollDie(long t2);  
void info();
void title();
void instructions(); 

int main(int argc, char* argv[])
{  
       
   // Create random number generator seeder
   time_t t;
   time(&t);    
   long t2 = static_cast<long> (t);
   srand(t2);
  
   // vector for final list of scores <scores, name>
   vector<pair<int, string> > playerScores;
   title();
   instructions();   

   // Game loop. Initialize playAgain to "Y" to start game. At the end of the 
   //game, user may select Y to restart the game or "N" to end the game.
   string playAgain = "Y";
   while(playAgain == "Y")
   {
       // Prompt for, and input number of players
       int numOfPlayers = 0;
       cout << "\n\n\tPlease enter the number of players for this game(1-4): ";
       cin >> numOfPlayers;
      
       // If player(s) have entered invalid number of players, prompt to enter 
       //again.
       while((numOfPlayers >= 5) || (numOfPlayers <= 0))
       {      
           cout << "\n\tSorry, but only 1 to 4 people may play in a game.";
           cout << "\n\tPlease enter the number of players for this game "
                   "(1-4): ";
           cin >> numOfPlayers;
       }

       // Create vector to store current player's names
       vector<string> names;
      
       // If this is a solo game.
       if(numOfPlayers == 1)
       {
           string name;
         
           cout << "\n\tPlease enter your name: ";
           cin >> name;
           names.push_back(name);
       }
      
       // If playing with group of people (no more than four)
       else if(numOfPlayers > 1)
       {
           // Users enter okay when ready to roll for who starts. string 
           //message used to ensure user enters OK correctly.
           string message;
          
           // Explains initial roll situation to players.
           cout << "\n\tTo determine which player will go first, each player "
                   "rolls all 5 die.";
           cout << "\n\tThe player with the highest total sum will start the "
                   "game.";
           cout << "\n\n\tEach player select a number between 1 and " 
                   << numOfPlayers << ".";
           cout << "\n\tRemember your number. Each player's roll is determined "
                   "by their number.";
           cout << "\n\n\tType 'OK' when each player has a number: ";
           cin >> message;
  
           // If players have entered anything other than ok or OK
           while((message != "OK") && (message != "ok"))
           {
               cout << "\n\tType 'OK' when ready: ";
               cin >> message;
           }

           // Create vector to store and sort each player's initial role. 
           //Vector is destroyed upon exit of if statement.
           vector<int> initRolls;
           // For loop calls sum() function, prints the return, and
           //adds an element and assigns the roll to the vector.
           for(int i = 0; i < numOfPlayers; i++)
           {          
               int firstRoll = sum(t2);
               cout << "\n\tNumber " << (i+1) << "'s sum of the initial roll "
                       "is: " << firstRoll;
               initRolls.push_back(firstRoll);
           }
              
           // Sort initial rolls and compare two highest rolls to ensure there 
           //was not a tie for who goes first.
           sort(initRolls.rbegin(), initRolls.rend());
              
           // while loop compares the two highest rolls. If there is a tie, 
           //initiates a re-roll.
           while(initRolls[0] == initRolls[1])
           {
               // Clears first rolls, informs players of the tie.
               initRolls.clear();
               cout << "\n\tThere is a tie, re-rolling die. "
                       "(Remember your number!)";
               // For loop re-rolls dice.
               for(int i = 0; i < numOfPlayers; i++)
               {
                   int firstRoll = sum(t2);
                   cout << "\n\tNumber " << (i+1) << "'s sum of the initial "
                           "roll is: " << firstRoll;
                   initRolls.push_back(firstRoll);
               }
           }

           // Prompts for names in a multiplayer game in order that turns will 
           //be played. Stores each name in vector "names."
           cout << "\n\n\tEnter name(s) in the order they take their turn." 
                   << endl;
           for(int i = 0; i < numOfPlayers; i++)
           {
               string name;
               cout << "\n\n\tPlease enter player " << (i+1) << "'s name: ";
               cin >> name;
               names.push_back(name);
           }
       }  
                  
       /*       
       * Arrays track player's score. scoreComb ensures player cannot enter
       * score into same score category more than once,
       * and combPoints stores the points for each category.
       * For loop and nested For loop initialize arrays, and set all categories 
       * to false, or unused for each player, and to -1 (1-4).
       */
       bool scoreComb[4][13];
       int combPoints[4][13];
           for(unsigned int j = 0; j < 4; j++)  
           {
               for(unsigned int k = 0; k < 13; k++)
               {              
                   scoreComb[j][k] = false;                  
                   combPoints[j][k] = 0;
               }
           }

       // bool array Yahtzee bonus is applied if the player scores a Yahtzee 
       //bonus. If true when score is tallied, the score will add 100 points.
       bool yahtzeeBonus[4];
       for(unsigned int i = 0; i > 4; i++)
       {
           yahtzeeBonus[i] = 0;
       }
              
       // Define number of rounds in a game. Start round counter at 1 before 
       //starting player's turns.
       const int MAX_ROUNDS = 13;
       int round = 1;
  
       // While loop ensures the game ends when it is supposed to, at the end 
       //of 13 rounds.
       while(round <= MAX_ROUNDS)
       {
           // For loop cycles through each player for every round. Each loop 
           //is a player's turn.              
           for(int i = 0; i < numOfPlayers; i ++)
           {
               // "keepers" used to determine which dice are held, and which 
               //to re-roll.
               // create array of int, or 'dice,' for the game to use.
               string keepers;
               int die[5];
               cout << "\n\n\n\n\t\t       ***** It is " << names[i] 
                       << "'s turn.*****" << endl;
               cout << "\n\n\t\t        Your first rolls are: \n\n";
  
               // for loop calls rollDie() function and iterates through all 
               //dice to create first roll.
               for(int j = 0; j < 5; j++)
               {
                   die[j] = rollDie(t2);
               }
              
               // Print player's first roll, prompts user to enter 5 characters
               //consisting of 1s or 0s based on the dice he/she wishes to hold.
               cout << "\t\t        " << die[0] << " " << die[1] << " " 
                       << die[2] << " " << die[3] << " " << die [4];
               cout << "\n\n\n   Which dice would you like to keep?";
               cout << "\n   Enter 1 to keep, or 0 to re-roll. "
                       "(e.g. 10101 re-rolls die 2 and 4): ";
               cin >> keepers;
              
               // For loop iterates through each character of the string, 
               //keepers, checking for a 1, or hold this die.
               // If a 1 is found, loop does not roll a new number for that die.
               //Otherwise, new number is found for each die rolled.
               for(unsigned int j = 0; j < 5; j++)
               {
                   if(keepers[j] != '1')
                   {
                          die[j] = rollDie(t2);
                   }                                  
               }              
              
               // Print player's second roll, prompt for the string keepers to 
               //determine which die should be held.
               cout << "\n\n\t\t        Your second rolls are: ";
               cout << "\n\n\t\t        " << die[0] << ' ' << die[1] << ' ' 
                       << die[2] << ' ' << die[3] << ' ' << die[4];
               cout << "\n\n   Which dice would you like to keep? Type '1' or "
                       "'0' as before: ";                      
                          
               cin >> keepers;
                          
               // Roll all die that are not selected as keeper with the number 1
               for(unsigned int j = 0; j < 5; j++)
               {
                   if(keepers[j] != '1')
                   {
                       die[j] = rollDie(t2);
                   }
               }
               // Prints player's final roll.
               cout << "\n\n\t\t        Your final dice combination is: ";
               cout << "\n\n\t\t        " << die[0] << ' ' << die[1] << ' ' 
                       << die[2] << ' ' << die[3] << ' ' << die[4]<<endl;
               cout<<endl;
               
              
               info();
  
               // declare variable option, prompt user for selection, assign 
               //selection. Try again statement defines goto position (back to 
               //choice) if
               // selection has already been used.
               tryAgain:
               int option;
               cout << "\n\n\tPlease enter the category you'd like to score "
                       "this turn: ";
               cin >> option;
  
               // Switch handles user selection for score category input
               // goto statements return game back to choice for switch if 
               //category has already been used.
               switch(option)
               {
               // if user has entered 1, checks to see if category already 
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 1:              
                   if(scoreComb[i][1] == true)
                   {
                       cout << "\n\tAces have already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the ONES in your hand,"
                               " or a 0: ";
                       cin >> combPoints[i][1];
                       scoreComb[i][1] = true;
                       break;
                   }
               // if user has entered 2, checks to see if category already 
               //holds a score, and prints appropriate response or returns to tryAgain.
               case 2:
                   if(scoreComb[i][2] == true)
                   {
                       cout << "\n\tTwos have already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all TWOS in your hand, "
                               "or a 0: ";
                       cin >> combPoints[i][2];
                       scoreComb[i][2] = true;
                       break;
                   }
               // if user has entered 3, checks to see if category already 
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 3:
                   if(scoreComb[i][3] == true)
                   {
                       cout << "\n\tThrees have already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the THREES in your "
                               "hand, or a 0: ";
                       cin >> combPoints[i][3];
                       scoreComb[i][3] = true;
                       break;
                   }
               // if user has entered 4, checks to see if category already
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 4:
                   if(scoreComb[i][4] == true)
                   {
                       cout << "\n\tFours have already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the FOURS in your"
                               " hand, or a 0: ";
                       cin >> combPoints[i][4];
                       scoreComb[i][4] = true;
                       break;
                   }
               // if user has entered 5, checks to see if category already
               //holds a score, and prints appropriate response or returns to tryAgain.
               case 5:
                   if(scoreComb[i][5] == true)
                   {
                       cout << "\n\tFives have already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the FIVES in your hand, or a 0: ";
                       cin >> combPoints[i][5];
                       scoreComb[i][5] = true;
                       break;
                   }
               // if user has entered 6, checks to see if category already 
               //holds a score, and prints appropriate response or returns to tryAgain.
               case 6:
                   if(scoreComb[i][6] == true)
                   {
                       cout << "\n\tSixes have already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the SIXES in your "
                               "hand, or a 0: ";
                       cin >> combPoints[i][6];
                       scoreComb[i][6] = true;
                       break;
                   }
               // if user has entered 7, checks to see if category already 
               //holds a score, and prints appropriate response or returns 
               //to tryAgain.
               case 7:
                   if(scoreComb[i][7] == true)
                   {
                       cout << "\n\t3 of a Kind has already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all dice in your hand, or "
                               "a 0: ";
                       cin >> combPoints[i][7];
                       scoreComb[i][7] = true;
                       break;
                   }
               // if user has entered 8, checks to see if category already 
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 8:
                   if(scoreComb[i][8] == true)
                   {
                       cout << "\n\t4 of a Kind has already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all dice in your hand, "
                               "or a 0: ";
                       cin >> combPoints[i][8];
                       scoreComb[i][8] = true;
                       break;
                   }
               // if user has entered 9, checks to see if category already 
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 9:
                   if(scoreComb[i][9] == true)
                   {
                       cout << "\n\tFull House has already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tIf you have a Full House, enter 25. "
                               "Otherwise, enter 0: ";
                       cin >> combPoints[i][9];
                       scoreComb[i][9] = true;
                       break;
                   }
               // if user has entered 10, checks to see if category already
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 10:
                   if(scoreComb[i][10] == true)
                   {
                       cout << "\n\tSmall Straight has already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tIf you have a Small Straight, enter 30. "
                               "Otherwise, enter 0: ";
                       cin >> combPoints[i][10];
                       scoreComb[i][10] = true;
                       break;
                   }
               // if user has entered 11, checks to see if category already 
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 11:
                   if(scoreComb[i][11] == true)
                   {
                       cout << "\n\tLarge Straight has already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tIf you have a Large Straight, enter "
                               "40. Otherwise, enter 0: ";
                       cin >> combPoints[i][11];
                       scoreComb[i][11] = true;
                       break;
                   }
               // if user has entered 12, checks to see if category already 
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 12:
                   if(scoreComb[i][12] == true)
                   {
                       // If statement to determine whether Yahtzee has been 
                       //previously scored or if a 0 was entered.
                       // If Yahtzee category is equal to 50 points, set 
                       //Yahtzee bonus to true.
                       if(combPoints[i][12] == 50)
                       {
                           yahtzeeBonus[i] = true;
                           cout << "\n\tCongratulations! Yahtzee Bonus has "
                                   "been applied!";
                       }
                       // If yahtzee holds a score of zero and has been entered,
                       //explain Joker Rules and return to choice.
                       else
                       {
                           cout << "\n\tYou have already entered a 0 for "
                                   "Yahtzee!";
                           cout << "\n\n\tIf you have Yahtzee in hand, and"
                                   " have already entered a 0 in the";
                           cout << "\n\tYahtzee category, apply the sum of"
                                   " your dice to the appropriate Upper";
                           cout << "\n\tSection score category. If "
                                   "applicable Upper Section score is filled, "
                                   "apply";
                           cout << "\n\tthe sum to any Lower Section "
                                   "category. If all Lower Section scores";
                           cout << "\n\thave been filled, you must enter a "
                                   "0 in any other Upper Section score.";
                            goto tryAgain;
                       }                      
                   }
                   else
                   {
                       cout << "\n\tIf you have scored YAHTZEE!, enter 50. "
                               "Otherwise, enter 0: ";
                       cin >> combPoints[i][12];
                       scoreComb[i][12] = true;
                       break;
                   }
               // if user has entered 13, checks to see if category already 
               //holds a score, and prints appropriate response or returns to 
               //tryAgain.
               case 13:
                   if(scoreComb[i][13] == true)
                   {
                       cout << "\n\tChance has already been scored.";
                       goto tryAgain;
                   }
                   else
                   {
                       cout << "\n\tIf using chance, enter sum of all dice."
                               " Otherwise, enter 0: ";
                       cin >> combPoints[i][13];
                       scoreComb[i][13] = true;
                       break;
                   }
               // if user has entered an inappropriate number, informs player 
               //that the number is not valid, and returns to tryAgain.
               default:
                   cout << "\n\tThat is not a valid selection, please "
                           "choose a number between 1 and 13.";
                   goto tryAgain;
               }
  
  
           }
           // Increments the round by one at the end of each round.
           round ++;
       }  
          
       // Vector to hold final scores of each player. Pairs with "vector<string>
       //names" for high score list
       vector<int> finalScores;
  
       // For loop adds and assigns the sum of the upper section scores to the 
       //uppSecTotals array for each separate player
       // and adds and assigns the sum of the lower section scores to the 
       //lowSectTotals array for each separate player.
       int uppSectTotals[4];
       int lowSectTotals[4];
       for(unsigned int i = 0; i < 4; i++)
       {          
           uppSectTotals[i] = (combPoints[i][0] + combPoints[i][1] + 
                   combPoints[i][2] + combPoints[i][3] + combPoints[i][4] + 
                   combPoints[i][5]);
           lowSectTotals[i] = (combPoints[i][6] + combPoints[i][7] + 
                   combPoints[i][8] + combPoints[i][9] + combPoints[i][10] + 
                   combPoints[i][11] + combPoints[i][12]);
       }  
  
       for(int i = 0; i < numOfPlayers; i++)
       {
           // tempScore used to total specific player's score. Once finished, 
           //applies final score to vector "finalScores."
           int tempScore = 0;
           // If Upper Section total is 63 or higher, applies bonus of 35 
           //points.
           if(uppSectTotals[1] >= 63)
           {
               tempScore += 35;
           }
           // If Yahtzee Bonus has been scored, applies an additional bonus 
           //of 100 points.
           if(yahtzeeBonus[i] = true)
           {
               tempScore += 100;
           }
           // tempScore contains any bonuses, and adds total of upper section 
           //and lower section scores.
           tempScore += (uppSectTotals[i] + lowSectTotals[i]);
          
           // Adds tempScore to finalScores vector, and pairs the players name 
           //and final score into playerScores vector for the high scores list.
           finalScores.push_back(tempScore);  
           playerScores.push_back(make_pair(finalScores[i], names[i]));
       }
      
       // High scores list header.
       cout << "\n\n\n              ****** Congratulations! You have completed "
               "the game! ******";
       cout << "\n\n              Scores in descending order are listed below: "
               "\n\n\n";
      
       // Sorts player scores from highest to lowest, then prints list. Notice 
       //iterator->second(names) is printed first, and iter->first (scores) is 
       //printed second.
       sort(playerScores.rbegin(), playerScores.rend());
       for(vector<pair<int, string> >::const_iterator iter = playerScores.begin
               (); iter != playerScores.end(); iter++)
       {
           cout << "\t" << iter->second << " " << iter->first << ".\n\n";
       }

       // Prompt player or players to play again. If "Y," return to beginning 
       //of game loop (restart the game, score list is saved)
       cout << "\n\n\t\tWould you like to play again?";
       cout << "\n\tEnter 'Y' to play again, or 'N' to end the game.";
       cin >> playAgain;
      
       // Ensures user enters a valid Play Again answer. If not, prompts user 
       //to re-enter letter.
       while((playAgain != "Y") && (playAgain != "N"))
       {
           cout << "\n\tThat answer is invalid. Enter capital 'Y' or capital "
                   "'N.'";
           cin >> playAgain;
       }

       // Clears names and finalScores vectors for new game
       names.clear();
       finalScores.clear();

   }

   return 0;
}

// sum Function - Used if number of players is higher than one, 
//returns
int sum(long t2)
{
    int roll1 = (rand() % 6 + 1);
   int roll2 = (rand() % 6 + 1);
   int roll3 = (rand() % 6 + 1);
   int roll4 = (rand() % 6 + 1);
   int roll5 = (rand() % 6 + 1);
  
   int startRoll = (roll1 + roll2 + roll3 + roll4 + roll5);
  
   return startRoll;
}

// rollDie Function. Called whenever the dice are rolled.
int rollDie(long t2)
{
   int roll = (rand() % 6 + 1);
   return roll;
}

//Game title
void title()
{
   fstream fIn;
fIn.open( "title.txt", ios::in );

if( fIn.is_open() )
{
  string s;
  while( getline( fIn, s ) )
  {
    cout << s << endl;
    // Tokenize s here into columns (probably on spaces)
  }
  fIn.close();
}    

}
//Game instructions
void instructions()
{
   fstream fIn;
fIn.open( "rules.txt", ios::in );

if( fIn.is_open() )
{
  string s;
  while( getline( fIn, s ) )
  {
    cout << s << endl;
    // Tokenize s here into columns (probably on spaces)
  }
  fIn.close();
}

}

// Score info
void info()
{
    
fstream fIn;
fIn.open( "info.txt", ios::in );

if( fIn.is_open() )
{
  string s;
  while( getline( fIn, s ) )
  {
    cout << s << endl;
    // Tokenize s here into columns (probably on spaces)
  }
  fIn.close();
}
    
}
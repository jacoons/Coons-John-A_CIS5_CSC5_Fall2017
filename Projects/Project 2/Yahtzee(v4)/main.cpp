#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int sum(long t2);
int rollDie(long t2);  
void info();
void title();
void inst(); 

int main(int argc, char* argv[])
{  

   time_t t;
   time(&t);    
   long t2 = static_cast<long> (t);
   srand(t2);
  
   vector<pair<int, string> > pScore;
   title();
   inst();   

   string pAgain = "Y";
   while(pAgain == "Y")
   {
       int numP = 0;
       cout << "\n\n\tPlease enter the number of players for this game(1-4): ";
       cin >> numP;
      
       while((numP >= 5) || (numP <= 0))
       {      
           cout << "\n\tSorry, but only 1 to 4 people may play in a game.";
           cout << "\n\tPlease enter the number of players for this game "
                   "(1-4): ";
           cin >> numP;
       }

       vector<string> names;
 
       if(numP == 1)
       {
           string name;
         
           cout << "\n\tPlease enter your name: ";
           cin >> name;
           names.push_back(name);
       }
      
      
       else if(numP > 1)
       {
           string message;
          
           cout << "\n\tTo determine which player will go first, each player "
                   "rolls all 5 die.";
           cout << "\n\tThe player with the highest total sum will start the "
                   "game.";
           cout << "\n\n\tEach player select a number between 1 and " 
                   << numP << ".";
           cout << "\n\tRemember your number. Each player's roll is determined "
                   "by their number.";
           cout << "\n\n\tType 'OK' when each player has a number: ";
           cin >> message;
  
           while((message != "OK") && (message != "ok"))
           {
               cout << "\n\tType 'OK' when ready: ";
               cin >> message;
           }

           vector<int> initR;
           
           for(int i = 0; i < numP; i++)
           {          
               int fRoll = sum(t2);
               cout << "\n\tNumber " << (i+1) << "'s sum of the initial roll "
                       "is: " << fRoll;
               initR.push_back(fRoll);
           }
   
           sort(initR.rbegin(), initR.rend());
     
           while(initR[0] == initR[1])
           {
               initR.clear();
               cout << "\n\tThere is a tie, re-rolling die. "
                       "(Remember your number!)";
              
               for(int i = 0; i < numP; i++)
               {
                   int fRoll = sum(t2);
                   cout << "\n\tNumber " << (i+1) << "'s sum of the initial "
                           "roll is: " << fRoll;
                   initR.push_back(fRoll);
               }
           }

           cout << "\n\n\tEnter name(s) in the order they take their turn." 
                   << endl;
           for(int i = 0; i < numP; i++)
           {
               string name;
               cout << "\n\n\tPlease enter player " << (i+1) << "'s name: ";
               cin >> name;
               names.push_back(name);
           }
       }  
      
       bool sComb[4][13];
       int cPoints[4][13];
           for(unsigned int j = 0; j < 4; j++)  
           {
               for(unsigned int k = 0; k < 13; k++)
               {              
                   sComb[j][k] = false;                  
                   cPoints[j][k] = 0;
               }
           }

       bool yBonus[4];
       for(unsigned int i = 0; i > 4; i++)
       {
           yBonus[i] = 0;
       }
   
       const int MAX_RDS = 13;
       int round = 1;
  
       while(round <= MAX_RDS)
       {
                    
           for(int i = 0; i < numP; i ++)
           {
               
               string keepers;
               int die[5];
               cout << "\n\n\n\n\t\t       ***** It is " << names[i] 
                       << "'s turn.*****" << endl;
               cout << "\n\n\t\t        Your first rolls are: \n\n";
  
               for(int j = 0; j < 5; j++)
               {
                   die[j] = rollDie(t2);
               }
              
               cout << "\t\t        " << die[0] << " " << die[1] << " " 
                       << die[2] << " " << die[3] << " " << die [4];
               cout << "\n\n\n   Which dice would you like to keep?";
               cout << "\n   Enter 1 to keep, or 0 to re-roll. "
                       "(e.g. 10101 re-rolls die 2 and 4): ";
               cin >> keepers;
              
               for(unsigned int j = 0; j < 5; j++)
               {
                   if(keepers[j] != '1')
                   {
                          die[j] = rollDie(t2);
                   }                                  
               }              
              
               cout << "\n\n\t\t        Your second rolls are: ";
               cout << "\n\n\t\t        " << die[0] << ' ' << die[1] << ' ' 
                       << die[2] << ' ' << die[3] << ' ' << die[4];
               cout << "\n\n   Which dice would you like to keep? Type '1' or "
                       "'0' as before: ";                      
                          
               cin >> keepers;
               
               for(unsigned int j = 0; j < 5; j++)
               {
                   if(keepers[j] != '1')
                   {
                       die[j] = rollDie(t2);
                   }
               }
              
               cout << "\n\n\t\t        Your final dice combination is: ";
               cout << "\n\n\t\t        " << die[0] << ' ' << die[1] << ' ' 
                       << die[2] << ' ' << die[3] << ' ' << die[4]<<endl;
               cout<<endl;
               
              
               info();
  
               tryAgn:
               int option;
               cout << "\n\n\tPlease enter the category you'd like to score "
                       "this turn: ";
               cin >> option;
  
               switch(option)
               {
           
               case 1:              
                   if(sComb[i][1] == true)
                   {
                       cout << "\n\tAces have already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the ONES in your hand,"
                               " or a 0: ";
                       cin >> cPoints[i][1];
                       sComb[i][1] = true;
                       break;
                   }
               
               case 2:
                   if(sComb[i][2] == true)
                   {
                       cout << "\n\tTwos have already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all TWOS in your hand, "
                               "or a 0: ";
                       cin >> cPoints[i][2];
                       sComb[i][2] = true;
                       break;
                   }
              
               case 3:
                   if(sComb[i][3] == true)
                   {
                       cout << "\n\tThrees have already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the THREES in your "
                               "hand, or a 0: ";
                       cin >> cPoints[i][3];
                       sComb[i][3] = true;
                       break;
                   }
               
               case 4:
                   if(sComb[i][4] == true)
                   {
                       cout << "\n\tFours have already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the FOURS in your"
                               " hand, or a 0: ";
                       cin >> cPoints[i][4];
                       sComb[i][4] = true;
                       break;
                   }
              
               case 5:
                   if(sComb[i][5] == true)
                   {
                       cout << "\n\tFives have already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the FIVES in your hand, or a 0: ";
                       cin >> cPoints[i][5];
                       sComb[i][5] = true;
                       break;
                   }
          
               case 6:
                   if(sComb[i][6] == true)
                   {
                       cout << "\n\tSixes have already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all the SIXES in your "
                               "hand, or a 0: ";
                       cin >> cPoints[i][6];
                       sComb[i][6] = true;
                       break;
                   }
             
               case 7:
                   if(sComb[i][7] == true)
                   {
                       cout << "\n\t3 of a Kind has already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all dice in your hand, or "
                               "a 0: ";
                       cin >> cPoints[i][7];
                       sComb[i][7] = true;
                       break;
                   }
             
               case 8:
                   if(sComb[i][8] == true)
                   {
                       cout << "\n\t4 of a Kind has already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tEnter the sum of all dice in your hand, "
                               "or a 0: ";
                       cin >> cPoints[i][8];
                       sComb[i][8] = true;
                       break;
                   }
               
               case 9:
                   if(sComb[i][9] == true)
                   {
                       cout << "\n\tFull House has already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tIf you have a Full House, enter 25. "
                               "Otherwise, enter 0: ";
                       cin >> cPoints[i][9];
                       sComb[i][9] = true;
                       break;
                   }
           
               case 10:
                   if(sComb[i][10] == true)
                   {
                       cout << "\n\tSmall Straight has already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tIf you have a Small Straight, enter 30. "
                               "Otherwise, enter 0: ";
                       cin >> cPoints[i][10];
                       sComb[i][10] = true;
                       break;
                   }
           
               case 11:
                   if(sComb[i][11] == true)
                   {
                       cout << "\n\tLarge Straight has already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tIf you have a Large Straight, enter "
                               "40. Otherwise, enter 0: ";
                       cin >> cPoints[i][11];
                       sComb[i][11] = true;
                       break;
                   }
             
               case 12:
                   if(sComb[i][12] == true)
                   {
                       
                       if(cPoints[i][12] == 50)
                       {
                           yBonus[i] = true;
                           cout << "\n\tCongratulations! Yahtzee Bonus has "
                                   "been applied!";
                       }
                       
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
                            goto tryAgn;
                       }                      
                   }
                   else
                   {
                       cout << "\n\tIf you have scored YAHTZEE!, enter 50. "
                               "Otherwise, enter 0: ";
                       cin >> cPoints[i][12];
                       sComb[i][12] = true;
                       break;
                   }
               
               case 13:
                   if(sComb[i][13] == true)
                   {
                       cout << "\n\tChance has already been scored.";
                       goto tryAgn;
                   }
                   else
                   {
                       cout << "\n\tIf using chance, enter sum of all dice."
                               " Otherwise, enter 0: ";
                       cin >> cPoints[i][13];
                       sComb[i][13] = true;
                       break;
                   }
              
               default:
                   cout << "\n\tThat is not a valid selection, please "
                           "choose a number between 1 and 13.";
                   goto tryAgn;
               }  
  
           }
         
           round ++;
       }  
       


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

int rollDie(long t2)
{
   int roll = (rand() % 6 + 1);
   return roll;
}

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
    
  }
  fIn.close();
}    

}

void inst()
{
   fstream fIn;
fIn.open( "rules.txt", ios::in );

if( fIn.is_open() )
{
  string s;
  while( getline( fIn, s ) )
  {
    cout << s << endl;

  }
  fIn.close();
}

}

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
   
  }
  fIn.close();
}
    
}
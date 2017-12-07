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
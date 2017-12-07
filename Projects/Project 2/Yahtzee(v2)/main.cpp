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
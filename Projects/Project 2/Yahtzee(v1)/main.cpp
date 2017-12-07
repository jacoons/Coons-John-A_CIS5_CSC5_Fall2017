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
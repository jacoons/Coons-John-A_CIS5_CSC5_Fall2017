#include <iostream>
#include <cstdlib> /* srand, rand */
#include <ctime> // time
#include <cmath>
using namespace std;

int main()
{
srand((int)time(0));
long long int X;
long long int guess;

cout<<"Enter X"<<endl ;
cin>> X;
cout<<"Value of X : "<<X<<endl;
long long int range = pow(10,X);
long long int value = rand() % range + 1;
long long int maxGuess = log2(range);

cout << "You will be given " << maxGuess << " guesses to guess the correct number\n";
for(long long int i=0;i<maxGuess;i++)
{
cout<<"Enter guess between 1 and " << range << ": ";
cin>>guess;


if(value == guess )
{
cout<<"Congratulations, You guessed the number!"<<endl;
//return 0;
}
else if (guess < value)
{
cout<< "Too low. Try again."<<endl;
}
else
{
cout<< "Too high. Try again."<<endl;
}
}
cout<<"Too many Tries, Game over"<<endl;

//HERE
cout<<"SFGKHGFKSHJGFKJSFGH";

return 0;
}
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <cmath>
using namespace std;

int main()
{
srand((int)time(0));
long long int X;
long long int guess;
char answer;

cout<<"Enter a number to set the RNG (X):"<<endl ;
cin>> X;
cout<<"Value of X : "<<X<<endl;
long long int range = pow(10,X);
long long int value = rand() % range + 1;
long long int maxGuess = log2(range);

cout<<"I have a number between 1 and "<<range<<endl;
cout << "You will be given a maximum of " << maxGuess << " guesses."<<endl;
cout<<"Please type your first guess below."<<endl;
        
for(long long int i=0;i<maxGuess;i++)
{
cout<<"Enter number(guess) between 1 and " << range << ": ";
cin>>guess;

if(value == guess )
{
cout<<"Congratulations, you guessed the number!"<<endl;
cout<<"want to play again?"<<endl;
cin>>answer;
if(answer=='y')
{
    main();
}
return 0;
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
cout<<"Too many tries."<<endl;

return 0;
}
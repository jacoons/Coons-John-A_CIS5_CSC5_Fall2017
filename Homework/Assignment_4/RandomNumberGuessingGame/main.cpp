#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    unsigned int setNumber;
    int guess;
    srand(time(0));
    
    setNumber = 1 + rand() % 100;
    
    cout<<"Please guess a number in the range of 1-100."<<endl;
    
    do
    {
        cin>> guess;
        
        if(guess < setNumber)
           cout<<"Your low.  Guess again: "<<endl;
        
        if(guess > setNumber)
           cout<<"Your high.  Guess again: "<<endl;
        
        if(guess == setNumber)
        {
           cout<<"Your correct!!!!"<<endl;
           break;
        }
    
    }while (guess != setNumber);
            
    
    
    
    
    
    
    return 0;
}


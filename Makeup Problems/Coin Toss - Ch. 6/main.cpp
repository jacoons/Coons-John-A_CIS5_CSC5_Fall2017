#include<iostream>
using namespace std;

int coinToss()
{
    int randNum;
    
    randNum = 1 +rand() % 2;
    
    if(randNum==1)
        cout<<"head"<<endl;
    else
        cout<<"tails"<<endl;
    
    return randNum;
    
}

int main(int argc, char** argv) 
{
    int numTimes, countHead=0, countTail=0, result;
    
    cout<<"How many times do want to flip the coin?"<<endl;
    cin>> numTimes;
    
    for(int i=1;i<=numTimes;i++)
    {
        result=coinToss();
        
        if(result==1)
        {
            countHead++;
        }
        
        else if(result==2)
        {
            countTail++;
        }
    }
    cout<<endl<<"Total number of heads: "<<countHead<<endl;
    cout<<"total number of tails: "<<countTail<<endl;
    
    system("pause");
}
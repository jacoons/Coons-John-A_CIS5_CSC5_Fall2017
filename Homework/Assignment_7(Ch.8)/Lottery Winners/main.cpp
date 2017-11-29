#include <iostream>
using namespace std;

#define SIZE 10

bool searchWinner(int [], int, int);

int main(int argc, char** argv) 
{
    int winNum[10]={13579, 26791, 26792, 33445, 55555, 62483, 77777, 
    79422, 85647, 93121};
    
    int playNum;
    
    cout<<"Please enter your number: "<<endl;
    cin>>playNum;
    
    bool result = searchWinner(winNum,SIZE,playNum);
    
    if(result)
        cout<<"You have one of the winning numbers!"<<endl;
    else
        cout<<"Your number is not a winning number!"<<endl;
    
    
    
}

bool searchWinner(int winNum[], int size, int playNum)
{
    bool found = false;
    int index = 0;
    
    while(index<size&!found)
    {
        if(winNum[index]==playNum)
            found=true;
        index++;
    }
    
    return found;
    }





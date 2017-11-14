#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    float spent, budget, 
          total = 0;
    
    cout<<"Please enter your budget for the month: ";
    cin>> budget;
    
    cout<<"(Enter '0' when you are done)"<<endl;
    cout<<"Please enter each expense for the month: "<<endl;
    
    do
    {
        cin>> spent;
        total = total + spent;
        
    }while (spent != 0);
    
    if (total <= budget)
        cout<<"Your monthly spending of $"<<total<<" is under the monthly "
                "budget of $"<<budget<<"!"<<endl;
            
    else
        cout<<"Your monthly spending of $"<<total<<" is over the monthly "
                "budget of $"<<budget<<"!"<<endl;
    
    
    
    
    return 0;
}


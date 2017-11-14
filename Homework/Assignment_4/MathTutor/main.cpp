
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    const int max = 100;
    
    int  rn1, rn2, choice, answer;
    
    double result;
    
    bool selection = true;
    
    do
    {
        unsigned seed = time(0);
        srand(seed);
        rn1 = 1 + rand() % max;
        rn2 = 1 + rand() % max;
        
        cout<<"_______MENU________"<<endl;
        cout<<"1. Addition"<<endl;
        cout<<"2. Subtraction"<<endl;
        cout<<"3. Multiplication"<<endl;
        cout<<"4. Division"<<endl;
        cout<<"5. Quit"<<endl;
        
        cout<<"Please make a selection from the above menu: "<<endl;
        cin>> choice;
        
        switch(choice)
        
        {
            
            case 1:
                cout<<"Addition: "<<endl;
                cout<<setw(5)<<rn1<<endl;
                cout<<"+"<<setw(4)<<rn2<<endl;
                cout<<"-------------"<<endl;
                result = rn1 + rn2;
                break;
                
            case 2:
                cout<<"Subtraction: "<<endl;
                cout<<setw(5)<<rn1<<endl;
                cout<<"-"<<setw(4)<<rn2<<endl;
                cout<<"-------------"<<endl;
                result = rn1 - rn2;
                break;
                
            case 3:
                cout<<"Multiplication: "<<endl;
                cout<<setw(5)<<rn1<<endl;
                cout<<"*"<<setw(4)<<rn2<<endl;
                cout<<"-------------"<<endl;
                result = rn1 * rn2;
                break;
                
            case 4:
                cout<<"Division: "<<endl;
                cout<<setw(5)<<rn1<<endl;
                cout<<"/"<<setw(4)<<rn2<<endl;
                cout<<"-------------"<<endl;
                result = rn1 / rn2;
                break;  
                
            case 5:
                exit(0);
            default: cout<<"INVALID SELECTION!!!"<<endl;
            
            selection = false;
            
        }
        
        if (selection)
        {
            cout<<"Enter the answer: "<<endl;
            cin>> answer;
            
            if (answer == result)
                cout<<"Congrats your answer is correct!"<<endl;
            else
                cout<<"Your answer is incorrect.  You are a failure."<<endl;
                cout<<"The correct answer is: "<<setw(5)<<result<<endl;
        }
        
        selection = true;
        cout<<endl;
        }while (selection);
    
                
                    
        
        
        
      
    
    
    
    return 0;
}


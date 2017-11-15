#include <iostream>
#include <cmath>

using namespace std;

float stockProfit(float,float,float,float,float);

int main(int argc, char** argv) {
    
    float ns, pp, pc, sc, sp, profit;
    
    cout<<"Please enter the number of shares: ";
    cin>>ns;
    
    cout<<"Please enter the purchase price of each share: ";
    cin>>pp;

    cout<<"Please enter the purchase commission: ";
    cin>>pc;

    cout<<"Please enter the sale price per share: ";
    cin>>sp;

    cout<<"Please enter the sales commission: ";
    cin>>sc;
    
    profit=stockProfit(ns,pp,pc,sp,sc);
    
    if(profit<0)
        cout<<"The loss on the sale of the stock is: $"<<abs(profit)<<"."<<endl;
    else
        cout<<"Profit on the sale of the stock is: $"<<profit<<"."<<endl;
}

    float stockProfit(float ns, float pp, float pc, float sp, float sc)
    {
        float profit;
        profit=((ns*sp)-sc)-((ns*pp)+pc);
        return profit;
    }



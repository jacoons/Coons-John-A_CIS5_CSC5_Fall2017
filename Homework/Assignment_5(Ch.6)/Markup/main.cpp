#include <iostream>
using namespace std;

float total(float cost, float markup);

int main(int argc, char** argv) 
{
    float wcost, retail, Mpercentage;
    
    cout<<"Please enter the item's wholesale cost: $";
    cin>> wcost;
    cout<<endl;
    
    cout<<"Please enter the item's markup percentage: %";
    cin>> wcost;
    cout<<endl;
    
    retail = total (wcost, Mpercentage);
    
    cout<<"This item is sold at a retail price of: $"<<retail<<endl;
  
}

float total(float cost, float markup)
{
    float retail;
    retail = cost+ ((cost*markup)/100);
    return retail;
    }
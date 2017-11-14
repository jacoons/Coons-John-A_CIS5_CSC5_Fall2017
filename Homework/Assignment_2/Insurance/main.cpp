
#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    float insurance_rate, replace_cost, recommended;
    
    insurance_rate=0.80;
            
    cout<<"Enter the replacement cost of your building:";
    cin>>replace_cost;
    
    recommended=insurance_rate*replace_cost;
    
    cout<<"It is recommended that you purchase $"<<recommended<<" in insurance "
            "for your property.";
    
            
    return 0;
}


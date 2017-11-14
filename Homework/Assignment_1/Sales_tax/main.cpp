#include <iostream>

using namespace std;

int main()
{
    float purchase, sales_tax, county_tax, total_tax;
    
    purchase=95;
    sales_tax=0.04*purchase;            
    county_tax=0.02*purchase;
    total_tax=sales_tax+county_tax;
    
    cout<<"Total sales tax on a $"<<(purchase)<<" item is $"<<(total_tax)<<".";
    
    
            

    return 0;
}



#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    
    string movie_name;
    float adult_price, child_price, adult_qty, child_qty, adult_total, 
            child_total, total_qty, total, theater_tax, profit, dist;
    
    cout<<"What is the name of the movie?";
    getline(cin, movie_name);
    
    cout<<"How many children's tickets were purchased?";
    cin>>child_qty;
    
    cout<<"How many adult's tickets were purchased?";
    cin>>adult_qty;
    
    child_price=06.00;
    adult_price=10.00;
    theater_tax=0.20;
            
    
    adult_total=adult_price*adult_qty;
    child_total=child_price*child_qty;
    total=adult_total+child_total;
    profit=total*theater_tax;
    dist=total-profit;
    
    cout<<setprecision(2)<<fixed;
    
    cout<<"Movie Name:                   "<<movie_name<<"\n";
    cout<<"Adult Tickets Sold:           "<<adult_qty<<"\n";
    cout<<"Child Tickets Sold:           "<<child_qty<<"\n";
    cout<<"Gross Box Office Profit:      $"<<total<<"\n";
    cout<<"Net Box Office Profit:        $"<<profit<<"\n";
    cout<<"Amount Paid to Distributor:   $"<<dist<<"\n";
    
        

    return 0;
}


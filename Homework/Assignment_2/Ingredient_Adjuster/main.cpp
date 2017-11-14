
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    
    float qty, sugar_per_cookie, butter_per_cookie, flour_per_cookie, sugar_total,
            butter_total, flour_total;    
    
    sugar_per_cookie=1.5/48;
    butter_per_cookie=1.0/48;
    flour_per_cookie=2.75/48;           
    
    cout<<"How many cookies do you want to make?";
    cin>>qty;
    
    sugar_total=sugar_per_cookie*qty;
    butter_total=butter_per_cookie*qty;
    flour_total=flour_per_cookie*qty;
    
    cout<<"To make "<<qty<<" cookies, you will need "<<sugar_total<<" cups of sugar, "
            <<butter_total<<" cups of butter and "<<flour_total<<" cups of flour.";
    

    return 0;
}


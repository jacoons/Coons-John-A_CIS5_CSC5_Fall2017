#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    int month, year, day, product;
    
    cout<<"Please enter the number of a month: "<<endl;
    cin>> month;
    
    cout<<"Please enter a day of the month you entered: "<<endl;
    cin>> day;    
    
    cout<<"Please enter the last two digits of a year: "<<endl;
    cin>> year;
    
    product = month * day;
    
    if (product == year)
    {
        cout<<"This date is... magic!!!"<<endl;
    }
    else
        cout<<"This date is not magic!!!"<<endl;
    
       
    
    
    return 0;
}


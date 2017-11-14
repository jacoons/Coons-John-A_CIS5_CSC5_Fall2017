
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    double cost, q,total;
    
    cout<<"Enter quantity: "<<endl;
    cin>> q;
    
    if (q <= 0)
    {
        cout<<"INVALID ENTRY!!!"<<endl;
        cin>> q;
    }
    
    cost = 99;
    
    if(q < 10)
        total = cost;
    else if(q <= 19)
        total = cost - ((cost*20)/100);
    else if(q <=49)
        total = cost - ((cost*30)/100);
    else if(q <=99)
        total = cost - ((cost*40)/100);
    
    else
        total = cost - ((cost*50)/100);
    
    cout<<"The total cost of your purchase is $"<<(total * q)<<"."<<endl;

    return 0;
}


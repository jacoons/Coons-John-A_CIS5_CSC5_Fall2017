
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    float total;
    int check;
    
    cout<<"How many check were written last month?"<<endl;
    cin>> check;
    
    if (check < 0)
    {
        cout<<"INVALID ENTRY!!!"<<endl;
    }    
    else if (check < 20)
    {
        total = 10 + check * 0.10;
    }        
    else if (check < 40)
    {
        total = 10 + (19.0 * 0.10)+ (check - 19) * 0.08;
    }  
    else if (check < 60)
    {
        total = 10 + (19 * 0.10) + (20 * 0.08) + (check - 39)*0.06; 
    }  
    else
    {
        total = 10 + (19 * 0.10) + (20 * 0.08) + (20 * 0.06) + (check - 59)*0.04;
    }    
    
    cout<<"Bank's fees for the month: "<<"$"<<(total)<<endl;
    
    
    return 0;
}


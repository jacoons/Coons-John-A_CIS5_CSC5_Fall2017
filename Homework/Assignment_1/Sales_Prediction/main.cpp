#include <iostream>

using namespace std;

int main()
{
    float total_sales, percent,percent_true;
    
    total_sales=8.6;
    percent=0.58;
    percent_true=58;
    
    cout<<"The East Coast sales division will make $"<<(total_sales*percent)<<endl;
    cout<<"million if they make "<<(percent_true)<<"% on a total of "<<endl;
    cout<<(total_sales)<<" million in sales.";
         
    return 0;
}


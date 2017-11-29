#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void sortHigh2Low(int [], string[]);

const int N_MONTHS = 12;

int main(int argc, char** argv)
{
    int values[N_MONTHS];
    
    string p_months[N_MONTHS] = {"January", "February", "March", "April",
    "May", "June", "July", "August", "September", "October",
    "November", "December"};
    
    for(int month=0;month<N_MONTHS;month++)
    {
        do{
            cout<<"Enter the total rainfall for "<<p_months[month]<<":";
            
            cin>>values[month];
            
            if(values[month]<0)
                cout<<"Enter positive rain fall statistics"<<endl;
        }while(values[month]<0);
    }
    cout<<"Before sorting "<<endl;
    
    for(int month=0;month<N_MONTHS;month++)
        cout<<setw(10)<<p_months[month]<<setw(10)<<values[month]<<endl;
    
    sortHigh2Low(values,p_months);
    
    cout<<"After sorted in order of rainfall "<<endl;
    cout<<"From highest to lowest "<<endl;
    
    for(int month=0;month<N_MONTHS;month++)
        cout<<setw(10)<<p_months[month]<<setw(10)<<values[month]<<endl;
    
    return 0;
}

void sortHigh2Low(int values[],string p_months[])
{
    bool swap;
    int temp;
    
    do
    {
        
        swap=false;
        for(int count=0;count<N_MONTHS;count++)
        {
            if(values[count]<values[count+1])
            {
                temp=values[count];
                values[count]=values[count+1];
                values[count+1]=temp;
                
                string tempString=p_months[count];
                p_months[count]=p_months[count+1];
                p_months[count+1]=tempString;
                swap=true;
                
            }
        }
    }while(swap);
}
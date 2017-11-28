#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float proj(float p, float bp, float dp, float in, float out){
    float n;
    n=p+in+bp-dp-out;
    return n;
}

int main(int argc, char** argv) {
    float start,bp,dp, go,come,year,projected,total=0;
    cout<<"Please enter the starting size of the population: ";
    cin>>start;
    while(start<2)
    {
        cout<<"ERROR - TRY AGAIN: ";
        cin>>start;
    }
    cout<<"Please enter the annual birth rate: ";
    cin>>bp;
    while(bp<0)
    {
        cout<<"ERROR - TRY AGAIN: ";
        cin>>bp;
    }
    cout<<"Please enter the annual death rate: ";
    cin>>dp;
    while(dp<0)
    {
      cout<<"ERROR - TRY AGAIN: ";
        cin>>dp;  
    }
    cout<<"Please enter the average yearly population increase: ";
    cin>>come;
    
    cout<<"Please enter the average yearly population decrease: ";
    cin>>go;
    
    cout<<"Please enter the number of years to calculate to: ";
    cin>>year;
    while(year<1)
    {
         cout<<"ERROR - TRY AGAIN: ";
        cin>>year;
    }
    cout<<"The starting population is "<<start<<endl;
    for(int x=1; x<=year; x++)
    {
        projected=proj(start,bp,dp,come,go);
        total=total+projected;
        cout<<"The projected population on year "<<year<<" is "<<total<<"."<<endl;
    }

    return 0;
}


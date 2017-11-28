#include<iomanip>
#include <iostream>

using namespace std;

double calculateTotalRainfall(double[], int);
double calculateAverageRainfall(double[], int);
double findHighestRainfall(double[], int, int &);
double findLowestRainfall(double[], int, int &);



int main(int argc, char** argv) {

    const int TOTAL_MONTHS=12;
    
    double totalRainfall, averageRainfall, highestRainfall, lowestRainfall;
    int monthIndexHigh = 0, monthIndexLow =0;
    
    double monthlyRainfall[TOTAL_MONTHS];
    
    string namesOfMonths[TOTAL_MONTHS]={"January", "February", "March", 
    "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};
    
    for(int i=0; i<TOTAL_MONTHS;i++)
    {
        cout<<"Pleas enter the rainfall in "<<namesOfMonths[i]<<":";
        cin>>monthlyRainfall[i];
        while(monthlyRainfall[i]<0)
    {
        cout<<"Rainfall should be greater than or equal to 0."<<endl;
        cout<<"Please enter a valid number for rainfall in: "<<namesOfMonths[i]<<
                ": ";
        cin>>monthlyRainfall[i];
    }
}
    
totalRainfall = calculateTotalRainfall(monthlyRainfall, TOTAL_MONTHS);
averageRainfall = calculateAverageRainfall(monthlyRainfall, TOTAL_MONTHS);
highestRainfall = findHighestRainfall(monthlyRainfall, TOTAL_MONTHS, monthIndexHigh);
lowestRainfall = findLowestRainfall(monthlyRainfall, TOTAL_MONTHS, monthIndexLow);


cout<<fixed<<showpoint<<setprecision(2)<<endl;
cout<<"The total rainfall in the year: "<<totalRainfall<<endl;
cout<<"The average rainfall in the year: "<<averageRainfall<<endl;
cout<<"The highest rainfall in the year: "<<highestRainfall<<" in "
        <<namesOfMonths[monthIndexHigh]<<endl;
cout<<"The lowest rainfall in the year: "<<lowestRainfall<<" in "
        <<namesOfMonths[monthIndexLow]<<endl;


    
    return 0;
}

double calculateTotalRainfall(double amounts[],int n)
{
    double totalAmount=0;
    for (int i=0;i<n;i++)
        totalAmount+=amounts[i];
    return totalAmount;
}

double calculateAverageRainfall(double amounts[],int n)
{
    double averageAmount=0.0;
    double totalAmount=0;
    for (int i=0;i<n;i++)
    totalAmount+=amounts[i];
    averageAmount=totalAmount/n;
    return averageAmount;
}

double findHighestRainfall(double amounts[],int n, int &monthIndex)
{
    double highestAmount;
    int i = 0;
    highestAmount=amounts[i];
    while(i<n)
    {
        if(amounts[i]>highestAmount)
        {
            highestAmount=amounts[i];
            monthIndex=i;
        }
        i++;
    }
    return highestAmount;
}
        
double findLowestRainfall(double amounts[], int n, int &monthIndex)
{
    double lowestAmount;
    int i = 0;
    lowestAmount=amounts[i];
    while(i<n)
    {
        if(amounts[i]<lowestAmount)
        {
            lowestAmount=amounts[i];
            monthIndex=i;
        }
        i++;
    }
    return lowestAmount;
    }

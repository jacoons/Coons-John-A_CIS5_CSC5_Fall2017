#include <iostream>
using namespace std;

double getSales(string); //THE BOOK INSTRUCTS US TO USE A DOUBLE OTHERWISE
                         //I WOULD HAVE USE A FLOAT.

void findHighest(double, double, double, double);

int main(int argc, char** argv) 
{
    double salesNE, salesSE, salesNW, salesSW;
    
    salesNE=getSales("Northeast");
    salesSE=getSales("Southeast");
    salesNW=getSales("Northwest");
    salesSW=getSales("Southwest");
    
    findHighest(salesNE, salesSE, salesNW, salesSW);
    
    return 0;
    
}

double getSales(string nameDivision)
{
    double tempSales;
    while(true)
    {
        cout<<"Please enter the quarterly sales for the "<<nameDivision
                <<" division: ";
        cin>>tempSales;
        
        if(tempSales>0)
        {
            break;
        }
        cout<<"The entered value must be positive."<<endl;
    }
      return tempSales;  
    }

void findHighest(double NE, double SE, double NW, double SW)
{
    if(SE>=NE&&SE>=NW&&SE>=SW)
    {
        cout<<"The Southeast division made the most money with $"<<SE<<"."<<endl;
    }
   
    if(NE>=SE&&NE>=NW&&NE>=SW)
    {
        cout<<"The Northeast division made the most money with $"<<NE<<"."<<endl;
    }
    
    if(SW>=NE&&SW>=NW&&SW>=SE)
    {
        cout<<"The Southwest division made the most money with $"<<SW<<"."<<endl;
    }
    
    
    if(NW>=NE&&NW>=SE&&NW>=SW)
    {
        cout<<"The Northwest division made the most money with $"<<NW<<"."<<endl;
    }
}
    
    
    
    
    
    
    
    

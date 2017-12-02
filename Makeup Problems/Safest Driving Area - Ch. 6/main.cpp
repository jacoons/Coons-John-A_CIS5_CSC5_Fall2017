#include <iostream>
using namespace std;


int getNumAccidents(char *);
void findLowest(double, double, double, double, double);
    
int main(int argc, char** argv) 
{
    double central,north, south, east, west;
    
    central = getNumAccidents("central");
    north = getNumAccidents("north");
    south = getNumAccidents("south");
    east = getNumAccidents("east");
    west = getNumAccidents("west");
    
    findLowest(central,north, south, east, west);
    
    return 0;
    
}

int getNumAccidents(char * division)
{
    int accidents;
    
    do
    {
        cout<<"Please enter accidents in "<<division<<" division: ";
        cin>>accidents;
        
        if(accidents<0.0)
            cout<<"Please enter a positive number.";
        
    }
    
    while(accidents<0.0);
    
    return accidents;
}

void findLowest(double central, double north, double south, double east, double west)
{
    
    if(central<=north&&central<=east&&central<=west&&central<=south)
    {
        cout<<"Lowest accidents in central division: "<<central<<endl;
    }
    
    if(north<=south&&north<=west&&north<=east&&north<=central)
    {
        cout<<"Lowest accidents in north division: "<<north<<endl;
    }
    
    if(south<=north&&south<=east&&south<=west&&south<=central)
    {
        cout<<"Lowest accidents in south division: "<<south<<endl;
    }
    
    if(east<=north&&east<=west&&east<=south&&east<=central)
    {
        cout<<"Lowest accidents in east division: "<<east<<endl;
    }
    
    if(west<=north&&west<=south&&west<=east&&west<=central)
    {
        cout<<"Lowest accidents in west division: "<<west<<endl;
    }
    
}
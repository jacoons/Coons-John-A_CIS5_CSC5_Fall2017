
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    
    float male, female, total, male_percent, female_percent;
    
    cout<<"How many males are in the class?";
    cin>>male;
    
    cout<<"How many females are in the class?";
    cin>>female;
    
    total=male+female;
    male_percent=(male/total)*100.00;
    female_percent=(female/total)*100.00;
   
    cout<<"The class is "<<male_percent<<"% male"<<" and "<<female_percent<<"% female.";
    

    return 0;
}



#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    
    string month_1, month_2, month_3;
    float month1, month2, month3, total, average;
           
    cout<<"What month would you like to record for first?";
    cin>>month_1;
    cout<<"How much rain fell for the month of "<<month_1<<" (in inches)?";
    cin>>month1;
    
    cout<<"What month would you like to record for next?";
    cin>>month_2;
    cout<<"How much rain fell for the month of "<<month_2<<" (in inches)?";
    cin>>month2;
    
    cout<<"What month would you like to record for last?";
    cin>>month_3;
    cout<<"How much rain fell for the month of "<<month_3<<" (in inches)?";
    cin>>month3;   
        
    total=month1+month2+month3;
    average=total/3;   
        
    cout<<"The average rainfall for the month's of "<<month_1<<", "<<month_2<<" "
            "and "<<month_3<<" is "<<average<<" inches.";
    

    return 0;
}


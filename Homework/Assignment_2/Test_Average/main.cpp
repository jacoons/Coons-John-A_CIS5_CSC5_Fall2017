
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    
    float test_1, test_2, test_3, test_4, test_5, total, average;
           
    cout<<"Please enter the score for Test 1:";
    cin>>test_1;
    
    cout<<"Please enter the score for Test 2:";
    cin>>test_2;
    
    cout<<"Please enter the score for Test 3:";
    cin>>test_3;
    
    cout<<"Please enter the score for Test 4:";
    cin>>test_4;
    
    cout<<"Please enter the score for Test 5:";
    cin>>test_5;
    
    total=test_1+test_2+test_3+test_4+test_5;
    average=total/5.00;   
        
    cout<<"The test average is "<<fixed<<setprecision(1)<<average<<".";
    

    return 0;
}


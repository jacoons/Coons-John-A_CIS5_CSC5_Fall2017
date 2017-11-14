
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    
    float class_a, class_b, class_c, class_a1, class_b1, class_c1, total;
        
    cout<<"How many Class A seats were sold?";
    cin>>class_a1;
    
    cout<<"How many Class B seats were sold?";
    cin>>class_b1;
    
    cout<<"How many Class C seats were sold?";
    cin>>class_c1;
    
    class_a=15.00*class_a1;
    class_b=12.00*class_b1;
    class_c=9.00*class_c1;
    total=class_a + class_b + class_c;
    
    cout<<"There was a total of $"<<setprecision(2)<<showpoint<<total<<" generated from ticket sales.";
    

    return 0;
}


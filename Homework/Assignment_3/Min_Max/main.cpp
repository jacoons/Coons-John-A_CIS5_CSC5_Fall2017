
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    double number_1, number_2;
    
    cout<<"Enter the first number:";
    cin>> number_1;
    
    cout<<"Enter the second number:";
    cin>> number_2;
    
    number_1 > number_2 ? cout<<"First number is larger":
        cout<<"First number is smaller";
    
    return 0;
}


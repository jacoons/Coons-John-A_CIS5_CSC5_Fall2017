/* 
 * File:   main.cpp
 * Author: Coons, John A.
 * Created on September 13, 2017, 9:50 AM
 * Purpose:  Create a big C
 */

//System Libraries Here
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char c;
    string sp1=" ";
    string sp2="  ";
    
    //Input or initialize values Here
    cout<<"Big C Program"<<endl;
    cout<<"Input the letter to draw a Big C"<<endl;
    cin>>c;
    
    
    //Process/Calculations Here
    
    //Output Located Here
    cout<<sp2<<c<<c<<endl;
    cout<<sp1<<c<<sp2<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<sp1<<c<<sp2<<c<<endl;
    cout<<sp2<<c<<c<<endl;

    //Exit
    return 0;
}


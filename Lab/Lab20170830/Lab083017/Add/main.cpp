/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 29, 2017, 12:01 PM
 * Purpose:  Creating a class template
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argv,char ** argc) {
    //Declare Variables
    short a,b,c;
    
    //Initialize Variables
    a=200;
    b=300
 
    //Process or map the inputs to the outputs
    c=a+b;
    
    //Display/Output all pertinent variables
    std::cout<<a<<" + "<<b<<" = "<<c<<std::endl;
    
    //Exit the program
    return 0;
}
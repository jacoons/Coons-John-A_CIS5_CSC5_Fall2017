/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 9th, 2017, 12:15 PM
 * Purpose:  Retirement Calculator Version 1
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <iomanip>      //Format Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float salary, deposit, invRate, savings, retAcct;
    
    //Initialize Variables
    salary=100000;          //$100k
    invRate=0.05;           //5%
    savings=salary/invRate; //Required savings to retire $'s
    deposit=0.10;           //10%/year
    retAcct=0;              //Initialize the retirement account
    
    //Process or map the inputs to the outputs
    cout<<"Retirement Table"<<endl;
    cout<<"Year      Savings  Int Earned    Deposit"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    for(int year=2022;year<=2072;year++){
        float intErnd=invRate*retAcct;//Interest earned for the year
        float depAmt=deposit*salary; //Yearly deposit
        cout<<setw(4)<<year<<setw(13)<<retAcct<<setw(12)<<intErnd
                <<setw(11)<<depAmt<<endl;
        retAcct+=(intErnd+depAmt);
    }
    
    //Exit the program
    return 0;
}
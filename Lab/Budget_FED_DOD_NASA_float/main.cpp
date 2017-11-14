/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 5th, 2017, 11:42 PM
 * Purpose:  What is unknown - What is reality!
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float fedBudg;//Federal Budget
    float dodBudg;//Department of Defense or Military Budget
    float nasaBud;//NASA Budget
    float pctDOD; //Percent DOD budget as a function of Federal
    float pctNASA;//Percent NASA budget as a function of Federal
    
    //Initialize Variables
    //Numbers will vary based on proposed vs. actual
    //by a small amount
    fedBudg=3.8e12f;//3.8  Trillion found by Google on-line 2017
    dodBudg=608e9f; //608  Billion  found by Google on-line  2017
    nasaBud=18.4e9f;//18.4 Billion  found by Google on-line  2017
    
    //Process or map the inputs to the outputs
    pctDOD=dodBudg/fedBudg*100;
    pctNASA=nasaBud/fedBudg*100;
    
    //Display/Output all pertinent variables
    cout<<"NASA's 2017 budget = $"<<nasaBud<<endl;
    cout<<"DOD's  2017 budget = $"<<dodBudg<<endl;
    cout<<"Fed's  2017 budget = $"<<fedBudg<<endl;
    cout<<"DOD's  percentage of total = "<<pctDOD<<"%"<<endl;
    cout<<"NASA's percentage of total = "<<pctNASA<<"%"<<endl;
    
    
    //Exit the program
    return 0;
}
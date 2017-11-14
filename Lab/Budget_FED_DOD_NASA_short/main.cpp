/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 6th, 2017, 10:52 AM
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
    short fedBudg;//Federal Budget
    short dodBudg;//Department of Defense or Military Budget
    short nasaBud;//NASA Budget
    float pctDOD; //Percent DOD budget as a function of Federal
    float pctNASA;//Percent NASA budget as a function of Federal
    
    //Initialize Variables
    //Numbers will vary based on proposed vs. actual
    //by a small amount
    fedBudg=3650;//3650 Billon found by Google on-line 2017
    dodBudg=639; //639  Billion  found by Google on-line  2017
    nasaBud=19.1;//19.1 Billion  found by Google on-line  2017
    
    //Process or map the inputs to the outputs
    pctDOD=100.0f*dodBudg/fedBudg;
    pctNASA=100.0f*nasaBud/fedBudg;
    
    //Display/Output all pertinent variables
    cout<<"NASA's 2017 budget = $"<<nasaBud<<" Billion"<<endl;
    cout<<"DOD's  2017 budget = $"<<dodBudg<<" Billion"<<endl;
    cout<<"Fed's  2017 budget = $"<<fedBudg<<" Billion"<<endl;
    cout<<"DOD's  percentage of total = "<<pctDOD<<"%"<<endl;
    cout<<"NASA's percentage of total = "<<pctNASA<<"%"<<endl;
    
    
    //Exit the program
    return 0;
}
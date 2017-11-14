/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 7th, 2017, 12:16 PM
 * Purpose:  How much tax we pay at the pump
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare and initialize Variables
    //Known Values
    float   pp=2.93f,    //Price at pump for a gallon of gas $/gallon
            ft=0.184f,   //Federal Tax per Gallong $/gallon
            st=0.36f,    //State Tax per Gallon $/gallon
            pt=0.0775f,  //State percentage sales tax
            oc=0.07f;    //Oil Company profit per Gallon
    //Unknown values
    float   bp,          //Base price $/gallon
            tt,          //Total Tax $/gallon
            ptt,         //Percentage total tax
            ptp,         //Percentage oil company profit
            sst;         //State Sales Tax

    //Process or map the inputs to the outputs
    bp=(pp-ft-st)/(1+pt);
    sst=bp*pt;
    tt=pp-bp;
    ptt=tt/bp*100;
    ptp=oc/bp*100;
    
    //Display/Output all pertinent variables
    cout<<"Known Values "<<endl;
    cout<<"Price at pump for a gallon of gas = $"<<pp<<endl;
    cout<<"Federal Tax per gallon of gas     = $"<<ft<<endl;
    cout<<"State Tax per gallon of gas       = $"<<st<<endl;
    cout<<"State percentage sales tax        =  "<<pt*100<<"%"<<endl;
    cout<<"Oil Company Profits per gallon    = $"<<oc<<endl;
    cout<<"Computed Values"<<endl;
    cout<<"Base price for a gallon of gas    = $"<<bp<<endl;
    cout<<"State Sales Tax per gallon        = $"<<sst<<endl;
    cout<<"Total tax per gallon of gas       = $"<<tt<<endl;
    cout<<"Percentage total taxes            =  "<<ptt<<"%"<<endl;
    cout<<"Percentage total oil comp profit  =  "<<ptp<<"%"<<endl;
    
    //Exit the program
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 19th, 2017, 12:32 PM
 * Purpose:  Math Tutor
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //For the power function
#include <iomanip>   //Formatting Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Set the Random Seed with Time
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    unsigned short op1,op2,stuAns,result;
    
    //Initialize variables
    op1=rand()%900+100;//[100-999]  3 Digit Random Number
    op2=rand()%900+100;//[100-999]  3 Digit Random Number
    
    //Prompt for the result
    cout<<"The program tests your addition capability"<<endl;
    cout<<"Type the answer"<<endl;
    cout<<setw(6)<<op1<<endl;
    cout<<"+"<<setw(5)<<op2<<endl;
    cout<<"------"<<endl;
    cin>>stuAns;
    
    //Calculate the result
    result=op1+op2;
    
    //Output the result
    cout<<"The result = "<<result<<endl;
    cout<<((result==stuAns)?"Correct":"Incorrect")<<endl;
 
    //Exit stage right!
    return 0;
}
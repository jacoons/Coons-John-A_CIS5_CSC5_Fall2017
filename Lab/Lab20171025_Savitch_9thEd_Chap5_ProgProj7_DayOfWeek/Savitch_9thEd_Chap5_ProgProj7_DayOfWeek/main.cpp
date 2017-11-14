/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 25th, 2017, 9:50 AM
 * Purpose:  Solve a date/day of week problem
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
unsigned char cnvMnth(string);
unsigned char cnvDay(string);
bool isLpYr(unsigned short);
unsigned char gtCntVl(unsigned short);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string month,day;
    unsigned short year;
    unsigned char nMonth,nDay;
    
    //Input Data/Variables
    do{
        cout<<"This program converts a date to a day"<<endl;
        cout<<"Input a date in the form mmmm dd, yyyy"<<endl;
        cout<<"For instance June 12, 1955"<<endl;
        cin>>month>>day>>year;
        nMonth=cnvMnth(month);
        nDay=cnvDay(day);
        cout<<"You input "<<static_cast<int>(nMonth)
                <<"/"<<static_cast<int>(nDay)
                <<"/"<<year<<endl;
    }while(nMonth==0||nDay>31);
    
    //Process or map the inputs to the outputs
    cout<<"Century Value 2008 = "<<
            static_cast<int>(gtCntVl(2008))<<endl;
    
    //Display/Output all pertinent variables
    
    //Exit the program
    return 0;
}

unsigned char gtCntVl(unsigned short year){
    return 2*(3-(year/100)%4);
}

bool isLpYr(unsigned short year){
    return ((year%400==0) || ((year%4==0) && year%100!=0));
}

unsigned char cnvDay(string day){
    char nDay=day[0]-'0';
    if(day[1]!=',')nDay=nDay*10+(day[1]-48);
    return nDay;
}

unsigned char cnvMnth(string month){
    if(month=="January")  return  1;
    if(month=="February") return  2;
    if(month=="March")    return  3;
    if(month=="April")    return  4;
    if(month=="May")      return  5;
    if(month=="June")     return  6;
    if(month=="July")     return  7;
    if(month=="August")   return  8;
    if(month=="September")return  9;
    if(month=="October")  return 10;
    if(month=="November") return 11;
    if(month=="December") return 12;
    return 0;
}
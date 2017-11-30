/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 18th, 2017, 9:05 AM
 * Purpose:  Menu with functions
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void menu();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int choice;
    //Loop the Menu and Problems
    do{
        //Input Data/Variables
        menu();
        cin>>choice;
        //Process or map the inputs to the outputs
        switch(choice){
            case 1:prob1();break;
            case 2:prob2();break;
            case 3:prob3();break;
            case 4:prob4();break;
            case 5:prob5();break;
            case 6:prob6();break;
            case 7:prob7();break;
            case 8:prob8();break;
            case 9:prob9();break;
            default:{
                cout<<"Exiting, have a great day!"<<endl;
            }
        }
    }while(choice>0&&choice<10);
    //Exit the program
    return 0;
}

void prob1(){
    cout<<"You are in Problem 1"<<endl;
}

void prob2(){
    cout<<"You are in Problem 2"<<endl;
}

void prob3(){
    cout<<"You are in Problem 3"<<endl;
}

void prob4(){
    cout<<"You are in Problem 4"<<endl;
}

void prob5(){
    cout<<"You are in Problem 5"<<endl;
}

void prob6(){
    cout<<"You are in Problem 6"<<endl;
}

void prob7(){
    cout<<"You are in Problem 7"<<endl;
}

void prob8(){
    cout<<"You are in Problem 8"<<endl;
}

void prob9(){
    cout<<"You are in Problem 9"<<endl;
}

void menu(){
    //Input Data/Variables
    cout<<"Choose from the Menu"<<endl;
    cout<<"1. Problem 1"<<endl;
    cout<<"2. Problem 2"<<endl;
    cout<<"3. Problem 3"<<endl;
    cout<<"4. Problem 4"<<endl;
    cout<<"5. Problem 5"<<endl;
    cout<<"6. Problem 6"<<endl;
    cout<<"7. Problem 7"<<endl;
    cout<<"8. Problem 8"<<endl;
    cout<<"9. Problem 9"<<endl;
}
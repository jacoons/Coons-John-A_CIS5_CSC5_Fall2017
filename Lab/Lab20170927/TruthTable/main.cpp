/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 26th, 2017, 9:05 PM
 * Purpose:  Confirm the Truth Table Results
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
    bool x,y;//Boolean Expressions
    
    //Display the Heading
    cout<<"X Y !X !Y X||Y X&&Y X^Y X^Y^Y X^Y^X "
        <<"!(X||Y) !X&&!Y !(X&&Y) !X||!Y"<<endl;
    
    //Initialize Variables for the First Row
    x=true;
    y=true;
    //Display the First Row
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x && y? 'T':'F')<<"    ";
    cout<<(x ^ y?'T':'F')<<"    ";
    cout<<((x ^ y)^y?'T':'F')<<"    ";
    cout<<((x ^ y)^x?'T':'F')<<"       ";
    cout<<(!(x || y)?'T':'F')<<"     ";
    cout<<(!x&&!y?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"  ";
    cout<<endl;

    //Initialize Variables for the Second Row
    x=true;
    y=false;
    //Display the First Row
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x && y? 'T':'F')<<"    ";
    cout<<(x ^ y?'T':'F')<<"    ";
    cout<<((x ^ y)^y?'T':'F')<<"    ";
    cout<<((x ^ y)^x?'T':'F')<<"       ";
    cout<<(!(x || y)?'T':'F')<<"     ";
    cout<<(!x&&!y?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"  ";
    cout<<endl;
    
    //Initialize Variables for the Third Row
    x=false;
    y=true;
    //Display the First Row
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x && y? 'T':'F')<<"    ";
    cout<<(x ^ y?'T':'F')<<"    ";
    cout<<((x ^ y)^y?'T':'F')<<"    ";
    cout<<((x ^ y)^x?'T':'F')<<"       ";
    cout<<(!(x || y)?'T':'F')<<"     ";
    cout<<(!x&&!y?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"  ";
    cout<<endl;
    
    //Initialize Variables for the Fourth Row
    x=false;
    y=false;
    //Display the First Row
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"  ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x && y? 'T':'F')<<"    ";
    cout<<(x ^ y?'T':'F')<<"    ";
    cout<<((x ^ y)^y?'T':'F')<<"    ";
    cout<<((x ^ y)^x?'T':'F')<<"       ";
    cout<<(!(x || y)?'T':'F')<<"     ";
    cout<<(!x&&!y?'T':'F')<<"       ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"  ";
    cout<<endl;
    
    
    //Exit the program
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 16th, 2017, 8:05 AM
 * Purpose:  Craps version 3
 *          Modified to add file-io
 *          Modified to include all language constructs
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cstdlib>      //Library set random number seed
#include <ctime>        //Libary to seed the random number generator
#include <iomanip>      //Format Library
#include <fstream>      //File Library
#include <string.h>     //String Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Initializing Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int  nRolls,chkWin,chkLoss,chkTot,nGames;
    int  w2s=0,w3s=0,w4s=0,w5s=0,w6s=0,w7s=0,
            w8s=0,w9s=0,w10s=0,w11s=0,w12s=0;//Wins vs. rolls
    int  l2s=0,l3s=0,l4s=0,l5s=0,l6s=0,l7s=0,
            l8s=0,l9s=0,l10s=0,l11s=0,l12s=0;//Losses vs. rolls
    const int SIZE=20;
    unsigned short mxRolls=0;
    char fileOut[SIZE]="crapOut.dat";
    string fileIn="crapIn.dat";
    ofstream out;
    ifstream in;
    
    //Initialize Variables
    nRolls=0;
    out.open(fileOut);
    in.open(fileIn.c_str());
    while(in>>nGames);
    nGames=nGames<36000?100000:nGames;
    
    //Process or map the inputs to the outputs
    for(unsigned int game=1;game<=nGames;game++){
        char die1=rand()%6+1;//[1,6]
        char die2=rand()%6+1;//[1,6]
        char sum=die1+die2;
        unsigned short cntRoll=1;
        nRolls++;//Increment Number of Rolls
        if(sum==7||sum==11){
            switch(sum){
                case 7:w7s++;break;
                case 11:w11s++;break;
            }
        }else if(sum==2||sum==3||sum==12){
            switch(sum){
                case 2:l2s++;break;
                case 3:l3s++;break;
                case 12:l12s++;break;
            }
        }else{
            bool loop;
            do{
                loop=true;
                char die1=rand()%6+1;//[1,6]
                char die2=rand()%6+1;//[1,6]
                char sum2=die1+die2;
                cntRoll++;
                nRolls++;//Increment Number of Rolls
                if(sum==sum2){
                    loop=false;
                    switch(sum){
                        case 4:w4s++;break;
                        case 5:w5s++;break;
                        case 6:w6s++;break;
                        case 8:w8s++;break;
                        case 9:w9s++;break;
                        case 10:w10s++;break;
                    }
                }else if(sum2==7){
                    loop=false;
                    switch(sum){
                        case 4:l4s++;break;
                        case 5:l5s++;break;
                        case 6:l6s++;break;
                        case 8:l8s++;break;
                        case 9:l9s++;break;
                        case 10:l10s++;break;
                    }
                }  
            }while(loop);
        }
        if(mxRolls<cntRoll)mxRolls=cntRoll;
    }
    
    //Calculate the totals
    chkWin=w2s+w3s+w4s+w5s+w6s+w7s+w8s+w9s+w10s+w11s+w12s;
    chkLoss=l2s+l3s+l4s+l5s+l6s+l7s+l8s+l9s+l10s+l11s+l12s;
    chkTot=chkWin+chkLoss;

    
    //Display/Output all pertinent variables
    out<<"Number of Games played  = "<<nGames<<endl;
    out<<"Number of Games checked = "<<chkTot<<endl;
    out<<"Number of Wins          = "<<chkWin<<endl;
    out<<"Number of losses        = "<<chkLoss<<endl;
    out<<"Percentage Wins         = "<<100.0f*chkWin/chkTot<<"%"<<endl;
    out<<"Percentage Losses       = "<<100.0f*chkLoss/chkTot<<"%"<<endl;
    out<<"Number of total rolls   = "<<nRolls<<endl;
    out<<"Maximum number of rolls in a game = "<<mxRolls<<endl;
    out<<"The average number of rolls per game = "<<1.0f*nRolls/nGames<<endl;
    out<<"Roll       Wins   Losses"<<endl;
    out<<"   2  "<<setw(9)<<w2s<<setw(9)<<l2s<<endl;
    out<<"   3  "<<setw(9)<<w3s<<setw(9)<<l3s<<endl;
    out<<"   4  "<<setw(9)<<w4s<<setw(9)<<l4s<<endl;
    out<<"   5  "<<setw(9)<<w5s<<setw(9)<<l5s<<endl;
    out<<"   6  "<<setw(9)<<w6s<<setw(9)<<l6s<<endl;
    out<<"   7  "<<setw(9)<<w7s<<setw(9)<<l7s<<endl;
    out<<"   8  "<<setw(9)<<w8s<<setw(9)<<l8s<<endl;
    out<<"   9  "<<setw(9)<<w9s<<setw(9)<<l9s<<endl;
    out<<"  10  "<<setw(9)<<w10s<<setw(9)<<l10s<<endl;
    out<<"  11  "<<setw(9)<<w11s<<setw(9)<<l11s<<endl;
    out<<"  12  "<<setw(9)<<w12s<<setw(9)<<l12s<<endl;
    
    //Display/Output all pertinent variables
    cout<<"Number of Games played  = "<<nGames<<endl;
    cout<<"Number of Games checked = "<<chkTot<<endl;
    cout<<"Number of Wins          = "<<chkWin<<endl;
    cout<<"Number of losses        = "<<chkLoss<<endl;
    cout<<"Percentage Wins         = "<<100.0f*chkWin/chkTot<<"%"<<endl;
    cout<<"Percentage Losses       = "<<100.0f*chkLoss/chkTot<<"%"<<endl;
    cout<<"Number of total rolls   = "<<nRolls<<endl;
    cout<<"Maximum number of rolls in a game = "<<mxRolls<<endl;
    cout<<"The average number of rolls per game = "<<1.0f*nRolls/nGames<<endl;
    cout<<"Roll       Wins   Losses"<<endl;
    cout<<"   2  "<<setw(9)<<w2s<<setw(9)<<l2s<<endl;
    cout<<"   3  "<<setw(9)<<w3s<<setw(9)<<l3s<<endl;
    cout<<"   4  "<<setw(9)<<w4s<<setw(9)<<l4s<<endl;
    cout<<"   5  "<<setw(9)<<w5s<<setw(9)<<l5s<<endl;
    cout<<"   6  "<<setw(9)<<w6s<<setw(9)<<l6s<<endl;
    cout<<"   7  "<<setw(9)<<w7s<<setw(9)<<l7s<<endl;
    cout<<"   8  "<<setw(9)<<w8s<<setw(9)<<l8s<<endl;
    cout<<"   9  "<<setw(9)<<w9s<<setw(9)<<l9s<<endl;
    cout<<"  10  "<<setw(9)<<w10s<<setw(9)<<l10s<<endl;
    cout<<"  11  "<<setw(9)<<w11s<<setw(9)<<l11s<<endl;
    cout<<"  12  "<<setw(9)<<w12s<<setw(9)<<l12s<<endl;
    
    //Close the file
    out.close();
    in.close();
    
    //Exit the program
    return 0;
}
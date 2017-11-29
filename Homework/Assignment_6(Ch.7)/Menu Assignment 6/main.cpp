/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 18th, 2017, 9:05 AM
 * Purpose:  Menu with functions
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <iomanip>
#include <fstream>
#include <string>


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
#define NumCols 30

#define NumRows 12
void readData(char data[NumRows][NumCols],string fileName)

{

ifstream inFile;

  



inFile.open(fileName);

  



if (!inFile)

{

cout << "Unable to open file";

exit(1); 

}



for(int i = 0; i < NumRows; i++)

{

for(int j = 0; j < NumCols; j++)

{

inFile >> data[i][j];

}

if ( !inFile ) break;

}

}



void generateReport(char data[NumRows][NumCols],int result[NumRows][5])

{



for(int i = 0; i < 12; i++)

{

for(int j = 0; j <5; j++)

{

result[i][j]=0;

}

}



for(int i = 0; i < NumRows; i++)

{

for(int j = 0; j < NumCols; j++)

{

if(data[i][j] == 'R')

result[i][0]++;

if(data[i][j] == 'F')

result[i][1]++;

if(data[i][j] == 'C')

result[i][2]++;

if(data[i][j] == 'S')

result[i][3]++;

if(data[i][j] == 'A')

result[i][4]++;

}

}

}



void displayReport(int result[NumRows][5])

{

string head[5] = {"Rainy","Flooding","Cloudy","Sunny","Armegeddon"};

string rowTitle[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};



cout<<"\t";

for(int i=0;i<5;i++)

cout<<head[i]<<"\t";

cout<<endl;



for(int i = 0; i < 12; i++)

{

cout<<rowTitle[i]<<"\t";

for(int j = 0; j < 5; j++)

{

if(j==2)

cout<<"\t";

cout<<result[i][j]<<"\t";

}

cout<<endl;

}



int max = result[0][3];

int month=0;

for(int i = 0; i < 12; i++)

{

if(max<result[i][3])

{

max = result[i][3];

month= i;

}

}

cout<<endl<<"The month with maximum number of Sunny days is: "<<rowTitle[month]<<" with "<<max<<" sunny days.";

}




//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int choice;
    double calculateTotalRainfall(double[], int);
double calculateAverageRainfall(double[], int);
double findHighestRainfall(double[], int, int &);
double findLowestRainfall(double[], int, int &);

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
       
            default:{
                cout<<"Exiting, have a great day!"<<endl;
            }
        }
    }while(choice>0&&choice<10);
    //Exit the program
    return 0;
}

void prob1(){
cout<<"Problem 1: Chips and Salsa"<<endl;
const int typesOfSalsa = 5;
const int stringSize = 7;
char salsa [typesOfSalsa][stringSize] = {"mild","medium","sweet","hot","zesty"};
int numOfJarsSold [typesOfSalsa];
int totalJarsOfSalsa = 0;
int highest;
int lowest;
for (int count = 0; count < typesOfSalsa; count++)
{
  cout<< "Enter the number of " <<salsa[count]<<" salsa jars sold in the past month: ";
  cin>> numOfJarsSold[count];
  while (numOfJarsSold[count]<0)
  {
   cout<< "Please enter a positive number: ";
   cin>> numOfJarsSold[count];
  }
  
  totalJarsOfSalsa += numOfJarsSold[count];
}

for (int count = 0; count < typesOfSalsa; count++)
{
  cout<< "Number of " <<salsa[count]<< " salsa jars sold in the past month: "<<numOfJarsSold[count]<<endl;
}
cout<<"Total number of jars sold in the past month: "<<totalJarsOfSalsa<<endl;

highest = numOfJarsSold[0];
for (int count =0; count < typesOfSalsa;count++)
{
  if (numOfJarsSold[count]> highest)
  {
   highest = numOfJarsSold[count];
  }
}
cout<<"The highest selling product is: "<<highest<<endl;
lowest = numOfJarsSold[0];
for (int count =0; count < typesOfSalsa;count++)
{
  if (numOfJarsSold[count] <lowest)
  {
   lowest = numOfJarsSold[count];
   
  }
  
}
cout<<"The lowest selling product is: "<<lowest<<endl;
system("pause");
}


void prob2(){
    cout<<"Problem 2: Largest Smallest Array Values"<<endl;
    const int size = 10;

   int small,large;

   int numberArray[size];

   //Inputting elements of array

   cout<<"Please enter 10 positive integers :"<<endl;

   for (int i=0;i<size;i++)

  {

   cin>>numberArray[i];

   }

//Assigning starting element to small,large

small=numberArray[0];

large=numberArray[0];

//Logic to find largest and smallest

for(int j=0;j<size;j++)

  {

      if(numberArray[j] >large)

         large = numberArray[j];

      if(numberArray[j]<small)

        small = numberArray[j];

  }

 

   cout<<"The smallest value is: "<<small<<endl;

   cout<<"The largest value is: "<<large<<endl;


}


void prob3(){
cout<<"Problem 3: Number Analysis Program"<<endl;
const int arraysize = 12;
int numbers[arraysize];
int count = 0;
ifstream inputfile;


inputfile.open("numbers.txt");

int highest,
    lowest;

double average;

int total=0;

while (count <arraysize && inputfile >> numbers[count])
{
    count++;
}
inputfile.close();


highest = numbers[0];
lowest = numbers [0];
for (count = 0; count < arraysize; count++)
{

    if (numbers[count] < lowest)
        lowest = numbers[count];

    else (numbers[count] > highest);
        highest = numbers[count];
}
for (count = 0; count < arraysize; count++)
{
    total += numbers[count];
}
average = total / arraysize;

cout << "The lowest number in the file is:          " << lowest;
cout << "\nThe highest number in the file is:         " << highest;
cout << "\nThe total of all numbers in the file is:   " << total;
cout << "\nThe average of all numbers in the file is: " << average << endl;
} 
    
    


void prob4(){
    cout<<"Problem 4: Rain or Shine"<<endl;
int i,j;

char data[NumRows][NumCols];



int result[12][5];



string fileName = "RainOrShine.txt";



readData(data,fileName);


generateReport(data,result);



displayReport(result);



}








void prob5(){
    cout<<"Problem 5: Rainfall Statistics"<<endl;
    const int TOTAL_MONTHS=12;
    
    double totalRainfall, averageRainfall, highestRainfall, lowestRainfall;
    int monthIndexHigh = 0, monthIndexLow =0;
    
    double monthlyRainfall[TOTAL_MONTHS];
    
    string namesOfMonths[TOTAL_MONTHS]={"January", "February", "March", 
    "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};
    
    for(int i=0; i<TOTAL_MONTHS;i++)
    {
        cout<<"Pleas enter the rainfall in "<<namesOfMonths[i]<<":";
        cin>>monthlyRainfall[i];
        while(monthlyRainfall[i]<0)
    {
        cout<<"Rainfall should be greater than or equal to 0."<<endl;
        cout<<"Please enter a valid number for rainfall in: "<<namesOfMonths[i]<<
                ": ";
        cin>>monthlyRainfall[i];
    }
}
}



void menu(){
    //Input Data/Variables
    cout<<"Choose from the Menu"<<endl;
    cout<<"Enter 0 to exit."<<endl;
    cout<<"1. Problem 1"<<endl;
    cout<<"2. Problem 2"<<endl;
    cout<<"3. Problem 3"<<endl;
    cout<<"4. Problem 4"<<endl;
    cout<<"5. Problem 5"<<endl;
  
    
}
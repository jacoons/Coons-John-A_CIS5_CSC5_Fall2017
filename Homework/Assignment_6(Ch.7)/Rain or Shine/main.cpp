#include<iostream>

#include <iomanip>

#include <fstream>

#include<string>

using namespace std;

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

int main()

{



int i,j;

char data[NumRows][NumCols];



int result[12][5];



string fileName = "RainOrShine.txt";



readData(data,fileName);


generateReport(data,result);



displayReport(result);

return 0;

}
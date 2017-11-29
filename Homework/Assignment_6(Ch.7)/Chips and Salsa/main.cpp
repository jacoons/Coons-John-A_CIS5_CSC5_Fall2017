
#include <iostream>
#include <iomanip>
using namespace std;
//main function
int main ()
{
//Variable declartion
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
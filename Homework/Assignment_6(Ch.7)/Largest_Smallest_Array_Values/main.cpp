#include<iostream>

using namespace std;

int main()

{

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

    // Displaying the smallest and largest values.

   cout<<"The smallest value is: "<<small<<endl;

   cout<<"The largest value is: "<<large<<endl;

   //To pause system for a while

   system("pause");

   return 0;

}//End main
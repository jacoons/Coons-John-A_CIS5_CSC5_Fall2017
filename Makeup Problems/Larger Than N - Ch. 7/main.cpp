#include <iostream>

using namespace std;

void printLargerElements(int *a, int size, int num);


int main()

{

     

     int a[50];

     int size;

     int num;

     

     cout<<"Enter the size of the array: ";

     cin>>size;

     cout<<"Enter the elements into the array: ";

   
     cout<<"Enter the elements into the array: "<<endl;

     for(int i=0;i<size;i++)

     {

          cout<<"a["<<(i+1)<<"]: ";

          cin>>a[i];

          cout<<endl;

     }

     

     cout<<"The elements entered are: "<<endl;

     for(int i=0;i<size;i++)

     {

          cout<<"["<<a[i]<<"] ";     

     }

     cout<<endl;

     

     cout<<"To print the array elements larger than the "

          <<"given number you need to enter a number."<<endl;

     cout<<"Enter a number: ";

     cin>>num;


    

     printLargerElements(a, size, num);

     system("pause");

     return 0;

}



void printLargerElements(int *a, int size, int num)

{

     cout<<"Elements that are larger than the number "<<num<<" are: "<<endl;

     for(int i=0;i<size; i++)

     {

          if(a[i]>num)

              cout<<"["<<a[i]<<"] ";

     }

     cout<<endl;

}
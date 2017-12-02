#include<iostream>
using namespace std;


void checkSquare(int a[][3]);


int main(int argc, char** argv)
{
int a[3][3];
cout<<"enter array elements"<<endl;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cout<<"Enter element of ("<<i<<","<<j<<"):";
cin>>a[i][j];
}
}
  
cout<<"Entered 2-D Matix is\n";
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}
  
checkSquare(a);

}

void checkSquare(int a[][3])
{
bool invalid=false;
for(int i=0;i<2;i++)
{
for(int j=0;j<2;j++)
{
if(a[i][j]<1||a[i][j]>9)
invalid = true;
}
}
  
if(invalid) {
cout<<"The given 2-D array is not Lo Shu Magic Square\n";
} else {

    
int diagonalSum=a[0][0]+a[1][1]+a[2][2];
     
  
   bool isValid=true;

     
   for(int i=0;i<3;i++)
   {
       int rowSum =0;
       for(int j=0;j<3;j++)
       {
       rowSum = rowSum+a[i][j];
       }
       if(rowSum!=diagonalSum)
       {
           isValid = false;  
           break;
       }
   }
  
 
   for(int i=0;i<3;i++)
   {
       int columnSum =0;
       for(int j=0;j<3;j++)
       {
       columnSum = columnSum+a[j][i];
       }
       if(columnSum!=diagonalSum)
       {
           isValid=false;
           break;
       }
   }
  
    if(isValid)
   {
           cout<<"The given 2-D array is Lo Shu Magic Square\n";
   } else {
           cout<<"The given 2-D array is not Lo Shu Magic Square\n";
   }
  
}
  
}
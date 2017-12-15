#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void print(char array[][16], int rows, int cols);
void Sort(char array[][16], int rows, int cols);

int main(){
ifstream infile("input.txt");
char array[10][16];
int i=0;
if(!infile){
cout <<"Unable to open the file.  Terminating the program."<<endl;
return 0;
}
while(!infile.eof()){
   infile >> array[i++];
}
cout << "Before Sorting " << endl;
print(array, 10, 15);
Sort(array, 10, 15);
cout << "\nAfter Sorting " << endl;
print(array, 10, 15);
return 0;
}

void print(char array[][16], int rows, int cols){
   for(int i=0; i<rows; i++){
       for(int j=0; j<cols; j++)
           cout << array[i][j];
           cout << endl;
   }
}
void Sort(char array[][16], int rows, int cols){
   char temp[16];
   for(int i=0; i<rows; i++){
       for(int j=i+1; j<rows; j++)
           if(strcmp(array[i], array[j])<0){
               strcpy(temp, array[i]);
               strcpy(array[i], array[j]);
               strcpy(array[j], temp);
           }
   }
}
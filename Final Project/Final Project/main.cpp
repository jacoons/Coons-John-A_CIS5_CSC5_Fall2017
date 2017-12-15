/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 18th, 2017, 9:05 AM
 * Purpose:  Menu with functions
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cstdlib> 
#include <ctime> 
#include <cmath>
#include<iomanip>
#include<vector>
#include<fstream>
#include<cstring>




using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
int prob1();
int prob2();
int prob3();
int prob4();
int prob5();
int prob6();
void menu();
void fillVec(vector<int>& V, bool isEven);
void prntVec(const vector<int>& V, int cols);
int indexFinder(int retrand[]);
int retrand (int);
void print(char array[][16], int rows, int cols);
void Sort(char array[][16], int rows, int cols);
int rowSum(int **arr, int row, int cols);
int colSum(int **arr, int rows, int col);
int grandSum(int **arr, int rows, int cols);
void print(int **arr, int rows, int cols);

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
            default:{
                cout<<"Exiting, have a great day!"<<endl;
            }
        }
    }while(choice>0&&choice<10);
    //Exit the program
    return 0;
}

int prob1(){
    cout<<"You are in Problem 1"<<endl;
    unsigned short int n;
short int reverse = 0;

cout << "Please enter an integer: ";
cin >> n;
if(n < 65535) 
{
while(n != 0) {
int remainder = n%10;
if((reverse*10 + remainder) > 32767)
{
cout << "no conversion possible"<< endl;
return 0;
}
reverse = reverse*10 + remainder;
n/=10;
}
cout << "Reversed number = " << reverse << endl;
}
else
{
cout << "no conversion possible"<< endl;
}
return 0;
}


int prob2(){
    cout<<"You are in Problem 2"<<endl;
    srand((int)time(0));
long long int X;
long long int guess;
char answer;

cout<<"Enter a number to set the RNG (X):"<<endl ;
cin>> X;
cout<<"Value of X : "<<X<<endl;
long long int range = pow(10,X);
long long int value = rand() % range + 1;
long long int maxGuess = log2(range);

cout<<"I have a number between 1 and "<<range<<endl;
cout << "You will be given a maximum of " << maxGuess << " guesses."<<endl;
cout<<"Please type your first guess below."<<endl;
        
for(long long int i=0;i<maxGuess;i++)
{
cout<<"Enter number(guess) between 1 and " << range << ": ";
cin>>guess;

if(value == guess )
{
cout<<"Congratulations, you guessed the number!"<<endl;
cout<<"Want to play again?"<<endl;
cin>>answer;
if(answer=='y')
{
    prob2();
}
return 0;
}
else if (guess < value)
{
cout<< "Too low. Try again."<<endl;
}
else
{
cout<< "Too high. Try again."<<endl;
}
}
cout<<"Too many tries."<<endl;

return 0;
}

int prob3(){
    cout<<"You are in Problem 3"<<endl;
    vector<int> V_even,V_odd;
   int size;
   int cols;

   cout <<"Enter vector size: ";
   cin >> size;
   V_even.resize(size);
   V_odd.resize(size);
   fillVec(V_even, true);
   fillVec(V_odd, false);
   
   cout <<"How many columns to display: ";
   cin >> cols;
   prntVec(V_even, cols); cout << endl;
   prntVec(V_odd, cols);cout << endl;
   return 0;
}

void fillVec(vector<int>& V, bool isEven){
   for(int i=0; i<V.size(); i++){
   int value =rand()%90+10;
       if(isEven && value %2==0)
       V[i] = value;
       else if(!isEven && value%2!=0)
       V[i] = value;
       else
       i--;
   }
}
void prntVec(const vector<int>& V, int cols){
   for(int i=0 ;i<V.size(); i++){
       cout << V[i] << " ";
       if( (i+1)%cols == 0) cout << endl;
   }
}

int prob4(){
    cout<<"You are in Problem 4"<<endl;
     srand(static_cast<int>(time(0)));
    const int n=5,ntimes=10000;
    int freq[n]={0};
    const int rndseq[n]={18,61,88,101,121};
    
     for(int i = 0; i < ntimes; i++)
     {
       int index = retrand(n); 
       freq[index]++; 
     }

   for(int i = 0; i < n; i++) 
   cout<<rndseq[i]<<" occurred "<< freq[i]<<" times."<<endl;
     
   return 0;
   }                               
int retrand(int n){
    return rand() % n; 
}

int prob5(){
    cout<<"You are in Problem 5"<<endl;
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

int prob6(){
    cout<<"You are in Problem 6"<<endl;
     int rows = 6, cols = 7;
   int **arr = new int*[rows];
   string fName;
   ifstream in;
   ofstream out;
   in.open("tablein.txt");
   out.open("tableout.txt");
   if(in.is_open() && out.is_open()){
       for(int i = 0; i < rows; ++i){
           arr[i] = new int[cols];
           for(int j = 0; j < cols - 1; ++j){
               if(i != rows - 1){
                   in >> arr[i][j];
               }
           }
       }
       print(arr, rows - 1, cols - 1);
       for(int i = 0; i < rows - 1; ++i){
           arr[i][cols - 1] = rowSum(arr, i, cols - 1);
       }
       for(int i = 0; i < cols - 1; ++i){
           arr[rows - 1][i] = colSum(arr, rows - 1, i);
       }
       arr[rows - 1][cols - 1] = grandSum(arr, rows - 1, cols - 1);
       print(arr, rows, cols);
       for(int i = 0; i < rows; ++i){
           for(int j = 0; j < cols; ++j){
               out << arr[i][j] << "\t";
           }
           out << endl;
       }
   }
   else{
       cout << "Can not open the file" << endl;
   }
   return 0;
}

int rowSum(int **arr, int row, int cols){
   int sum = 0;
   for(int i = 0; i < cols; ++i){
       sum += arr[row][i];
   }
   return sum;
}

int colSum(int **arr, int rows, int col){
   int sum = 0;
   for(int i = 0; i < rows; ++i){
       sum += arr[i][col];
   }
   return sum;
}

int grandSum(int **arr, int rows, int cols){
   int sum = 0;
   for(int i = 0; i < rows; ++i){
       for(int j = 0; j < cols; ++j){
           sum += arr[i][j];
       }
   }
   return sum;
}

void print(int **arr, int rows, int cols){
   for(int i = 0; i < rows; ++i){
       for(int j = 0; j < cols; ++j){
           cout << arr[i][j] << " ";
       }
       cout << endl;
   }
   cout << endl;
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
    cout<<"Enter '0' to exit."<<endl;
    }
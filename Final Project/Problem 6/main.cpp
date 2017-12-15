#include <iostream>
#include <fstream>

using namespace std;

int rowSum(int **arr, int row, int cols);
int colSum(int **arr, int rows, int col);
int grandSum(int **arr, int rows, int cols);
void print(int **arr, int rows, int cols);

int main(){
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
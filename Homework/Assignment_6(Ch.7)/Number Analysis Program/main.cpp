#include <iostream>
#include <fstream>
using namespace std;

int main()

//Number Analysis Program

{
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

#include <iostream>
#include <string> 
using namespace std;


void sortArray(string [], int); 
int binarySearch(string [], int, string);
const int SIZE = 20;

int main()
{
   
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                               "Looney, Joe", "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };

   
    string empName; 
    int results;  

   
    sortArray(names, NUM_NAMES); 

    
    cout << "Please enter an employee's name: "; 
    getline(cin, empName); 

    
    results = binarySearch(names, NUM_NAMES, empName); 

   
    if (results == -1)
        cout << "That name does not exist in the array.\n";
    else
    {
     
        cout << "That name is found at element " << results;
        cout << " in the array.\n";
    }

    system("PAUSE"); 

    return 0;
}

void sortArray(string names[], int size)
{
    int startScan, minIndex; 
    string minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

int binarySearch(string names[], int size, string value)
{
    int first = 0,             
        last = size - 1,       
        middle,                
        position = -1;         
    bool found = false;     

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     
        if (names[middle] == value)      
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)  
            last = middle - 1;
        else
            first = middle + 1;           
    }
    return position;
}
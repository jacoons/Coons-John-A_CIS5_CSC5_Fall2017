#include <string> 
#include <iomanip>
#include <iostream>     //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void menu();

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

void Linear_search (int array[], int NUM_ELS)
    {
        int charge_num;
        bool found = false;
        cout<<"Enter account charge number: "<<endl;
        cin>>charge_num;
        for(int i = 0; i<NUM_ELS; i++)
        {
            if(array[i] == charge_num)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            cout<<"Number is valid."<<endl;
        }
        else
        {
            cout<<"Number is not valid."<<endl;
        }
    }

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
            case 7:prob7();break;
            case 8:prob8();break;
            case 9:prob9();break;
            default:{
                cout<<"Exiting, have a great day!"<<endl;
            }
        }
    }while(choice>0&&choice<10);
    //Exit the program
    return 0;
}

void prob1(){
    cout<<"Problem 1 - Binary String Search"<<endl;
    
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

    
    cout << "Please enter an employee's name: "<<endl; 
   
    std::string str;
    std::getline(cin, str);
    getline(cin, empName); 
  

    
    results = binarySearch(names, NUM_NAMES, empName); 

   
    if (results == -1)
        cout << "That name does not exist in the array.\n";
    else
    {
     
        cout << "That name is found at element " << results;
        cout << " in the array.\n";
    }
    
    //system("PAUSE");
    
}

     


void prob2(){
    cout<<"Problem 2 - Charge Account Validation"<<endl;
    int NUM_ELS = 18;
    const int ARRAY_SIZE = 18;
    int array [ARRAY_SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277,
    1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 
    6545231, 3852085, 7576651, 7881200, 4581002};
    
    Linear_search(array, NUM_ELS);
    
    
}

void prob3(){
    cout<<"You are in Problem 3"<<endl;
}

void prob4(){
    cout<<"You are in Problem 4"<<endl;
}

void prob5(){
    cout<<"You are in Problem 5"<<endl;
}

void prob6(){
    cout<<"You are in Problem 6"<<endl;
}

void prob7(){
    cout<<"You are in Problem 7"<<endl;
}

void prob8(){
    cout<<"You are in Problem 8"<<endl;
}

void prob9(){
    cout<<"You are in Problem 9"<<endl;
}

void menu(){
    //Input Data/Variables
    cout<<"Assignment 7 - Chapter 8"<<endl;
    cout<<"Choose from the Menu"<<endl;
    cout<<"1. Problem 1: \tBinary String Search"<<endl;
    cout<<"2. Problem 2: \tCharge Account Validation"<<endl;
    cout<<"3. Problem 3: \tLottery Winners"<<endl;
    cout<<"4. Problem 4: \tLottery Winners Modification"<<endl;
    cout<<"5. Problem 5: \tRainfall Statistics Modification"<<endl;
    cout<<"6. Problem 6: \tSorting Orders"<<endl;

}
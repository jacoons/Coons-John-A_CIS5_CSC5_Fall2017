#include <string> 
#include <iomanip>
#include <iostream>     //Input/Output Stream Library

#define SIZE 10
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

bool searchWinner(int [], int, int);
void sortArray(string [], int); 
int binarySearch(string [], int, string);
void Linear_search (int[], int);
bool searchWinner2(int [], int, int);
void sortHigh2Low(int [], string[]);
void BubbleSort(int arr[], int);
void SelectionSort(int arr[], int);

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

     


void prob2(){
    cout<<"Problem 2 - Charge Account Validation"<<endl;
    int NUM_ELS = 18;
    const int ARRAY_SIZE = 18;
    int array [ARRAY_SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277,
    1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 
    6545231, 3852085, 7576651, 7881200, 4581002};
    
    Linear_search(array, NUM_ELS);
    
    
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

void prob3(){
    cout<<"Problem 3 - Lottery Winners"<<endl;
    
    int winNum[10]={13579, 26791, 26792, 33445, 55555, 62483, 77777, 
    79422, 85647, 93121};
    
    int playNum;
    
    cout<<"Please enter your number: "<<endl;
    cin>>playNum;
    
    bool result = searchWinner(winNum,SIZE,playNum);
    
    if(result)
        cout<<"You have one of the winning numbers!"<<endl;
    else
        cout<<"Your number is not a winning number!"<<endl;
    
}
bool searchWinner(int winNum[], int size, int playNum)
{
    bool found = false;
    int index = 0;
    
    while(index<size&!found)
    {
        if(winNum[index]==playNum)
            found=true;
        index++;
    }
    
    return found;
    }


void prob4(){
    cout<<"Problem 4 - Lottery Winners Modification"<<endl;
    int winNum[10]={13579, 26791, 26792, 33445, 55555, 62483, 77777, 
    79422, 85647, 93121};
    
    int playNum;
    
    cout<<"Please enter your number: "<<endl;
    cin>>playNum;
    
    bool result = searchWinner2(winNum,SIZE,playNum);
    
    if(result)
        cout<<"You have one of the winning numbers!"<<endl;
    else
        cout<<"Your number is not a winning number!"<<endl;
    
   
    
}

bool searchWinner2(int winNum[], int size, int playNum)
{
    int first=0, last=size-1, middle;
    
    bool found=false;
    
    while(!found && first<=last)
    {
        middle=(first+last)/2;
        
        if(winNum[middle]==playNum)
            found=true;
        else if(winNum[middle]>playNum)
            last=middle-1;
        else
            first = middle+1;
       
    }
    
    return found;
}

const int N_MONTHS = 12;
void prob5(){
    cout<<"Problem 5 - Rainfall Statistics Modification"<<endl;
    int values[N_MONTHS];
    
    string p_months[N_MONTHS] = {"January", "February", "March", "April",
    "May", "June", "July", "August", "September", "October",
    "November", "December"};
    
    for(int month=0;month<N_MONTHS;month++)
    {
        do{
            cout<<"Enter the total rainfall for "<<p_months[month]<<":";
            
            cin>>values[month];
            
            if(values[month]<0)
                cout<<"Enter positive rain fall statistics"<<endl;
        }while(values[month]<0);
    }
    cout<<"Before sorting "<<endl;
    
    for(int month=0;month<N_MONTHS;month++)
        cout<<setw(10)<<p_months[month]<<setw(10)<<values[month]<<endl;
    
    sortHigh2Low(values,p_months);
    
    cout<<"After sorted in order of rainfall "<<endl;
    cout<<"From highest to lowest "<<endl;
    
    for(int month=0;month<N_MONTHS;month++)
        cout<<setw(10)<<p_months[month]<<setw(10)<<values[month]<<endl;
    
   
}

void sortHigh2Low(int values[],string p_months[])
{
    bool swap;
    int temp;
    
    do
    {
        
        swap=false;
        for(int count=0;count<N_MONTHS;count++)
        {
            if(values[count]<values[count+1])
            {
                temp=values[count];
                values[count]=values[count+1];
                values[count+1]=temp;
                
                string tempString=p_months[count];
                p_months[count]=p_months[count+1];
                p_months[count+1]=tempString;
                swap=true;
                
            }
        }
    }while(swap);
}
    

void prob6(){
    cout<<"Problem 6 - Sorting Orders"<<endl;
    int array1[8]={5,1,4,6,3,8,2,7};
    int array2[8]={5,1,4,6,3,8,2,7};
    int i;
    
    cout<<"contents of the first array: "<<endl;
    for(i=0;i<8;i++)
        cout<<" "<<array1[i];
    cout<<endl;
    
    BubbleSort(array1, 8);
    cout<<"Contents of the second array: "<<endl;
    for(i=0;i<8;i++)
        cout<<" "<<array2[i];
    cout<<endl;
    
    SelectionSort(array2,8);
}

void BubbleSort(int array[], int size)
{
    bool swap;
    int temp;
    cout<<"Bubble Sort"<<endl;
    do
    {
        swap=false;
        for(int count=0; count<(size-1); count++)
        {
            if (array[count]>array[count+1])
            {
                temp=array[count];
                array[count]=array[count+1]=temp;
                swap=true;
            }
        }
        for(int i=0;i<size;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }while(swap);
}

void SelectionSort(int array[], int size)
{
    int startScan, minIndex, minValue;
    cout<<"Selection Sort: "<<endl;
    for(startScan=0; startScan<(size-1); startScan++)
    {
        minIndex=startScan;
        minValue=array[startScan];
        for(int index=startScan+1;index<size;index++)
        {
            if(array[index]<minValue)
            {
                minValue=array[index];
                minIndex=index;
            }
        }
        array[minIndex]=array[startScan];
        array[startScan]=minValue;
        
        for(int i=0;i<size;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
}



void menu(){
    //Input Data/Variables
    cout<<"Assignment 7 - Chapter 8"<<endl;
    cout<<"Choose from the Menu"<<endl;
    cout<<endl;
    cout<<"1. Problem 1: \tBinary String Search"<<endl;
    cout<<"2. Problem 2: \tCharge Account Validation"<<endl;
    cout<<"3. Problem 3: \tLottery Winners"<<endl;
    cout<<"4. Problem 4: \tLottery Winners Modification"<<endl;
    cout<<"5. Problem 5: \tRainfall Statistics Modification"<<endl;
    cout<<"6. Problem 6: \tSorting Orders"<<endl;
    cout<<endl;
    cout<<"Enter '0' to exit."<<endl;

}
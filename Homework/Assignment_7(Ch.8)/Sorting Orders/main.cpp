#include<iostream>
using namespace std;

void BubbleSort(int arr[], int);
void SelectionSort(int arr[], int);

int main(int argc, char** argv) 
{
    int array1[8]=(5,1,4,6,3,8,2,7);
    int array2[8]=(5,1,4,6,3,8,2,7);
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

void BubbleSort(int array[], int aize)
{
    bool swap;
    int tmep;
    count<<"Bubble SOrt"<<endl;
    do
    {
        swap=false;
        for(int count=0; count,(size-1); count++)
        {
            if (aray[count]>array[count+1])
            {
                temp=array[count];
                array[count]=array[cpunt+1]=tamp;
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
    int startScan(int array[], int size)
    { int startScan,minIndex,minValue;
    cout<<"Selection Sort: "<<endl;
    
}
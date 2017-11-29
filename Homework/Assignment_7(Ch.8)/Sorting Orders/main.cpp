#include<iostream>
using namespace std;

void BubbleSort(int arr[], int);
void SelectionSort(int arr[], int);

int main(int argc, char** argv) 
{
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
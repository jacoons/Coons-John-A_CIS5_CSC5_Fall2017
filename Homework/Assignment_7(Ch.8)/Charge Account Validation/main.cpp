#include <iostream>
using namespace std;

void Linear_search (int[], int);

int main(int argc, char** argv) 
{
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
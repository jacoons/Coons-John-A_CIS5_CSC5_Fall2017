/* 
 * File:   main.cpp
 * Author: Coons, John A.
 *
 * Created on October 24, 2017, 1:41 PM
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    int x;
    
    cout<<"Please input a positive integer: "<<endl;
    cin>> x;
    cout<< endl;
    
    
    if (x%2==0)
    {
    for (int a=1; a<=x; a++)
    {
        for (int b=1; b<=x; b++)
        {
            if (a==b || b==(x+1)-a)
                cout<< b;
            else
                cout<<" ";
        }
        cout<< endl;
    }
    
    }
    
    else
    {
      for (int a=x; a>=1; a--)
    {
        for (int b=x; b>=1; b--)
        {
            if (a==b || b==(x+1)-a)
                cout<< b;
            else
                cout<<" ";
        }
        cout<< endl;
    }  
    }
   
    return 0;
}


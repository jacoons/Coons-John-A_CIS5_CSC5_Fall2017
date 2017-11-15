#include <iostream>
using namespace std;

float fallingDistance(int);

int main(int argc, char** argv) 
{
    float distance;
    int time;
    
    for(time=1; time<=10; time++)
    {
        distance=fallingDistance(time);
        cout<<"The distance at "<<time<<" seconds "<<"is "
                <<distance<<" meters."<<endl;
    }
}

float fallingDistance(int time)
{
    float g=9.8, distance;
    distance=static_cast<float>(0.5*g*time*time);
    return distance;
}
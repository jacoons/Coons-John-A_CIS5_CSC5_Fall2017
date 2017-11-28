#include <iostream>
using namespace std;

float kineticEnergy(float,float);

int main(int argc, char** argv) 
{
    float ke, mass, velocity;    
    mass = 0;
    velocity = 0;
    
    ke = kineticEnergy(mass, velocity);
    
    cout<<"The object's kinetic energy is "<<ke<<" meters per second squared."
            <<endl;
}

float kineticEnergy(float mass, float velocity)
{
    cout<<"Please enter the mass of the object(in kilograms): ";
    cin>>mass;
    
    
    cout<<"Please enter the velocity of the object(in meters per second): ";
    cin>>velocity;
    
    float ke;
    
    ke = (0.5*mass*velocity*velocity);
    return ke;
}
            
    

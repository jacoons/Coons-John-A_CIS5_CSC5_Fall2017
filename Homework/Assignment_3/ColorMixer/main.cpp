#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    string color1, color2;
    
    cout<<"Enter a primary color: "<<endl;
    cin>> color1;
      
    cout<<"Enter a primary color: "<<endl;
    cin>> color2;
    
    if ((color1 == "red" || color1 == "blue" || color1 == "yellow") &&
        (color2 == "red" || color2 == "blue" || color2 == "yellow"))
        
    {
        
    if ((color1 == "red" && color2=="blue") ||
       (color2 == "red" && color1 == "blue"))
        cout<<"Those two colors create the color purple."<<endl;
    
    else if ((color1 == "red" && color2 == "yellow") ||
            (color2 == "red" && color1 == "yellow"))
        cout<<"These two colors create orange."<<endl;
    
    else if ((color1 == "blue" && color2 == "yellow") ||
            (color2 == "blue" && color1 == "yellow"))
        cout<<"These two colors create green."<<endl;
    
    else
        cout<<"Secondary color is: "<<color1;
    
    }
    
    else
    {
        cout<<"INVALID ENTRY!!"<<endl;
    }
    

    return 0;
}



#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    float h, w, BMI;
    
    cout<<"Enter your height in inches and rounded to the "
            "nearest half inch: "<<endl;
    cin>> h;
    
    cout<<"Enter your weight in pounds: "<<endl;
    cin>> w;
    
    BMI = (703/(h*h))*w;
    
    cout<<"Your Body Mass Index(BMI) is: "<<BMI<<"."<<endl;
 
    if (BMI < 18.5)
        cout<<"You need to eat a cheeseburger.  Your BMI is\n"
                "lower than the optimal minimum of 18.5."<<endl;
    
    if (BMI >25)
        cout<<"You need to lay off of the cheeseburgers.\n"
              "Your BMI is higher than the optimal maximum of 25."<<endl;
    
   
    if (BMI >= 18.5 && BMI<=25)
        cout<<"Your BMI is within optimal range!!!"<<endl;
     
    
    return 0;
}


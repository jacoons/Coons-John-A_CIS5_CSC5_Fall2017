#include <iostream>
using namespace std;

void getScore(double &score);
double findLowest(double, double, double, double, double);
void calcAverage(double, double, double, double, double);


int main(int argc, char** argv) 
{
    double test1, test2, test3, test4, test5;
    
    cout<<"Please enter five test scores: "<<endl;
    
    getScore(test1);
    getScore(test2);
    getScore(test3);
    getScore(test4);
    getScore(test5);
    
    calcAverage(test1, test2, test3, test4, test5);
}

void getScore(double &score)
{
    cin>>score;
    while(score<0||score>100)
    {
        cout<<"ERROR!! Please re-enter the test score: "<<endl;
        cin>>score;
    }
    }

void calcAverage(double a, double b, double c, double d, double e)
{
    double low, sum, sum4, avg;
    
    low=findLowest(a,b,c,d,e);
    
    sum=a+b+c+d+e;
    sum4=(a+b+c+d+e)-low;
    avg=sum4/4;
            
    
    
    
    cout<<"Average of the four highest test scores is: "<<avg<<".";
}
   
double findLowest(double a, double b, double c, double d, double e)
{
    double low;
               
    if(a<b&&a<c&&a<d&&a<e){
        return a;
    }
    if(b<a&&b<c&&b<d&&b<e){
        return b;
    }
        if(c<a&&c<b&&c<d&&c<e){
            return c;
        }
            if(d<a&&d<b&&d<c&&d<e){
                return d;
            }
                if(e<a&&e<b&&e<c&&e<d){
                    return e;}
                
    
    
    

    
}


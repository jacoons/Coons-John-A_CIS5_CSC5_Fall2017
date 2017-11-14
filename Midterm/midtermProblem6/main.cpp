#include <iostream>
#include <cmath>

using namespace std;


int factorial(int n)
{
    
    if(n<=1)
        return 1;

   
    return n * factorial(n-1);
}


double sequence(double x, int n)
{
    int i, j=0;

    double result = 0;

    
    for(i=1; i<=n; i=i+2, j++)
    {
        
        result += ( pow((double)(-1), j) * ( (pow(x, i)) ) ) / 
                ( (double)(factorial(i)) );
    }

    
    return result;
}


int main()
{
    int n;
    double x;

    double result;

 
    cout << "\n\n Enter value for x: ";
    cin >> x;

    
    cout << "\n\n Enter value for n: ";
    cin >> n;

   
    result = sequence(x, n);

 
    cout << "\n\n Value of sequence = " << result << "\n\n";

    cout << "\n";
    return 0;
}
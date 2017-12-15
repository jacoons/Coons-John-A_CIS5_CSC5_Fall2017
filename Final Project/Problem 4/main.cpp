#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;  
 
int indexFinder(int retrand[]);
int retrand (int);

int main(int argc, char** argv){
    srand(static_cast<int>(time(0)));
    const int n=5,ntimes=10000;
    int freq[n]={0};
    const int rndseq[n]={18,61,88,101,121};
    
     for(int i = 0; i < ntimes; i++)
     {
       int index = retrand(n); 
       freq[index]++; 
     }

   for(int i = 0; i < n; i++) 
   cout<<rndseq[i]<<" occurred "<< freq[i]<<" times."<<endl;
     
   return 0;
   }                               
int retrand(int n){
    return rand() % n; 
}
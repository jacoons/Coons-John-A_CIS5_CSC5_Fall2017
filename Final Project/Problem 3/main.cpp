#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

void fillVec(vector<int>& V, bool isEven);
void prntVec(const vector<int>& V, int cols);


int main(){
   vector<int> V_even,V_odd;
   int size;
   int cols;

   cout <<"Enter vector size: ";
   cin >> size;
   V_even.resize(size);
   V_odd.resize(size);
   fillVec(V_even, true);
   fillVec(V_odd, false);
   
   cout <<"How many columns to display: ";
   cin >> cols;
   prntVec(V_even, cols); cout << endl;
   prntVec(V_odd, cols);cout << endl;
   return 0;
}

void fillVec(vector<int>& V, bool isEven){
   for(int i=0; i<V.size(); i++){
   int value =rand()%90+10;
       if(isEven && value %2==0)
       V[i] = value;
       else if(!isEven && value%2!=0)
       V[i] = value;
       else
       i--;
   }
}
void prntVec(const vector<int>& V, int cols){
   for(int i=0 ;i<V.size(); i++){
       cout << V[i] << " ";
       if( (i+1)%cols == 0) cout << endl;
   }
}

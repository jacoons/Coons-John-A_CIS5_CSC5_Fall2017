#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   int count_1, count_2, placeH, conv;
   char num[4];
   cout << "Enter a 4 digit number : ";
   cin >> num;
   
   conv = atoi(num);
   
   if(conv%2==0)
   
   {
   
   
      for(count_1 = 3; count_1 >= 0; count_1--)
          {
       if(num[count_1] >= '0' && num[count_1] <= '9')
       {
           placeH = num[count_1] - '0';
           cout<< placeH<<" ";
      
           for(count_2 = 0; count_2 < placeH; count_2++)
           {
               cout << "*";
           }
            }
      
       else
       {
           cout <<num[count_1]<<" NAN";
       }
       cout << endl;
          
      }
   }
   
   
   
   
   else
   {
         for(count_1 = 3; count_1 >= 0; count_1--)
          {
       if(num[count_1] >= '0' && num[count_1] <= '9')
       {
           placeH = num[count_1] - '0';
           cout<< placeH<<" ";
      
           for(count_2 = 0; count_2 < placeH; count_2++)
           {
               cout << placeH;
           }
            }
      
       else
       {
           cout <<num[count_1]<<" NAN";
       }
       cout << endl;
          
      }
   }
       
   
 
         
   return 0;
}
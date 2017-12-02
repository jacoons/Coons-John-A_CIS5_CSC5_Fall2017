#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char letterGrade(double score);

int main( )
{
   char names[5][25]; 
   char grades[5]; 
   double scores[5][4]; 
   double avgScore[5]; 
   

   for(int i=0;i<5;i++)
   {
      cout<<"\nEnter student "<<(i+1)<<" name: ";
      cin>>names[i];
      cout<<"Enter his 4 scores: ";
      for(int j=0;j<4;j++)
      {
            cin>>scores[i][j];
     
            while(scores[i][j] > 100 || scores[i][j] <0)
            {
               cout<<"\ntest score should between 0 and 100"<<endl;
               cout<<"enter test score: ";
                  cin>>scores[i][j];
            }
         }
      }
      
      int low=0;
      for(int i=0;i<5;i++)
      {
           low=scores[i][0];
            avgScore[i] = 0;
            for(int j=0;j<4;j++)
            {
                 if(low<scores[i][j])
                      low=scores[i][j];
                 avgScore[i] += scores[i][j];
            }
            avgScore[i]-=low;
            avgScore[i]/=3;
            grades[i] = letterGrade(avgScore[i]);
         }
         
         cout<<"\nStudent Name\tAverage Score\tLetter Grade"<<endl;
         for(int i=0;i<5;i++)
         {
            cout.setf(ios::fixed,ios::floatfield);
            cout.precision(2);
               cout<<names[i]<<"\t\t"<<setprecision(2)<<avgScore[i]<<"\t\t"<<grades[i]<<endl;
          }
         
         system("PAUSE");
         return 0;
      }
     
      char letterGrade(double score)
      {
         if(score >= 90 && score <=100)
            return 'A';
         else if(score >= 80 && score <90)
               return 'B';
         else if(score >= 70 && score <80)
               return 'C';
            else if(score >= 60 && score <70)
                 return 'D';
            else
        return 'F';
}
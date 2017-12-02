

#include <iostream>

#include <iomanip>

#include<math.h>



using namespace std;



void getJudgeData(int &someValue);



double calcScore(int la, int lb, int lc, int ld, int le);



int findLowest(int aa, int bb, int cc, int dd, int ee);



int findHighest(int aaa, int bbb, int ccc, int ddd, int eee);



int main ()

{  

     

     int scores, ljudge1,ljudge2,ljudge3,ljudge4,ljudge5;

   

     double avgValue;

     getJudgeData(scores);

   

     ljudge1 = scores;

     cout <<ljudge1 << endl;


     getJudgeData(scores);


     ljudge2 = scores;


     cout <<ljudge2 << endl;

   

     getJudgeData(scores);

    

     ljudge3 = scores;

     

     cout <<ljudge3 << endl;

     

     getJudgeData(scores);

     

     ljudge4 = scores;

 

     cout <<ljudge4 << endl;

     

     getJudgeData(scores);

     

     ljudge5 = scores;

    

     cout <<ljudge5 << endl;

     

avgValue = calcScore(ljudge1,ljudge2,ljudge3,ljudge4,ljudge5);

  

cout <<"Average after removal of highest & lowest value " <<avgValue<<endl;

    

     system("pause");

    

     return 0;

}



void getJudgeData(int &someValue)

{  

    

     cout << "Enter input of your score from 1-10: ";

     

     cin >> someValue;

     

     if (someValue < 1 || someValue > 10)

     {

        

          cout << "Please enter la valid score from 1-10: ";

          

          cin >> someValue;

     }

     

     else

     {

         

          someValue;

     }

}


double calcScore(int la, int lb, int lc, int ld, int le)

{

     

     double rtValue;


     double lLow = findLowest(la, lb, lc, ld, le);

     

     double lHigh = findHighest(la, lb, lc, ld, le);

     cout<<"Low score is "<<lLow<<endl;

     

     cout<<"High score is "<<lHigh<<endl;

   

rtValue = ((la + lb + lc + ld + le) - (lLow + lHigh)) / 3;



     return rtValue;

}



int findLowest (int aa, int bb, int cc, int dd, int ee)

{  

     

     int lowestScore;

     

     if ((aa < bb) && (aa < cc) && (aa < dd) && (aa < ee))

     {

          lowestScore = aa;

     }

     

else if ((bb < aa) && (bb < cc) && (bb < ee) && (bb < ee))

     {

          

          lowestScore = bb;

     }

  

else if ((cc < aa) && (cc < bb) && (cc < dd) && (cc < ee))

     {

       
          lowestScore = cc;

     }



else if ((dd < aa) && (dd < bb) && (dd < cc) && (dd < ee))

     {

        

          lowestScore = dd;

     }

    

else if ((ee < aa) && (ee < bb) && (ee < cc) && (ee < dd))

     {

        

          lowestScore = ee;

     }

     

     return lowestScore;

}



int findHighest (int aaa, int bbb, int ccc, int ddd, int eee)

{

     

     int highestScore = 0;



if ((aaa > bbb) && (aaa > ccc) && (aaa > ddd) && (aaa > eee))

     {

      

          highestScore = aaa;

     }

 

else if ((bbb > aaa) && (bbb > ccc) && (bbb > eee) && (bbb > eee))

     {

          

          highestScore = bbb;

     }

   

else if ((ccc > aaa) && (ccc > bbb) && (ccc < ddd) && (ccc > eee))

     {

        

          highestScore = ccc;

     }

  

else if ((ddd > aaa) && (ddd > bbb) && (ddd > ccc) && (ddd > eee))

     {

        

          highestScore = ddd;

     }

   

else if ((eee > aaa) && (eee > bbb) && (eee > ccc) && (eee > ddd))

     {

      

          highestScore = eee;

     }

     

     return highestScore;

}
#include <string>
#include <iomanip>
#include <iostream>     //Input/Output Stream Library
#include<cmath>
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants
const int NUM_MONKEYS = 3;  
const int NUM_DAYS = 7;  
//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();
void prob11();
void prob12();
void menu();
int coinToss();
void inputAnswers(char *inAnswers);
int checkAnswers(char inAnswers[]);
void displayResult(int correctAns);
char letterGrade(double score);
char letterGrade2(double score);
void printLargerElements(int *a, int size, int num);
void checkSquare(int a[][3]);
void generateLotteryNumber(int lottery[], int n);
void getUserNumbers(int user[], int n);
void display(int arr[], int n);
int matchCount(int lottery[], int user[], int n);
void fillArray (float [][NUM_DAYS], int);
void showArray (float [][NUM_DAYS], int, float, float, float);
float calcMax  (float [][NUM_DAYS], int);
float calcMin  (float [][NUM_DAYS], int);
float calcAvg  (float [][NUM_DAYS], int);
double presentValue(double F, double r, double n);
int getNumAccidents(char *);
void findLowest(double, double, double, double, double);
void getJudgeData(int &someValue);
double calcScore(int la, int lb, int lc, int ld, int le);
int findLowest(int aa, int bb, int cc, int dd, int ee);
int findHighest(int aaa, int bbb, int ccc, int ddd, int eee);


//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int choice;
    //Loop the Menu and Problems
    do{
        //Input Data/Variables
        menu();
        cin>>choice;
        //Process or map the inputs to the outputs
        switch(choice){
            case 1:prob1();break;
            case 2:prob2();break;
            case 3:prob3();break;
            case 4:prob4();break;
            case 5:prob5();break;
            case 6:prob6();break;
            case 7:prob7();break;
            case 8:prob8();break;
            case 9:prob9();break;
            case 10:prob10();break;
            case 11:prob11();break;
            case 12:prob12();break;
            default:{
                cout<<"Exiting, have a great day!"<<endl;
            }
        }
    }while(choice>0&&choice<10);
    //Exit the program
    return 0;
}

void prob1(){
    cout<<"Problem 1: Coin Toss - Ch. 6"<<endl;
    int numTimes, countHead=0, countTail=0, result;
    
    cout<<"How many times do want to flip the coin?"<<endl;
    cin>> numTimes;
    
    for(int i=1;i<=numTimes;i++)
    {
        result=coinToss();
        
        if(result==1)
        {
            countHead++;
        }
        
        else if(result==2)
        {
            countTail++;
        }
    }
    cout<<endl<<"Total number of heads: "<<countHead<<endl;
    cout<<"total number of tails: "<<countTail<<endl;
    
    system("pause");
}
int coinToss()
{
    int randNum;
    
    randNum = 1 +rand() % 2;
    
    if(randNum==1)
        cout<<"head"<<endl;
    else
        cout<<"tails"<<endl;
    
    return randNum;
    
}

void prob2(){
    cout<<"Problem 2: Driver's License Exam - Ch. 7"<<endl;
    char inAnswers[20];
inputAnswers(inAnswers);
int correctAns=checkAnswers(inAnswers);
cout<<"Correct Answers are "<<correctAns<<endl;
displayResult(correctAns);
cout << endl;

}
void inputAnswers(char *inAnswers)
{
for(int i=0; i<20; i++)
{
do
{
char ans;
cout<<"Enter Answer for Question "<<(i+1)<<" :";
cin>>ans;
if(ans=='A'||ans=='a'||ans=='B'||ans=='B'||ans=='b'||ans=='C'||ans=='c'||ans=='D'||ans=='d')
{
*inAnswers=ans;
break;
}
else
{
cout<<"Error! Invalid Answer Enter only A, B, C and D"<<endl;
}

}
while(1);
inAnswers++;

}
}
int checkAnswers(char inAnswers[])
{

int correctAns=0;
cout<<"Incorrect Answers : "<<endl;
char answers[]= {'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','A','D','B'};
for(int i=0; i<20; i++)
{
if((answers[i]==inAnswers[i])||(answers[i]-inAnswers[i]==-32))
{

correctAns++;
}
else
{
cout<<"Incorrect answer For QUESTION :"<<(i+1)<<endl;
}
}
return correctAns;
}
void displayResult(int correctAns)
{

if(correctAns>=15)
{
cout<<"Congratualations Passed"<<endl;

}
else
{
cout<<"User Failed"<<endl;
}
cout<<"Correct Answers:"<<correctAns<<endl;
cout<<"Incorrect Answers:"<<(20-correctAns)<<endl;

}



void prob3(){
    cout<<"Problem 3: Grade Book - Ch. 7"<<endl;
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



for(int i=0;i<5;i++)

{

avgScore[i] = 0;

for(int j=0;j<4;j++)

avgScore[i] += scores[i][j];

avgScore[i] /= 4;

grades[i] = letterGrade(avgScore[i]);

}



cout<<"\nStudent Name\tAverage Score\tLetter Grade"<<endl;

for(int i=0;i<5;i++)

{

cout.setf(ios::fixed,ios::floatfield);

cout.precision(2);

cout<<names[i]<<"\t\t"<<setprecision(2)<<avgScore[i]<<"\t\t"<<grades[i]<<endl;

}



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


void prob4(){
    cout<<"Problem 4: Grade Book Modification - Ch. 7"<<endl;
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
         
         
      }
     
      char letterGrade2(double score)
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


void prob5(){
    cout<<"Problem 5: Larger Than N - Ch. 7"<<endl;
    

     

     int a[50];

     int size;

     int num;

     

     cout<<"Enter the size of the array: ";

     cin>>size;

     cout<<"Enter the elements into the array: ";

   
     cout<<"Enter the elements into the array: "<<endl;

     for(int i=0;i<size;i++)

     {

          cout<<"a["<<(i+1)<<"]: ";

          cin>>a[i];

          cout<<endl;

     }

     

     cout<<"The elements entered are: "<<endl;

     for(int i=0;i<size;i++)

     {

          cout<<"["<<a[i]<<"] ";     

     }

     cout<<endl;

     

     cout<<"To print the array elements larger than the "

          <<"given number you need to enter a number."<<endl;

     cout<<"Enter a number: ";

     cin>>num;


    

     printLargerElements(a, size, num);



}



void printLargerElements(int *a, int size, int num)

{

     cout<<"Elements that are larger than the number "<<num<<" are: "<<endl;

     for(int i=0;i<size; i++)

     {

          if(a[i]>num)

              cout<<"["<<a[i]<<"] ";

     }

     cout<<endl;

}


void prob6(){
    cout<<"Problem 6: Lo Shu Magic Square - Ch. 7"<<endl;
    int a[3][3];
cout<<"enter array elements"<<endl;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cout<<"Enter element of ("<<i<<","<<j<<"):";
cin>>a[i][j];
}
}
  
cout<<"Entered 2-D Matix is\n";
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}
  
checkSquare(a);

}

void checkSquare(int a[][3])
{
bool invalid=false;
for(int i=0;i<2;i++)
{
for(int j=0;j<2;j++)
{
if(a[i][j]<1||a[i][j]>9)
invalid = true;
}
}
  
if(invalid) {
cout<<"The given 2-D array is not Lo Shu Magic Square\n";
} else {

    
int diagonalSum=a[0][0]+a[1][1]+a[2][2];
     
  
   bool isValid=true;

     
   for(int i=0;i<3;i++)
   {
       int rowSum =0;
       for(int j=0;j<3;j++)
       {
       rowSum = rowSum+a[i][j];
       }
       if(rowSum!=diagonalSum)
       {
           isValid = false;  
           break;
       }
   }
  
 
   for(int i=0;i<3;i++)
   {
       int columnSum =0;
       for(int j=0;j<3;j++)
       {
       columnSum = columnSum+a[j][i];
       }
       if(columnSum!=diagonalSum)
       {
           isValid=false;
           break;
       }
   }
  
    if(isValid)
   {
           cout<<"The given 2-D array is Lo Shu Magic Square\n";
   } else {
           cout<<"The given 2-D array is not Lo Shu Magic Square\n";
   }
  
}
}

void prob7(){
    cout<<"Problem 7: Lottery Application - Ch. 7"<<endl;
    int n = 5;
int lottery[5];
int user[5];
generateLotteryNumber(lottery, n);
getUserNumbers(user, n);
  
cout << "lottery array:" <<endl;
display(lottery, n);
cout << "user array:" <<endl;
display(user, n);
  
int matches = matchCount(lottery, user, n);
  
cout << "There are " << matches << " matches in lottery and users number"<< endl;
if(matches == n)
{
cout << "grand prize winner"<<endl;
}

}
void generateLotteryNumber(int lottery[], int n)
{
for(int i = 0; i < n; i++)
{
lottery[i] = rand()%10;
}
}

void getUserNumbers(int user[], int n)
{
for(int i = 0; i < n; i++)
{
cout << "Enter number " << (i+1) << " : ";
cin >> user[i];
}
}

int matchCount(int lottery[], int user[], int n)
{
int matches = 0;
for(int i = 0; i < n; i++)
{
for(int j = 0; j < n; j++)
{
if(user[i] == lottery[j])
{
matches++;
break;
}
}
}
return matches;
}

void display(int arr[], int n)
{
for(int i = 0; i < n; i++)
{
cout << arr[i] << " ";
}
cout << endl;
}
 

void prob8(){
    cout<<"Problem 8: Monkey Business - Ch. 7"<<endl;
    float food[NUM_MONKEYS][NUM_DAYS]; 
    float min;                        
    float max;                         
    float average;                     
    
    fillArray (food, NUM_MONKEYS);
    max = calcMax (food, NUM_MONKEYS);
    min = calcMin (food, NUM_MONKEYS);
    average = calcAvg (food, NUM_MONKEYS);
    
    showArray (food, NUM_MONKEYS, average, max, min);
   
}



void fillArray (float array[][NUM_DAYS], int NUM_MONKEYS)
{
   
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
       do {
            cout << " Enter food eaten (in pounds) by each monkey per day\n";
            cout << " Monkey " << (monkeys + 1)
            << ", Day " << (days + 1) << ": ";
            cin >> array[monkeys][days];
            if (array[monkeys][days] <0) 
	            cout << "Food cannot be negative" << endl;
            } while (array[monkeys][days] <0);
        cout << endl;
        }    
}

float calcAvg (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    float total = 0.0;   
    float average = 0;
    
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
            total += array[monkeys][days];
            average = total / 21;
            }
    return average;

    
    
}


float calcMax (float array[][NUM_DAYS], int NUM_MONKEYS)
{
   
    float max = array[0][0]; 
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        {   if (array[monkeys][days] > max)
            max = array[monkeys][days];
        }
    }
    return max;
    
}


float calcMin (float array[][NUM_DAYS], int NUM_MONKEYS)
{
   
    float min = array[0][0];
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        { if (array[monkeys][days] < min)
            min = array[monkeys][days];
        }
    }
    return min;
}


void showArray (float array[][NUM_DAYS], int NUM_MONKEYS, float average, float max, float min)//[NUM_DAYS])
{
    cout <<"Pounds of Food Eaten by Monkey and Day of Week";
    cout <<endl;
    cout <<"Monkey"<<setw(7) << "Sun" << setw(8)<< "Mon" <<setw(8)<< "Tue" <<setw(8)<< "Wed" <<setw(8)<< "Thu"<< setw(8)<< "Fri" <<setw(8)<< "Sat";
    cout <<endl;
    cout << fixed << showpoint << setprecision(1);
    
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        cout<< "\n"<<left<<setw(10)<<(monkeys+1);
        for (int days = 0; days < NUM_DAYS; days++)
            cout<< left<< setw (7) << array[monkeys][days]<< " ";
    }
    cout << endl;
    cout << endl;
    cout << "The average amount of food eaten (in pounds) by all monkeys is: " << setw(4) << fixed << setprecision(1) << average << " pounds." << endl;
    cout << "The greatest amount of food eaten (in pounds) by one monkey this week is: " << setw(4) << fixed << setprecision(1) << max << " pounds." << endl;
    cout << "The least amount of food eaten (in pounds) by one monkey this week is: " << setw(4) << fixed << setprecision(1) << min << " pounds." << endl;
    
    cout << endl;
}


void prob9(){
    cout<<"Problem 9: Payroll - Ch. 7"<<endl;
    const int numOfEmployees = 7;
int long empId[numOfEmployees]= {5658845,4520125,7895122,8777541,8451277,1302850,7580489};
int hours[numOfEmployees];
double payRate[numOfEmployees];
double wages[numOfEmployees];


cout<< "Enter the hours worked by 7 employees and their hourly pay rates.\n";
for (int count = 0;count < numOfEmployees;count++)
{
cout<< "Hours worked by employee #"<<empId[count]<< ":";
cin>> hours[count];
while (hours < 0)
{
cout<<"Please enter a positive number: ";
cin>> hours[count];
}
cout<< "Hourly pay rate for employee #"<<empId[count]<<":";
cin>> payRate[count];
while (payRate[count] < 6.00)
{
cout<< "Please enter a pay rate higher than $6.00: ";
cin>> payRate[count];
}
}

for (int count = 0;count < numOfEmployees;count++)
{
wages[count]= hours[count] * payRate[count];
cout<<"Here is the gross pay for each employee:\n";
cout<<fixed<<showpoint<<setprecision(2);
cout<< "Employee #"<<empId[count]<<": $"<<wages[count]<< endl;
}

} 


void prob10(){
    cout<<"Problem 10: Present Value - Ch. 6"<<endl;
    double result, futureValue, annualRate, years;
    
    cout<<"Enter future value: ";
    cin>>futureValue;
    
    cout<<"Enter annual interest rate: ";
    cin>>annualRate;
    
    cout<<"Enter number of years: ";
    cin>>years;
    
    result = presentValue(futureValue,annualRate,years);
    
    cout<<"Need to deposit: $"<<result;
    
    
}

double presentValue(double F,double r, double n)
{
    double P;
    
    P=F/(pow((1+r),n));
    
    return P;
}


void prob11(){
    cout<<"Problem 11: Safest Driving Area - Ch. 6"<<endl;
     double central,north, south, east, west;
    
    central = getNumAccidents("central");
    north = getNumAccidents("north");
    south = getNumAccidents("south");
    east = getNumAccidents("east");
    west = getNumAccidents("west");
    
    findLowest(central,north, south, east, west);
    
    
}

int getNumAccidents(char * division)
{
    int accidents;
    
    do
    {
        cout<<"Please enter accidents in "<<division<<" division: ";
        cin>>accidents;
        
        if(accidents<0.0)
            cout<<"Please enter a positive number.";
        
    }
    
    while(accidents<0.0);
    
    return accidents;
}

void findLowest(double central, double north, double south, double east, double west)
{
    
    if(central<=north&&central<=east&&central<=west&&central<=south)
    {
        cout<<"Lowest accidents in central division: "<<central<<endl;
    }
    
    if(north<=south&&north<=west&&north<=east&&north<=central)
    {
        cout<<"Lowest accidents in north division: "<<north<<endl;
    }
    
    if(south<=north&&south<=east&&south<=west&&south<=central)
    {
        cout<<"Lowest accidents in south division: "<<south<<endl;
    }
    
    if(east<=north&&east<=west&&east<=south&&east<=central)
    {
        cout<<"Lowest accidents in east division: "<<east<<endl;
    }
    
    if(west<=north&&west<=south&&west<=east&&west<=central)
    {
        cout<<"Lowest accidents in west division: "<<west<<endl;
    }
    
}


void prob12(){
    cout<<"Problem 12: Star Search - Ch. 6"<<endl;
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


void menu(){
    //Input Data/Variables
    cout<<"Choose from the menu below..."<<endl;
    cout<<endl;
    cout<<"1. Problem 1"<<endl;
    cout<<"2. Problem 2"<<endl;
    cout<<"3. Problem 3"<<endl;
    cout<<"4. Problem 4"<<endl;
    cout<<"5. Problem 5"<<endl;
    cout<<"6. Problem 6"<<endl;
    cout<<"7. Problem 7"<<endl;
    cout<<"8. Problem 8"<<endl;
    cout<<"9. Problem 9"<<endl;
    cout<<"10. Problem 10"<<endl;
    cout<<"11. Problem 11"<<endl;
    cout<<"12. Problem 12"<<endl;
    cout<<endl;
    cout<<"...or enter '0' to exit."<<endl;
}
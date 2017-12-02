#include <iostream>

using namespace std;
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
int main()
{

char inAnswers[20];
inputAnswers(inAnswers);
int correctAns=checkAnswers(inAnswers);
cout<<"Correct Answers are "<<correctAns<<endl;
displayResult(correctAns);
cout << endl;
return 0;
}


#include <iostream>
#include <stdlib.h>

using namespace std;

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


int main()
{
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
return 0;
}

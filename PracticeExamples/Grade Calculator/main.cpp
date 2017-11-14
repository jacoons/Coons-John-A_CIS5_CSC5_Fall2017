
#include <iostream>

using namespace std;


int main()
{
    const int A_SCORE=90,
              B_SCORE=80,
              C_SCORE=70,
              D_SCORE=60;
    
    int test_score;
    
    cout<<"Enter your numeric test score and I will\n";
    cout<<"tell you the grade you earned:";
    cin>>test_score;
    
    if (test_score >= A_SCORE)
    {
        cout<<"Your grade is an A.\n";
    }
    else
    {
        if (test_score >= B_SCORE)
        {
            cout<<"Your grade is a B.\n";
        }
        else
        {
            if (test_score >= C_SCORE)
            {        
                cout<<"Your grade is a C.\n";
            }
            else
            {
                if (test_score >= D_SCORE)
                {
                cout<<"Your grade is a D.\n";
                }
                else
                {
                cout<<"Your grade is an F.\n";
                }
            }    
        }
    }
           
    

    return 0;
}


#include <iostream>

using namespace std;
int main()
{
    float land_size, size_in_acres;
    
    land_size = 391867;
    
    size_in_acres = land_size /43560;
    
    cout<<"The number of acres in "<<land_size<<" square feet is "<<size_in_acres<<"."<<endl;
    
    return 0;
}


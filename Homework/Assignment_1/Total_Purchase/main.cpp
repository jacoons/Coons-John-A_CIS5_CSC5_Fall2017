#include <iostream>

using namespace std;

int main()
{
    float price_1, price_2, price_3, price_4, price_5;
    float sub_total, sales_tax, total_price;
    
    price_1=15.95;
    price_2=24.95;
    price_3=6.95;
    price_4=12.95;
    price_5=3.95;
            
    sub_total=price_1+price_2+price_3+price_4+price_5;
    
    sales_tax=sub_total*0.07;
    
    total_price=sales_tax+sub_total;
    
    cout<<"The price of item 1 is "<<"$"<<price_1<<"."<<endl;
    cout<<"The price of item 2 is "<<"$"<<price_2<<"."<<endl;
    cout<<"The price of item 3 is "<<"$"<<price_3<<"."<<endl;
    cout<<"The price of item 4 is "<<"$"<<price_4<<"."<<endl;
    cout<<"The price of item 5 is "<<"$"<<price_5<<"."<<endl;
    
    cout<<"Subtotal = $"<<sub_total<<"."<<endl;
    cout<<"Sales Tax = $"<<sales_tax<<"."<<endl;
    cout<<"Total = $"<<total_price<<"."<<endl;
      
    
    return 0;
}


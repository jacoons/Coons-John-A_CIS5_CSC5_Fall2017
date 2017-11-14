
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    float pallet, with_widget, widget_weight; 
    short widget_qty;
    
    cout<<"How much does the pallet weigh?";
    cin>>pallet;
    
    cout<<"How much does the pallet weight with the widgets on it?";
    cin>>with_widget;
    
    widget_weight=with_widget-pallet;
    widget_qty=widget_weight/12.5;
    
    cout<<"There are "<<widget_qty<<" widgets sitting on the pallet.";
    
      
   

    return 0;
}


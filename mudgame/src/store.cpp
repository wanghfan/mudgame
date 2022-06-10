#include "store.h"
store::store(int l, string s, map<string, int> item_price):place(s,l),item_price(item_price){}
void store:: show(){
    Sleep(delay_time*0.8);
    cout<<"你到达了商店，你可以在这购买物品"<<endl;
    Sleep(delay_time*0.8);
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                   童叟无欺                   *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                     商店                     *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
    Sleep(delay_time*0.8);
    
}
void store::show_item(){
    Sleep(delay_time * 0.8);
    cout<<"商店的商品及价格如下："<<endl;
    Sleep(delay_time * 0.8);
    int i=0;
    for(auto it:item_price)
    {
        
        cout<<i<<it.first<<" "<<it.second<<endl;
        i++;
    }
}
void store::buy(int item,people &p)
{
    map<string,int>::iterator it;
    string temp;
    int i=0;
    for(auto it:item_price)
    {
        if(i==item){
            cout<<i<<it.first<<" "<<it.second<<endl;
            temp=it.first;
            break;
        }
        i++;
    }
    if(i==item_price.size())
    {
        cout<<"商店中无此商品！"<<endl;

        Sleep(delay_time * 0.8);
    }else{
        
        cout<<"购买成功！"<<endl;
        Sleep(delay_time * 0.8);
        cout<<"您获得了"<<" "<<temp<<endl;
        Sleep(delay_time * 0.8);
        p.money_change(-1*item_price[temp]);
        item_price.erase(temp);
        p.get_something(temp);

    }
}
void store::event(people &p)
{
//     cout<<"您可以选择 0.购买 1.抢劫"<<endl;
//     int choice;
//     cin>>choice;
    // if(choice==0)
    // {
        // show_item();
       
        int flag=0;
        while (flag==0)
        {
            /* code */
            show_item();
            Sleep(delay_time*0.8);
            Sleep(delay_time*0.8);
            cout << "请输入要够买的物品序号"<<endl;
            int temp;
            cin >> temp;
            buy(temp,p);
            cout<<"0.继续购买 1.结束购买"<<endl; 
            int c;
            cin>>c;
            flag=c;
        }        
    // }
    // if(choice==1)
    // {

    // } 
}
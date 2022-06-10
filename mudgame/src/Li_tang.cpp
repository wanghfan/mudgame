#include "Li_tang.h"
using namespace std;
litang::litang(int l, string s):place(s,l){}
void litang::show()
{
    Sleep(delay_time);
    cout << "达到世界最高城，里唐！" << endl;
    Sleep(delay_time);
    cout << "太美丽了里唐" << endl;
    Sleep(delay_time);
    cout << "************************************************" << endl;
    cout << "*                 *                            *" << endl;
    cout << "*                 *                            *" << endl;
    cout << "*      雪山       *         丁真广告牌          *" << endl;
    cout << "*                 *                            *" << endl;
    cout << "*                 *                            *" << endl;
    cout << "*                 *                            *" << endl;
    cout << "********************************************** *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
    Sleep(delay_time);
}
void litang::event(people &player)
{
    int choice;
    // show();
    cout<<"你有两个选择"<<endl;
    Sleep(delay_time);
    cout << "0.看看远处的雪山 1.看看广告牌 " << endl;
    Sleep(delay_time);
    cin>>choice;
    if(choice==0)
    {
        player.happiness_change(3);
        player.attractiveness_change(2);
        if(!(rand()%30)){
            cout<<"看着此情此景，你不禁感慨良多，对着美丽的雪山大声呼喊"<<endl;
            Sleep(delay_time * 0.8);
            cout<<"~~我家住在黄土高坡~~"<<endl;
            Sleep(delay_time * 0.8);
            cout<<"你感觉雪山好像也在回应你"<<endl;
            Sleep(delay_time * 0.8);
            cout<<"原来是发生了雪崩"<<endl;
            Sleep(delay_time * 0.8);
            cout<<"你被埋了"<<endl;
            player.set_die();
            return;
        }
    }
    if(choice==1)
    {
        cout<<"哎呀这不丁真吗"<<endl;
        player.happiness_change(-2);
    }
}
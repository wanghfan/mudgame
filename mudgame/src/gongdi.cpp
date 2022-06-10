#include "place.h"
#include "gongdi.h"
//只有晚上能来酒吧
#include <iostream>
using namespace std;
gongdi::gongdi(int l, string s, int wan ) : place(s, l), wanchengdu(wan) {}
void gongdi:: show()
{
    cout << "欢迎来到工地" << endl;
    cout << "********************************" << endl;
    cout << "*   半成品大楼      *           *" << endl;
    cout << "*                  *     挖掘机 *" << endl;
    cout << "********************           *" << endl;
    cout << "*                              *" << endl;
    cout << "*            工人              *" << endl;
    cout << "*  砖块堆           土木工程师  *" << endl;
    cout << "*                              *" << endl;
    cout << "************大铁门**************" << endl;
    cout << "建筑完成度" << wanchengdu << "%" << endl;
    cout << "这里到处都是灰，以及一群在干活的工人们。" << endl;
}
void gongdi::banzhuan(people &player)
{
    cout << "你来到了砖块堆旁，撸起袖子开始扛" << endl;
    cout << "烈日当空，你很辛苦。" << endl;
    player.happiness_change(-2);
    player.physique_change(3);
    cout << "到处都是灰尘,你的脸越来越粗糙" << endl;
    player.attractiveness_change(-2);
    if(rand()%2){
        cout<<"你看到一个搬砖人晕倒在了地上，他需要治疗，你愿意提供帮助吗？0,不管他；1，帮助他"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            cout<<"你花了10元的医药费"<<endl;
            player.money_change(-10);
            cout<<"他醒来了解情况后，感激地看着你"<<endl;
            cout<<"虽然今天几乎白干了，但是你(maybe)也没有后悔"<<endl;
            player.EQ_change(3);
            player.happiness_change(2);
            if(rand()%2){
                string a;
                generate_name(a);
                player.get_friend(a);
            }
        }
    }
    if (!(rand() % 10))
    {
        beiza(player);
    }
    wanchengdu++;
    cout << "工作结束了，你领到了自己的工钱" << endl;
    player.money_change((int)(std::sqrt(player.get_physique()) * 1.5));
}
void gongdi::drive(people &player)
{
    cout << "凭着你学到的知识，你进入了挖掘机并开始工作。" << endl;
    cout << "看着昔日一起工作的工友还在辛苦的搬砖，你不禁感慨起知识的力量。" << endl;
    wanchengdu += 2;
    cout << "工作结束了，你领到了自己的工钱" << endl;
    player.money_change(15);
}
void gongdi::beiza(people &player)
{
    cout << "你正扛着砖，突然脚下一团阴影越来越来大。" << endl;
    cout << "在众人的惊呼声中，你被砸中了" << endl;
    vector<string> v = player.get_bag();
    string s("安全帽");
    if (find(v.begin(), v.end(), s) == v.end())
    {
        player.physique_change(-20);
    }
    else
    {
        cout << "所幸有安全帽,你伤的并不重" << endl;
        player.physique_change(-10);
    }
}
void gongdi::zhihui(people &player)
{
    cout << "凭借你学到的土木知识，你开始指挥工人们进行工作" << endl;
    cout << "看着昔日一起工作的工友还在辛苦的搬砖，你不禁感慨起知识的力量。" << endl;
    cout << "看着建筑在你的指挥下一步步建成，你感到了由衷的自豪" << endl;
    player.happiness_change(1);
    if (!(rand() % 20))
    {
        beiza(player);
    }
    cout << "工作结束了，你领到了自己的工钱" << endl;
    wanchengdu += 3;
    player.money_change(20);
}
void gongdi::finish(people &player)
{
    cout << "恭喜！建筑完成了！" << endl;
    cout << "老板非常高兴，给了所有干活的人一波福利" << endl;
    player.money_change(80);
    player.happiness_change(10);
    cout << "新的任务也来了" << endl;
    wanchengdu = 0;
}
void gongdi::event(people &player)
{
    // show();
    while (1)
    {
        cout << "你有如下选择：0，搬砖；1，开挖掘机；2，土木指挥.请输入你的选择." << endl;
        int action;
        cin >> action;
        if (action == 0)
        {
            banzhuan(player);
            break;
        }
        else if (action == 1)
        {
            if (player.get_IQ() >= 80)
            {
                drive(player);
                break;
            }
            else
            {
                cout << "你现在还不会开挖掘机,多去学校学学吧" << endl;
                cout << "请重新选择" << endl;
            }
        }
        else if (action == 2)
        {
            if (player.get_IQ() >= 110)
            {
                zhihui(player);
                break;
            }
            else
            {
                cout << "你现在还不会土木工程,多去学校学学吧" << endl;
                cout << "请重新选择" << endl;
            }
        }
        else
        {
            cout << "请输入正确的选项" << endl;
        }
    }
    if (wanchengdu >= 100)
    {
        finish(player);
    }

}

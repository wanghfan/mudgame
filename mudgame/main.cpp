//*******************************************************************************************************************
//模拟人生
//该游戏是一个人生模拟mud游戏
//
// people类：
// 1.属性：幸福度、智商、情商、体力、金钱、伴侣
// 2.物品栏
// 3.相应修改自身属性的函数
//
// place类：该类为base类，其下继承了各种子类，比如教室、体育馆、实验室、工地、酒吧、网吧、办公楼等
//该类用于表征所有地点类都会具有的信息
//每个地点类：
// 1.属性：这个视地点而定，每个地点有自己特定的属性；不如说教室类就有学习氛围属性
// 2.函数：主要分为两类；
//      第一类为生成事件函数，目标是根据输入的人的属性以及一定的随机值生成相应的事件
//      第二类为事件函数，输出发生的事件，并且对人的属性进行修改，并且自身的属性值也有可能被修改
//*******************************************************************************************************************//

// 1.一开始可以选择人的特性，不要每个人都一样
// 2.可以进行地图化，每次只能移动到相近的地点.地点可以设定为需要探索.
// 3.NPC的设置
// 4.多玩家
// 5.事件可以再有选择
// 6.勋章
// #include <windows.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include "src/place.h"
#include "src/people.h"
#include "src/globals.h"
#include "src/utils.h"
#include "src/lake.h"
#include "src/gongdi.h"
#include "src/Li_tang.h"
#include "src/store.h"
#include "src/bar.h"
#include "src/hospital.h"
#include "src/map.h"
#include "src/classroom.h"
#include "src/company.h"
#include "src/gym.h"
using namespace std;
#define max_increment 8////
#define delay_time 800////
#define total_points 200////
#define place_num 10
place *Place[place_num] ;
 people player;
int main()
{
    system("cls");
    system("chcp 65001");
    start_view();
    //初始化
    srand(time(0));
    int live = 30;
    cout << "请依次输入你的名称和性别(m/f)，开始你的人生" << endl;
    cout << "输入示例如下：Allen(输入回车键)m(输入回车键)" << endl; //暂不支持中文输入
    string name;
    string sex;
    cin >> name >> sex;
    //分配点数
    player = people(name, sex);
    distribute_point(player);
    while(1){
        cout<<"请选择你的寿命(10到100之间)"<<endl;
        cin>>live;
        if(live<=50&&live>=10){
            break;
        }
        else{
            cout<<"请输入正确的寿命"<<endl;
        }
    }
    player.loc_r=4;
    player.loc_c =4;
    
    //设置商店物品
    map <string,int> item_price;
    item_price["钓鱼竿"]=20; 
    item_price["安全帽"]=40;
    item_price["香水"]=50;

    Place[0] = new classroom(0, "classroom0", 50);
    Place[1] = new company(1, "company0", 30);
    Place[2] = new gym(2,"gym0");
    Place[3] = new lake(3,"westlake");
    Place[4] = new litang(4,"litang");
    Place[5] = new store(5,"store0",item_price);
    Place[6] = new bar(6,"bar0");
    Place[7] = new hospital(7,"hospital0");
    Place[8] = new gongdi(8,"gongdi");
    int map[4][4];
    //初始化地图
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
            map[i][j]=-1;
    }
    map[3][3]=0;
    map[3][4]=2;
    map[4][3]=1;
    map[2][4]=3;
    map[2][2]=4;
    map[3][1]=5;
    map[3][2]=6;
    map[4][2]=7;
    map[2][3]=8;
    //开始玩
    int day = 0;
     for (; day < live && player.player_die() != 1; day++)
    {
        cout << endl << endl << "这是第" << day << "天" << endl;
        cout << "你想回顾一下自己的现状吗？是请输入非0数，否则输入0" << endl;
        
        int seeself = 0;
        cin >> seeself;
        if (seeself)
        {
            player.show();
        }
        for (int day_time = 0; day_time < 3; day_time++)
        { //上午为0，下午为1，晚上为2
            cout << endl;
            if (day_time == 0)
            {
                cout << "这是上午" << endl;
            }
            else if (day_time == 1)
            {
                cout << "这是下午" << endl;
            }
            else
            {
                cout << "这是晚上" << endl;
            }
            //使用循环的是为了解决输入不存在的地点的问题
            if (day == 0 && day_time==0)
            {
                Sleep(delay_time);
                cout<<"您现在初始位置,游戏结束前不会回到这里"<<endl;
                Sleep(delay_time);
                cout << "你现在在地图上的方位为：" << endl;
                show_map(player.loc_r, player.loc_c);
                cout << "************分割线**************" << endl;
                Sleep(delay_time * 0.5);
                cout << "注意，您无法停留在初始位置！" << endl;
            }
            while(1){
                Sleep(delay_time);
                cout << "请选择一个方向" << endl;
                Sleep(delay_time);
                cout << "8.上 2.下 4.左 6.右 5.停留（查看地图）" << endl;
                Sleep(delay_time);
                int choice;
                cin >> choice;
                int theta_r=0,theta_c=0;
                if(choice==8){theta_r=-1;theta_c=0;}
                if(choice==2){theta_r=1;theta_c=0;}
                if(choice==4){theta_r=0;theta_c=-1;}
                if(choice==6){theta_r=0;theta_c=1;}
                if(choice==5){theta_r=0;theta_c=0;}
                if(map[player.loc_r+theta_r][player.loc_c+theta_c]==-1)
                {
                    Sleep(delay_time);
                    cout<<"该地点不存在！请重新输入"<<endl;
                    Sleep(delay_time);
                }
                else
                {
                    int activity = map[player.loc_r + theta_r][player.loc_c + theta_c];
                    player.loc_r += theta_r;
                    player.loc_c += theta_c;
                    cout<<"你现在在地图上的方位为："<<endl;
                    show_map(player.loc_r, player.loc_c);
                    cout<<"************分割线**************"<<endl;
                    Sleep(delay_time * 0.5);
                    cout << "您可以选择继续行进或者触发事件，行进不会消耗时间。" << endl;
                    Sleep(delay_time*0.5);
                    cout<<"0.行进 1.触发事件"<<endl;
                    Sleep(delay_time * 0.5);
                    int f=1;
                    while(1){
                        int choice;
                        
                        cin>>choice;
                        
                        if(choice==1){
                            Place[activity]->show();
                            Sleep(delay_time * 0.5);
                            Place[activity]->event(player);
                            f=0;
                            break;
                        }
                        else if(choice==0){
                            break;
                        }
                        else {
                            cout<<"请输入合法输入！"<<endl;
                            continue;
                        }
                    }
                    if(f==1)
                    continue;
                    else
                    break;
                    
                }
            }
            if(day_time==0){
                cout<<"你该吃午饭了，花了五元"<<endl;
            }
            else if(day_time==1){
                cout<<"你该吃晚饭了，花了五元"<<endl;
            }
            else{
                cout<<"你该睡觉了，同时还要付明天的早餐费，花了五元"<<endl;
            }
            player.money_change(-5);
            //死亡设定
            if(player.get_money()<0){
                cout<<"由于缺少生活费,你死了"<<endl;
                player.set_die();
            }
            else if(player.get_physique()<=5){
                cout<<"由于身体过于虚弱，你死了"<<endl;
                player.set_die();
            }
            else if(player.get_happiness()<=10){
                if(rand()%2){
                    cout<<"你感到十分抑郁，你自杀了"<<endl;
                }
                player.set_die();
            }
            if (player.player_die() == 1)
            {
                break;
            }
        }
    }
    show_res(player,day);
    system("pause");
    return 0;
}
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
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "place.h"
#include "people.h"
#include "globals.h"
#include "utils.h"
using namespace std;
#define max_increment 8////
#define delay_time 800////
#define total_points 200////
int main()
{
    system("cls");
    system("chcp 65001");
    start_view();
    //初始化
    srand(time(0));
    const int live = 1;
    cout << "请依次输入你的名称和性别(m/f)，开始你的人生" << endl;
    cout << "输入示例如下：Allen(输入回车键)m(输入回车键)" << endl; //暂不支持中文输入
    string name;
    string sex;
    cin >> name >> sex;
    //分配点数
    people player(name, sex);
    distribute_point(player);
    player.loc_r=2;
    player.loc_c =2;

    classroom classroom0(0, "classroom0", 50);
    company company0(1,"company0",30);
    gym gym0(2,"gym0");
    int map[4][4];
    //初始化地图
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            map[i][j]=-1;
    }
    map[1][1]=0;
    map[1][2]=1;
    map[2][1]=2;
    
    //开始玩
    int day = 0;
     for (; day < live && player.player_die() != 1; day++)
    {
        cout << "这是第" << day << "天" << endl;
        cout << "你想回顾一下自己的现状吗？是请输入非0数，否则输入0" << endl;
        int seeself = 0;
        cin >> seeself;
        if (seeself)
        {
            player.show();
        }
        for (int day_time = 0; day_time < 3; day_time++)
        { //上午为0，下午为1，晚上为2
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
                    cout << "注意，您无法停留在初始位置！" << endl;
                }
                    Sleep(delay_time);
                    cout<<"请选择一个方向"<<endl;
                    Sleep(delay_time);
                    cout << "0.上 1.下 2.左 3.右 4.停留" << endl;
                    Sleep(delay_time);
                    int choice;
                    
                    
                    while(1){
                        cin >> choice;
                        if(choice==0)
                        {
                            if(map[player.loc_r-1][player.loc_c]==-1)
                            {
                                Sleep(delay_time);
                                cout<<"该地点不存在！请重新输入"<<endl;
                                Sleep(delay_time);
                            }
                            else
                            {
                                int activity = map[player.loc_r - 1][player.loc_c];
                                if(activity==0)
                                    classroom0.event(player);
                                if(activity==1)
                                    gym0.event(player);
                                if(activity==2)
                                    company0.event(player);
                                player.loc_r--;
                                break;
                            }
                            
                            
                        }
                        if(choice  == 1)
                        {
                            if (map[player.loc_r + 1][player.loc_c] == -1)
                            {
                                Sleep(delay_time);
                                cout << "该地点不存在！请重新输入" << endl;
                                Sleep(delay_time);
                            }

                            else
                            {
                                int activity = map[player.loc_r + 1][player.loc_c];
                                if (activity == 0)
                                    classroom0.event(player);
                                if (activity == 1)
                                    gym0.event(player);
                                if (activity == 2)
                                    company0.event(player);
                                player.loc_r++;
                                break;
                            }
                        }
                        if (choice == 2)
                        {
                            if (map[player.loc_r ][player.loc_c-1] == -1)
                            {
                                Sleep(delay_time);
                                cout << "该地点不存在！请重新输入" << endl;
                                Sleep(delay_time);
                            }
                            else
                            {
                                int activity = map[player.loc_r ][player.loc_c-1];
                                if (activity == 0)
                                    classroom0.event(player);
                                if (activity == 1)
                                    gym0.event(player);
                                if (activity == 2)
                                    company0.event(player);
                                player.loc_c--;
                                break;
                            }
                        }
                        if (choice == 3)
                        {
                            if (map[player.loc_r ][player.loc_c+1] == -1)
                            {
                                Sleep(delay_time);
                                cout << "该地点不存在！请重新输入" << endl;
                                Sleep(delay_time);
                            }
                            else
                            {
                                int activity = map[player.loc_r ][player.loc_c+1];
                                if (activity == 0)
                                    classroom0.event(player);
                                if (activity == 1)
                                    gym0.event(player);
                                if (activity == 2)
                                    company0.event(player);
                                player.loc_c++;
                                break;
                            }
                        }
                        if (choice == 4)
                        {
                            if (map[player.loc_r][player.loc_c] == -1)
                            {
                                Sleep(delay_time);
                                cout << "该地点不存在！请重新输入" << endl;
                                Sleep(delay_time);
                            }
                            else
                            {
                                int activity = map[player.loc_r][player.loc_c];
                                if (activity == 0)
                                    classroom0.event(player);
                                if (activity == 1)
                                    gym0.event(player);
                                if (activity == 2)
                                    company0.event(player);
                                
                                break;
                            }
                        }
                    }

            
        }
    }
    show_res(player,day);
    return 0;
}
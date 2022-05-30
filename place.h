#include<string>
#include<iostream>
#include<windows.h>
#include"people.h"
#include"utils.h"
#define delay_time 800
using namespace std;
class place
{ //所有地点类的基类，属性表示每个地点类都会有的属性
private:
    int location; //从0开始，地点坐标
    string name;

public:
    place(string s = "", int l = 0);
    void show();
    virtual ~place();
    //使用默认拷贝构造以及赋值函数即可
};

class gym:public place
{
private:
    int cap0=20;
    int cap1=20;
    int cap2=20;
    int cap3=20;
public:
    gym(int l,string s);
    void show_gym();
    void basketball(people &player);
    void badminton(people &player);
    void event(people &player);
};

class classroom : public place
{
private:
    int studying_atmosphere; // from 0~100
public:
    classroom(int l, string s, int atmos = 50);
    void show();
    int select(const people &p);
    void learn_well(people &p);
    void fall_asleep(people &p);
    void can_t_understand(people &p);
    void find_a_friend(people &p);
    void find_a_gril_friend(people &p);
    void event(people &player);
};

class company: public place{
private:
    int pressure;
    int ini=0;
    int is_im_w=0;
public:
    company(int l, string s, int pressure);
    void show();
    void event(people &player);
};
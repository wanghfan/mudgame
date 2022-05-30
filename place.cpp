#include"place.h"
using namespace std;
//place base class
place::place(string s/*=""*/ , int l/*=0*/ ) : name(s), location(l) {}
void place::show()
{
    cout << "位置:" << location << endl;
    cout << "地点:" << name << endl;
}
place::~place(){}

//gym class
gym::gym(int l,string s):place(s,l){}
void gym::show_gym()
{
    Sleep(delay_time);
    cout<<"欢迎来到浙江大学体育馆"<<endl;
    Sleep(delay_time);
    cout << "*************************************************"<<endl;
    cout << "*       羽毛球     *                 *          *" << endl;
    cout << "*                  *                 *          *" << endl;
    cout << "********************     网球        *   乒乓球  " << endl;
    cout << "*                  *                 *          *" << endl;
    cout << "*       篮球       *                 *          *" << endl;
    cout << "*                  *                 *          *" << endl;
    cout << "*                  *                 *          *" << endl;
    cout << "*                  *                 *          *" << endl;
    cout << "*************************************************" << endl;
    Sleep(delay_time);
}
void gym::basketball(people &player)
{

    int r = rand() % 30;
    if(r<=5)
    {
        Sleep(delay_time);
        cout<<"你刚走进篮球场，一颗硕大的篮球砸中你的脑门"<<endl;
        Sleep(delay_time);
        cout << " ****  "<<endl;
        cout << "*    *             " << endl;
        cout << "*    *     -->>   头" << endl;
        cout << " ****" << endl;
        cout<<"获得医药费 20"<<endl;
        Sleep(delay_time);
        player.happiness_change(-2);
        player.physique_change(0);
        player.money_change(20);
        return;
    }
    int now_num = rand() % (cap0 * 2);
    //   cout<<"余量："<<now_num<<endl;
    if (now_num <= cap0 - 1)
    {
        Sleep(delay_time);
        cout << "篮球场还有余量" << endl;
        if (player.get_physique() <= 10)
        {
            cout << "你太瘦弱了！没人愿意和你组队" << endl;
            Sleep(delay_time);
            player.happiness_change(-2);
            player.physique_change(0);
            return;
        }
        else
        {
            Sleep(delay_time);
            cout << "你打得非常开心，你和球友们成为了好朋友" << endl;
            player.physique_change(2);
            player.happiness_change(3);
            player.attractiveness_change(1);
            return;
        }
    }
    else
    {
        Sleep(delay_time);
        cout << "篮球场没有余量了！" << endl;
        Sleep(delay_time);
        cout << "你有如下选择" << endl;
        Sleep(delay_time);
        cout << "0.离开" << endl;
        Sleep(delay_time * 2);
        cout << "1.抢夺一个场地" << endl;
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            Sleep(delay_time);
            player.physique_change(0);
            player.happiness_change(-1);
            player.attractiveness_change(0);
            return;
        }
        if (choice == 1)
        {
            Sleep(delay_time);
            if(player.get_physique()>=45)
            {
                cout<<"你以一敌十，击退了众人"<<endl;
                player.physique_change(5);
                Sleep(delay_time);
                cout<<"但最后没有人和你一起打球，你只能孤单地离开了"<<endl;
                player.happiness_change(-2);
                return;
            }else{
                cout<<"你冲向篮球场，恰巧一个壮汉正在救球"<<endl;
                Sleep(delay_time);
                cout<<"你们撞再了一起，你飞出了5m远"<<endl;
                player.physique_change(-2);
                player.happiness_change(-1);
                Sleep(delay_time);
                cout<<"你需要支付医药费20"<<endl;
                if(player.get_money()<20)
                {
                    Sleep(delay_time);
                    cout<<"你死了"<<endl;
                    player.set_die();
                }else{
                    Sleep(delay_time);
                    return;
                }
            }
            
        }
    }
}
void gym::badminton(people &player)
{
    int now_num = rand() % (cap0 * 2);
    //   cout<<"余量："<<now_num<<endl;
    if (now_num <= cap0 - 1)
    {
        cout << "羽毛球场还有余量" << endl;
        if (player.get_attractiveness() <= 10)
        {
            Sleep(delay_time);
            cout << "你的颜值过低，没人愿意和你打球！" << endl;
            Sleep(delay_time);
            player.happiness_change(-2);
            player.physique_change(0);
            return;
        }
        else
        {
            Sleep(delay_time);
            cout << "你和另一位同学打得非常开心，你们成为了好朋友" << endl;
            player.physique_change(2);
            player.happiness_change(3);
            player.attractiveness_change(1);
            return;
        }
    }
    else
    {
        cout << "羽毛球场没有容量！" << endl;
        Sleep(delay_time);
        cout << "你有如下选择" << endl;
        Sleep(delay_time);
        cout << "0.离开" << endl;
        Sleep(delay_time*2);
        cout<<"1.抢夺一个场地"<<endl;
        int choice;
        cin>>choice;
        if(choice==0)
        {
            Sleep(delay_time);
            player.physique_change(0);
            player.happiness_change(-1);
            player.attractiveness_change(0);
            return;
        }
        if(choice==1)
        {
            Sleep(delay_time);
            cout<<"勇敢者的选择！"<<endl;
            Sleep(delay_time);
            cout<<"你目光转向了那个身材瘦弱的同学"<<endl;
            Sleep(delay_time);
            cout<<"要选择他吗？（输入y or n）"<<endl;
            string yes;
            cin>>yes;
            if(yes=="y")
            {
                cout<<"“给我滚开！”你大喝道。"<<endl;
                Sleep(delay_time);
                if(player.get_physique()<=10)
                {
                    cout<<"对方使出了“佛山无影脚”，你被击倒在地"<<endl;
                    Sleep(delay_time);
                    cout<<"你灰溜溜地跑了"<<endl;
                    player.physique_change(0);
                    player.happiness_change(-2);
                    player.attractiveness_change(-2);
                    return;
                }
                else{
                    Sleep(delay_time);
                    cout<<"对方望向高大威猛的你，丢下球拍跑了"<<endl;
                    Sleep(delay_time);
                    cout<<"获得物品，球拍*1"<<endl;
                    player.get_something("球拍");
                    Sleep(delay_time);
                    cout << "你和另一位同学打得非常开心，你们成为了好朋友" << endl;
                    player.physique_change(2);
                    player.happiness_change(3);
                    player.attractiveness_change(1);
                    return;
                }
            }
        }
    }
}
void gym::event(people &player)
{
    show_gym();
    cout<<"请输入序号以选择一个场地"<<endl;
    cout<<"0.羽毛球 1.篮球"<<endl;
    int choice;
    cin>>choice;
    if(choice==0)
    {
        badminton(player);
    }
    if(choice==1)
    {
        basketball(player);
    }

}

//classroom class
classroom::classroom(int l, string s, int atmos /*= 50*/) : place(s, l), studying_atmosphere(atmos) {}
void classroom::show()
{
    Sleep(delay_time);
    cout<<"欢迎来到浙江大学教室0！"<<endl;
    Sleep(delay_time);
    cout << "*******************************" << endl;
    cout << "*                             *" << endl;
    cout << "*            学生             *" << endl;
    cout << "*                             *" << endl;
    cout << "*                             *" << endl;
    cout << "*        ************         *" << endl;
    cout << "*        *   讲台   *         *" << endl;
    cout << "*        *          *         *" << endl;
    cout << "*****门门门*********************" << endl;
}
int classroom::select(const people &p)
{ //返回选中的事件,计数从0开始
    if (p.get_sex() == "m" && p.get_IQ() > 150 && p.get_EQ() > 100 && p.get_friends().size() > 3)
    { //事件4，找到npy,cgh版
        if (rand() % 5)
        {
            return 4;
        }
    }
    int chance0 = generate_increment(p.get_IQ() + studying_atmosphere, 400);
    int chance1 = (max_increment - generate_increment(p.get_IQ() + studying_atmosphere, 400));
    int chance3 = generate_increment(p.get_EQ() + studying_atmosphere, 400);
    if (!(rand() % chance0))
    { //越聪明，教室学习氛围越好，越容易听懂;
        return 0;
    }
    if (!(rand() % chance1))
    { //越聪明，教室学习氛围越好，越不容易睡着;
        return 1;
    }
    if (!(rand() % chance3))
    { // EQ越高，教室学习氛围越好,越容易沟通;
        return 3;
    }
    return 2;
}
void classroom::learn_well(people &p)
{
    Sleep(delay_time);
    cout << "你专心听讲，觉得老师讲的条理十分清晰，完全理解了这节课的内容。你从中体会到了知识的乐趣。" << endl;
    //越**，加的越少
    p.IQ_change(rand() % generate_increment(p.get_IQ(), 300));
    p.happiness_change(rand() % 3);
    if (studying_atmosphere < 300)
    {
        studying_atmosphere++;
    }
}
void classroom::fall_asleep(people &p)
{
    Sleep(delay_time);
    cout << "你觉得很困，于是你睡着了。" << endl;
    if (studying_atmosphere > 0)
    {
        studying_atmosphere--;
    }
}
void classroom::can_t_understand(people &p)
{
    Sleep(delay_time);
    cout << "你试图去理解老师讲的内容，但是发现你完全做不到。你很痛苦。" << endl;
    p.happiness_change(-rand() % 3);
}
void classroom::find_a_friend(people &p)
{
    Sleep(delay_time);
    cout << "你在课后与同学交流起了题目，你们在交流中加深了对知识的理解。" << endl;
    p.IQ_change(rand() % (generate_increment(p.get_IQ(), 300) / 2));
    p.EQ_change(1);
    if (rand() % 2)
    {
        Sleep(delay_time);
        cout << "在交流过程中，你发现一位同学与你意趣相投，你们交换了微信。你认识了一位新朋友。" << endl;
        string name;
        generate_name(name);
        p.get_friend(name);
        p.happiness_change(1);
    }
}
void classroom::find_a_gril_friend(people &p)
{ //陈淦豪版
    Sleep(delay_time);
    cout << "热爱学习的你发现每次都有一个女生和你一样，早早地来到教室，坐在第一排。你们之前也会不时讨论问题，交流心得，"
            "你们慢慢熟络。今天恰好是5月20日，那个女生低着头过来给了你一封信......"
        << endl;
    string name;
    generate_name(name);
    p.get_mate(name);
    p.happiness_change(5);
}
void classroom::event(people &player)
{ // player进入该地点
    Sleep(delay_time);
    show();
    // cout << "你在0号教室" << endl;
    int sel = select(player);
    if (sel == 0)
    {
        learn_well(player);
    }
    else if (sel == 1)
    {
        fall_asleep(player);
    }
    else if (sel == 2)
    {
        can_t_understand(player);
    }
    else if (sel == 3)
    {
        find_a_friend(player);
    }
    else if (sel == 4)
    {
        find_a_gril_friend(player);
    }
    else
    {
        Sleep(delay_time);
        cout << "没有这个地点" << endl; //此处应抛出异常
    }
}

//company class
company::company(int l, string s, int pressure) : place(s, l), pressure(pressure){} 
void company::show()
{
        
    Sleep(delay_time);
    if (ini == 0){
        cout << "这是你第一次来到公司" << endl;
        Sleep(delay_time);
        cout<<"公司，市场经济的重要成分"<<endl;
        Sleep(delay_time);
        cout<<"你可以从公司获取金钱（money），但与此同时，你要付出一些东西"<<endl;
        Sleep(delay_time);
        cout << "公司的压力氛围与你的属性的差异会导致不同事件的发生" << endl;
        Sleep(delay_time);
        cout << "你是并不是一名全日制员工，你可以选择一直不来公司" << endl;
        Sleep(delay_time);
    }
    cout << "*******************************" << endl;
    cout << "*   老板 *                    *" << endl;
    cout << "*        *                    *" << endl;
    cout << "**********                    *" << endl;
    cout << "*                员工         *" << endl;
    cout << "*                             *" << endl;
    cout << "*                             *" << endl;
    cout << "*                             *" << endl;
    cout << "************门门门**************" << endl;
}

void company::event(people &player)
    {
        show();
        cout<<"你进入了公司"<<endl;
        Sleep(delay_time);
        int temp=rand();
        if(temp%2==0&&pressure<=30)
        {
            cout << "没有特别的任务，你可以选择做一些日常性的事物" << endl;
            Sleep(delay_time);
            cout << "0.打扫卫生 1.摸鱼 2.整理文件" << endl;
            Sleep(delay_time);
            int choice;
            cin>>choice;
            if(choice==0)
            {
                cout<<"你开始打扫卫生"<<endl;
                Sleep(delay_time);
                cout<<"打扫完成"<<endl;
                player.money_change(10);
                player.physique_change(5);
                pressure += 5;
            }
            if (choice == 1)
            {
                cout << "你开始摸鱼" << endl;
                Sleep(delay_time);
                cout << "摸鱼结束" << endl;
                player.money_change(10);
                player.physique_change(0);
                pressure+=10;
            }
            if (choice == 2)
            {
                cout << "你开始整理" << endl;
                Sleep(delay_time);
                cout << "整理结束" << endl;
                player.money_change(10);
                player.physique_change(2);
                pressure += 5;
            }
        }
        else if (temp % 2 == 1 && is_im_w==0)
        {
            cout <<"“"<<player.get_name()<< "，这里有一样艰巨的任务交给你”，老板说道" << endl;
            Sleep(delay_time);
            cout << "什么任务？你问道"<< endl;
            Sleep(delay_time);
            cout<<"我需要你去找一个羽毛球拍"<<endl;
            Sleep(delay_time);
            cout<<"尽管任务很奇怪，你还是接受了"<<endl;
            player.money_change(0);
            is_im_w=1;
        }
        else if (temp % 2 == 1 && is_im_w == 1)
        {
            Sleep(delay_time);
            cout <<"“任务完成了吗?”老板问道"<<endl;
            Sleep(delay_time);
            cout <<"0.完成了 1.没有完成"<<endl;
            Sleep(delay_time);
            int choice;
            cin>>choice;
            if(choice==0)
            {
                int find=0;
                for(auto it:player.get_bag())
                {
                    if(it=="球拍")
                        find=1;
                }
                if(find==1)
                {

                    cout<<"“你真是我的最佳员工！”老板说道"<<endl;
                    player.money_change(50);
                    player.happiness_change(50);
                    
                }else{
                    cout << "“你个骗子！”老板骂道" << endl;
                    Sleep(delay_time);
                    cout<<"你被罚款了"<<endl;
                    player.money_change(-10);
                    player.happiness_change(-10);
                }
            }
            else{
                cout<<"那就快去做！"<<endl;
                player.money_change(0);
                player.happiness_change(-10);
            }
        }
    }

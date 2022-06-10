#include "company.h"
// company class
company::company(int l, string s, int pressure) : place(s, l), pressure(pressure) {}
void company::show()
{

    Sleep(delay_time);
    if (ini == 0)
    {
        cout << "这是你第一次来到公司" << endl;
        Sleep(delay_time);
        cout << "公司，市场经济的重要成分" << endl;
        Sleep(delay_time);
        cout << "你可以从公司获取金钱（money），但与此同时，你要付出一些东西" << endl;
        Sleep(delay_time);
        cout << "公司的压力氛围与你的属性的差异会导致不同事件的发生" << endl;
        Sleep(delay_time);
        cout << "你是并不是一名全日制员工，你可以选择一直不来公司" << endl;
        Sleep(delay_time);
        ini++;
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
    // show();
    cout << "你进入了公司" << endl;
    Sleep(delay_time);
    int temp = rand();
    if (temp % 2 == 0 && pressure <= 50)
    {
        cout << "没有特别的任务，你可以选择做一些日常性的事物" << endl;
        Sleep(delay_time);
        while(1){
            cout << "0.打扫卫生 1.摸鱼 2.整理文件" << endl;
            Sleep(delay_time);
            int choice;
            cin >> choice;
            if (choice == 0)
            {
                cout << "你开始打扫卫生" << endl;
                Sleep(delay_time);
                cout << "打扫完成" << endl;
                player.money_change(10);
                player.physique_change(1);
                pressure += 3;
                break;
            }
            else if (choice == 1)
            {
                cout << "你开始摸鱼" << endl;
                Sleep(delay_time);
                cout << "摸鱼结束" << endl;
                player.money_change(10);
                player.physique_change(0);
                pressure += 6;
                break;
            }
            else if (choice == 2)
            {
                cout << "你开始整理" << endl;
                Sleep(delay_time);
                cout << "整理结束" << endl;
                player.money_change(10);
                pressure += 3;
                break;
            }
            else{
                cout<<"请输入合法的选项"<<endl;
            }
        }
    }
    else if (temp % 2 == 1 && is_im_w == 0)
    {
        cout << "“" << player.get_name() << "，这里有一样艰巨的任务交给你”，老板说道" << endl;
        Sleep(delay_time);
        cout << "什么任务？你问道" << endl;
        Sleep(delay_time);
        cout << "我需要你去找一个羽毛球拍" << endl;
        Sleep(delay_time);
        cout << "尽管任务很奇怪，你还是接受了" << endl;
        player.money_change(0);
        is_im_w = 1;
    }
    else if (temp % 2 == 1 && is_im_w == 1)
    {
        Sleep(delay_time);
        cout << "“任务完成了吗?”老板问道" << endl;
        Sleep(delay_time);
        cout << "0.完成了 1.没有完成" << endl;
        Sleep(delay_time);
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            int find = 0;
            for (auto it : player.get_bag())
            {
                if (it == "球拍")
                    find = 1;
            }
            if (find == 1)
            {

                cout << "“你真是我的最佳员工！”老板说道" << endl;
                player.money_change(50);
                player.happiness_change(10);
            }
            else
            {
                cout << "“你个骗子！”老板骂道" << endl;
                Sleep(delay_time);
                cout << "你被罚款了" << endl;
                player.money_change(-10);
                player.happiness_change(-5);
            }
        }
        else
        {
            cout << "那就快去做！" << endl;
            player.money_change(0);
            player.happiness_change(-2);
        }
    }
    else if(temp % 2 == 1 && is_im_w != 1 && is_im_w != 0){
        cout<<"今天的公司看起来一切正常"<<endl;
        cout<<"你坐到了自己的工位上开始正常工作"<<endl;
        if(player.get_attractiveness()>=80){
            if(rand()%2){
                if(player.get_sex()=="m"){
                    cout<<"一位精心打扮的女孩子走了过来，向你请教一些问题"<<endl;
                    if(player.get_IQ()<=100){
                        cout<<"你有点小激动，但是发现自己也不会这个问题，只好尴尬地说俺也不会"<<endl;
                        player.happiness_change(-1);
                    }
                    else{
                        cout<<"你三下五除二解决了她的问题，收到了一脸崇拜的目光"<<endl;
                        cout<<"今天晚饭的时候有空吗？那位同事充满希冀地问。"<<endl;
                        cout<<"请做出你的选择：0，没空；1，有空啊，一起吃吗？"<<endl;
                        int choice;
                        cin>>choice;
                        if(choice==0){
                            cout<<"不好意思，我没空"<<endl;
                            cout<<"她有些失望地走了"<<endl;
                        }
                        else if(choice==1){
                            cout<<"有空啊，一起吃吗？"<<endl;
                            cout<<"她的眼睛弯成了月牙"<<endl;
                            cout<<"经过那次晚饭，你们的关系逐渐升温..."<<endl;
                            string empty;
                            if(player.get_mate()==empty){
                                string a;
                                generate_name(a);
                                player.get_mate(a);
                            }
                            else{
                                cout<<"你们的亲密举动被你的女友"<<player.get_mate()<<"抓了个现行"<<endl;
                                cout<<"两位女生痛骂了你一顿，然后全部离开了你" <<endl;
                                cout<<"你感到十分痛苦"<<endl;
                                string a;
                                player.get_mate(a);
                                player.happiness_change(-50);
                            }
                        }
                        else{
                            cout<<"“乌哩哇啦叽里古拉。”你在胡言乱语"<<endl;
                            cout<<"她被你吓跑了"<<endl;
                        }
                    }
                }
            }
        }
        cout<<"工作结束了，你收到了今天的工钱"<<endl;
        player.money_change(15);
    }
    else if(temp % 2 == 0 && pressure > 50){
        cout<<"公司中每个人都在忙碌，见有员工到来，老板立马给你分配了任务"<<endl;
        if(player.get_IQ()>=100){
            cout<<"哎呀，高技术人才啊。快去写代码！"<<endl;
            cout<<"你在老板的催促下疯狂的码代码"<<endl;
            player.IQ_change(5);
            cout<<"头发以肉眼可见的速度在减少"<<endl;
            player.happiness_change(-4);
            player.physique_change(-1);
            player.attractiveness_change(-3);
            cout<<"终于，你完成了工作"<<endl;
            player.money_change(25);
            pressure-=5;
        }
        else if(player.get_EQ()>=100){
            cout<<"哎呀，管理型人才啊。快去管理项目！"<<endl;
            cout<<"你在老板的催促下疯狂工作"<<endl;
            player.EQ_change(5);
            player.happiness_change(-2);
            if(rand()%2&&player.get_EQ()<=200){
                cout<<"由于管理时心情烦躁，你和一位员工起了争执，你被揍了"<<endl;
                player.happiness_change(-4);
                player.physique_change(-2);
                player.attractiveness_change(-3);
            }
            cout<<"终于，你完成了工作"<<endl;
            player.money_change(25);
            pressure-=5;
        }
        else {
            cout<<"哎呀，你咋啥都不会啊！怎么混进来的！"<<endl;
            cout<<"你被老板骂了一通，灰溜溜的走了"<<endl;
            player.happiness_change(-3);
        }
    }
}

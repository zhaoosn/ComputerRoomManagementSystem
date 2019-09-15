#include "CompData.h"
#include "Computer.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#define MAX 30
using namespace std;

CompData::CompData()    //构造函数
{
    for(int i=0; i<MAX; i++)
    {
        computer[i].setCompNum(i+1);
    }
/*    ifstream fin("computer.txt");
    for(int j=0; j<MAX; j++)
    {
        fin.read((char*)&c,sizeof(c));
        computer[j] = c;
    }
    fin.close();
*/

}

Computer * CompData::searchComp()     //搜索空闲电脑
{
    for(int i=0; i<MAX; i++)
        if(computer[i].getTag()==0)
            return &computer[i];
        return NULL;
}

Computer * CompData::searchNum(int compnum) //按电脑号搜索电脑
{
    for(int i=0; i<MAX; i++)
        if(computer[i].getCompNum()==compnum)
            return &computer[i];
        return NULL;
}

int CompData::upcomp()      //上机
{
    Computer * p = searchComp();    //查找空余电脑
    Computer p2;
    Student s;
    if(p == NULL) {
        cout<<"机房已满，上机失败！"<<endl;
        return 0;
    }
    while(true) {
        cin.clear();    //清空缓冲区
        cin.sync();
        cout<<"请输入机位："<<endl;
        int num;
        cin>>num;
        if(num>-1 && num<31)    {
            if(computer[num-1].getTag()==0) {
                computer[num-1].upcomp();
                computer[num-1].setCompNum(num);
                return computer[num-1].getCompNum();
                break;
            }
            else    {
                cout<<"该电脑正在被人使用，请重新选择！"<<endl;
                continue;
            }
        }
        else    {
            cout<<"输入有误，请重新输入！"<<endl;
            continue;
        }

        }


    //p->upcomp();
    //return p->getCompNum();

}

void CompData::disp()  //显示
{
    cout<<'\n'<<endl<<"电脑使用情况如下，'1'为被使用中，'0'为空闲中！"<<'\n'<<endl;
    for(int i=0; i<MAX; i++)  {
        cout<<"  "<<computer[i].getTag()<<"  ";
        if((i+1)%6==0)
            cout<<endl;
    }
}

void CompData::disp2()  //显示
{
    cout<<endl<<"空闲电脑的电脑号如下："<<'\n'<<endl;
    for(int i=0; i<MAX; i++)  {
        if(computer[i].getTag()==0)   {
            cout<<"\t"<<computer[i].getCompNum()<<"  ";
            if((i+1)%6==0)
            cout<<endl;
        }
        else    {
            if((i+1)%6==0)
                cout<<endl;
            else
                cout<<"\t";

        }

    }
}



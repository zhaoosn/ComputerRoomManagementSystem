#include <iostream>
#include <string.h>
#include <windows.h>
#include "Student.h"
#include "StuData.h"
#include "Computer.h"
#include "CompData.h"

#define MAX 30

using namespace std;


StuData StudentD;
Student * s;
CompData ComputerD;
Computer * c;


int main()
{
    int select;
    char name[MAX];
	int ID;
	int clas;
	int num;    //选择机位

    while(true) {
        cout<<"****************************************"<<endl;
        cout<<"**************机房学生查询**************"<<endl;
        cout<<"************   1.上机         **********"<<endl;
        cout<<"************   2.下机         **********"<<endl;
        cout<<"************   3.机房学生查询 **********"<<endl;
        cout<<"************   4.电脑使用情况 **********"<<endl;
        cout<<"************   0.退出         **********"<<endl;
        cout<<"****************************************"<<endl;
        cout<<"请输入您想进行操作所对应的编号:"<<endl;
        cin>>select;

        cin.clear();    //清空缓冲区
        cin.sync();

        switch(select)
        {
        case 1:     //上机操作
            {
                system("cls");

                cout<<endl<<endl<<"请输入上机人信息："<<endl;
                cout<<"姓名："<<endl;
                cin>>name;
                cout<<"学号："<<endl;
                cin>>ID;
                cout<<"班级："<<endl;
                cin>>clas;

                if(strlen(name)<=MAX && ID>0 && clas>0) {   //判断输入格式
                    s = StudentD.searchID(ID);

                    if(s==NULL && (ComputerD.searchComp())!=NULL) {

                        ComputerD.disp2();


                        StudentD.upcomp(name,ID,clas,ComputerD.upcomp());
                        s = StudentD.searchID(ID);


                        //system("cls");
                        s->show2();
                        system("pause");
                        system("cls");
                    }
                    else
                        if(s==NULL) {
                            cout<<"机房已满，请耐心等待！"<<endl;
                            system("pause");
                            system("cls");
                        }
                        else    {
                            cout<<"该学号正被使用，请重新确认后上机！"<<endl;
                            system("pause");
                            system("cls");
                        }
                }
                else
                {
                    cout<<endl<<"------上机失败------"<<endl;
                    cout<<"格式有误，请确认后重新上机！"<<endl;
                    system("pause");
                    system("cls");
                }
                break;
            }
        case 2:     //下机操作
            {
                system("cls");
                cout<<"请输入需要下机的人的学号："<<endl;
                cin>>ID;
                s = StudentD.searchID(ID);
                if(s!=NULL)
                {
                    c = ComputerD.searchNum(s->getCompNum());
                    cout<<"下机成功！"<<endl;
                    s->downcomp();
                    c->downcomp();
                    system("pause");
                    system("cls");
                }
                else
                    cout<<"机房没有此人，请重新确认后再下机！"<<endl;
                break;
            }
        case 3:     //学生查询
            {
                system("cls");
                StudentD.search();
                break;

            }
        case 4:     //电脑使用情况
            {
                system("cls");  //清屏函数
                ComputerD.disp();
                system("pause");
                system("cls");
                break;

            }
        case 0:     //退出
            {
                cout<<"您确定要退出当前管理系统？（1--是  2--否）："<<endl;
                int chanc = 0;
                cin>>chanc;
                if(chanc == 1)  {
                    cout<<"欢迎下次使用！"<<endl;
                    exit(0);
                }
                else
                {
                    system("cls");
                    continue;
                }
            }
        default:
            {
                cout<<"输入有误，请重新输入！"<<endl;
                Sleep(1000);
                system("cls");
            }
        }

    }



    return 0;
}

#include "StuData.h"
#include <iostream>
#include "Student.h"
#include <string.h>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

StuData::StuData()                //构造函数
	{
		top = -1;
	}

Student * StuData::searchID(int ID)  //按学号搜索
	{
		for(int i=0; i<=top; i++)
			if(student[i].getID()==ID && student[i].getTag()==1)
			{
				return &student[i];
			}
		return NULL;
	}

Student * StuData::searchClas(int clas)  //按班级搜索
	{
		for(int i=0; i<=top; i++)
			if(student[i].getClas()==clas && student[i].getTag()==1)
			{
				return &student[i];
			}
		return NULL;
	}

void StuData::showClas(int clas)  //按班级显示
	{
		for(int j=0; j<=top; j++)
			if(student[j].getClas()==clas && student[j].getTag()==1)
			{
				student[j].setotime();
				student[j].show();
				cout<<endl;
			}
	}

Student * StuData::searchName(char * name)  //按姓名搜索
	{
		for(int i=0; i<=top; i++)
			if(!strcmp(student[i].getName(),name) && student[i].getTag()==1)
			{
				return &student[i];
			}
		return NULL;
	}

void StuData::showAll()    //显示所有学生
	{
		if(top > -1)  {
        for(int i=0; i<=top; i++)
            if(student[i].getTag()==1)
			{
				student[i].setotime();
				student[i].show();
				cout<<endl;
			}
		}
		else
            cout<<"机房无人上机！"<<'\n'<<endl;

	}

void StuData::upcomp(char name[MAX], int ID, int clas, int compNum)  //上机
	{
		top++;
		student[top].upcomp(name, ID, clas, compNum);
	}

int StuData::search()     //机房学生查询
	{
		int choice;
		char name[MAX];
		int ID;
		int clas;
		Student * s;
	    while(true)
		{
			cout<<'\n'<<endl<<"--------机房学生查询--------"<<'\n'<<endl;
			cout<<"------1. 按姓名查询   ------"<<endl;
			cout<<"------2. 按学号查询   ------"<<endl;
			cout<<"------3. 按班级查询   ------"<<endl;
			cout<<"------4. 全部学生信息 ------"<<endl;
			cout<<"------0. 返回主菜单   ------"<<endl;
			cin>>choice;
			switch(choice)
			{
			case 1:
			    {
                    system("cls");
                    cout<<"请输入学生姓名："<<endl;
                    cin>>name;
                    s = searchName(name);
                    if(s==NULL)
                    {
                        cout<<"机房没有此人"<<endl;
                        break;
                    }
                    s->setotime();
                    s->show();
                    break;
			    }
			case 2:
			    {
                    system("cls");
                    cout<<"请输入学生学号："<<endl;
                    cin>>ID;
                    s = searchID(ID);
                    if(s==NULL)
                    {
                        cout<<"机房没有此人"<<endl;
                        break;
                    }
                    s->setotime();
                    s->show();
                    break;
			    }
			case 3:
			    {
                    system("cls");
                    cout<<"请输入班级号："<<endl;
                    cin>>clas;
                    s = searchClas(clas);
                    if(s==NULL)
                    {
                        cout<<"机房没有该班级的人！"<<endl;
                        break;
                    }
                    showClas(clas);
                    break;
			    }
			case 4:
			    {
                    system("cls");
                    cout<<'\n'<<endl<<"**********机房所有上机学生信息如下**********"<<'\n'<<endl;
                    showAll();
                    break;
			    }
			case 0:
			    {
                system("cls");
			    return 0;
			    }

			default:
				cout<<"输入有误，请重新输入："<<endl;
			}
		cout<<"按任意键返回"<<endl;
        getch();
        system("cls");
		}
	}


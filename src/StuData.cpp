#include "StuData.h"
#include <iostream>
#include "Student.h"
#include <string.h>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

StuData::StuData()                //���캯��
	{
		top = -1;
	}

Student * StuData::searchID(int ID)  //��ѧ������
	{
		for(int i=0; i<=top; i++)
			if(student[i].getID()==ID && student[i].getTag()==1)
			{
				return &student[i];
			}
		return NULL;
	}

Student * StuData::searchClas(int clas)  //���༶����
	{
		for(int i=0; i<=top; i++)
			if(student[i].getClas()==clas && student[i].getTag()==1)
			{
				return &student[i];
			}
		return NULL;
	}

void StuData::showClas(int clas)  //���༶��ʾ
	{
		for(int j=0; j<=top; j++)
			if(student[j].getClas()==clas && student[j].getTag()==1)
			{
				student[j].setotime();
				student[j].show();
				cout<<endl;
			}
	}

Student * StuData::searchName(char * name)  //����������
	{
		for(int i=0; i<=top; i++)
			if(!strcmp(student[i].getName(),name) && student[i].getTag()==1)
			{
				return &student[i];
			}
		return NULL;
	}

void StuData::showAll()    //��ʾ����ѧ��
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
            cout<<"���������ϻ���"<<'\n'<<endl;

	}

void StuData::upcomp(char name[MAX], int ID, int clas, int compNum)  //�ϻ�
	{
		top++;
		student[top].upcomp(name, ID, clas, compNum);
	}

int StuData::search()     //����ѧ����ѯ
	{
		int choice;
		char name[MAX];
		int ID;
		int clas;
		Student * s;
	    while(true)
		{
			cout<<'\n'<<endl<<"--------����ѧ����ѯ--------"<<'\n'<<endl;
			cout<<"------1. ��������ѯ   ------"<<endl;
			cout<<"------2. ��ѧ�Ų�ѯ   ------"<<endl;
			cout<<"------3. ���༶��ѯ   ------"<<endl;
			cout<<"------4. ȫ��ѧ����Ϣ ------"<<endl;
			cout<<"------0. �������˵�   ------"<<endl;
			cin>>choice;
			switch(choice)
			{
			case 1:
			    {
                    system("cls");
                    cout<<"������ѧ��������"<<endl;
                    cin>>name;
                    s = searchName(name);
                    if(s==NULL)
                    {
                        cout<<"����û�д���"<<endl;
                        break;
                    }
                    s->setotime();
                    s->show();
                    break;
			    }
			case 2:
			    {
                    system("cls");
                    cout<<"������ѧ��ѧ�ţ�"<<endl;
                    cin>>ID;
                    s = searchID(ID);
                    if(s==NULL)
                    {
                        cout<<"����û�д���"<<endl;
                        break;
                    }
                    s->setotime();
                    s->show();
                    break;
			    }
			case 3:
			    {
                    system("cls");
                    cout<<"������༶�ţ�"<<endl;
                    cin>>clas;
                    s = searchClas(clas);
                    if(s==NULL)
                    {
                        cout<<"����û�иð༶���ˣ�"<<endl;
                        break;
                    }
                    showClas(clas);
                    break;
			    }
			case 4:
			    {
                    system("cls");
                    cout<<'\n'<<endl<<"**********���������ϻ�ѧ����Ϣ����**********"<<'\n'<<endl;
                    showAll();
                    break;
			    }
			case 0:
			    {
                system("cls");
			    return 0;
			    }

			default:
				cout<<"�����������������룺"<<endl;
			}
		cout<<"�����������"<<endl;
        getch();
        system("cls");
		}
	}


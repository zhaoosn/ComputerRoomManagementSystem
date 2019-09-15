#include "CompData.h"
#include "Computer.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#define MAX 30
using namespace std;

CompData::CompData()    //���캯��
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

Computer * CompData::searchComp()     //�������е���
{
    for(int i=0; i<MAX; i++)
        if(computer[i].getTag()==0)
            return &computer[i];
        return NULL;
}

Computer * CompData::searchNum(int compnum) //�����Ժ���������
{
    for(int i=0; i<MAX; i++)
        if(computer[i].getCompNum()==compnum)
            return &computer[i];
        return NULL;
}

int CompData::upcomp()      //�ϻ�
{
    Computer * p = searchComp();    //���ҿ������
    Computer p2;
    Student s;
    if(p == NULL) {
        cout<<"�����������ϻ�ʧ�ܣ�"<<endl;
        return 0;
    }
    while(true) {
        cin.clear();    //��ջ�����
        cin.sync();
        cout<<"�������λ��"<<endl;
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
                cout<<"�õ������ڱ���ʹ�ã�������ѡ��"<<endl;
                continue;
            }
        }
        else    {
            cout<<"�����������������룡"<<endl;
            continue;
        }

        }


    //p->upcomp();
    //return p->getCompNum();

}

void CompData::disp()  //��ʾ
{
    cout<<'\n'<<endl<<"����ʹ��������£�'1'Ϊ��ʹ���У�'0'Ϊ�����У�"<<'\n'<<endl;
    for(int i=0; i<MAX; i++)  {
        cout<<"  "<<computer[i].getTag()<<"  ";
        if((i+1)%6==0)
            cout<<endl;
    }
}

void CompData::disp2()  //��ʾ
{
    cout<<endl<<"���е��Եĵ��Ժ����£�"<<'\n'<<endl;
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



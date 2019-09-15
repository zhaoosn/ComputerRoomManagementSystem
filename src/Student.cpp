#include "Student.h"
#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;

Student::Student()
{

}

char * Student::getName()  //��ȡ����
	{
		return m_name;
	}

int Student::getID()   //��ȡѧ��
	{
		return m_ID;
	}

int Student::getClas()  //��ȡ�༶
	{
		return m_clas;
	}

int Student::getTag()  //��ȡ�ϻ����
	{
		return tag;
	}

void Student::tagChange()  //�����ϻ����
    {
		tag=0;
	}

int Student::getCompNum()   //��ȡ�ϻ���
	{
		return m_compNum;
	}

time_t Student::getTime()  //��ȡ��ǰʱ��
	{
		return time(NULL);
	}

void Student::setotime()  //��ȡ�»�ʱ��
	{
		otime=getTime();
	}

void Student::upcomp(char name[MAX], int ID, int clas, int compNum) //�ϻ�����
{
    strcpy(m_name,name);
    tag = 1;
    m_ID = ID;
    m_clas = clas;
    m_compNum = compNum;
    stime = getTime();
}

int Student::downcomp()     //�»�
    {
        otime = getTime();
        setotime();
        tagChange();
        show();
        return m_compNum;
	}

double Student::countht()   //�������ϻ�ʱ��
	{
		return difftime(otime,stime);
	}

int Student::countm()  //�����ϻ�����
	{
		if(((int)countht())%3600==0)
			return ((int)countht())/3600;
		return ((int)countht()/3600)+1;
	}

void Student::show()  //��ʾ
	{
		cout<<"������"<<m_name<<"  "<<"�༶��"<<m_clas<<"  "<<"ѧ�ţ�"<<m_ID<<"  "<<"�ϻ��ţ�"<<m_compNum<<endl;
		cout<<"��ʼ�ϻ�ʱ�䣺"<<asctime(localtime(&stime))<<"  "<<"�ϻ���ʱ�䣺"<<countht()/60.00<<"����"<<"  "<<"�ϻ����ã�"<<countm()<<"Ԫ"<<endl;
	}

void Student::show2()  //��ʾ
    {
        cout<<'\n'<<endl<<"   -----�ϻ��ɹ�-----"<<endl;
        cout<<"������"<<m_name<<endl
            <<"�༶��"<<m_clas<<endl
            <<"ѧ�ţ�"<<m_ID<<endl
            <<"��ʼ�ϻ�ʱ�䣺"<<asctime(localtime(&stime))<<"�ϻ��ţ�"<<m_compNum<<endl;
    }



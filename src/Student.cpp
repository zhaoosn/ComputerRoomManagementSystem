#include "Student.h"
#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;

Student::Student()
{

}

char * Student::getName()  //获取姓名
	{
		return m_name;
	}

int Student::getID()   //获取学号
	{
		return m_ID;
	}

int Student::getClas()  //获取班级
	{
		return m_clas;
	}

int Student::getTag()  //获取上机标记
	{
		return tag;
	}

void Student::tagChange()  //更改上机标记
    {
		tag=0;
	}

int Student::getCompNum()   //获取上机号
	{
		return m_compNum;
	}

time_t Student::getTime()  //获取当前时间
	{
		return time(NULL);
	}

void Student::setotime()  //获取下机时间
	{
		otime=getTime();
	}

void Student::upcomp(char name[MAX], int ID, int clas, int compNum) //上机操作
{
    strcpy(m_name,name);
    tag = 1;
    m_ID = ID;
    m_clas = clas;
    m_compNum = compNum;
    stime = getTime();
}

int Student::downcomp()     //下机
    {
        otime = getTime();
        setotime();
        tagChange();
        show();
        return m_compNum;
	}

double Student::countht()   //计算总上机时间
	{
		return difftime(otime,stime);
	}

int Student::countm()  //计算上机费用
	{
		if(((int)countht())%3600==0)
			return ((int)countht())/3600;
		return ((int)countht()/3600)+1;
	}

void Student::show()  //显示
	{
		cout<<"姓名："<<m_name<<"  "<<"班级："<<m_clas<<"  "<<"学号："<<m_ID<<"  "<<"上机号："<<m_compNum<<endl;
		cout<<"开始上机时间："<<asctime(localtime(&stime))<<"  "<<"上机总时间："<<countht()/60.00<<"分钟"<<"  "<<"上机费用："<<countm()<<"元"<<endl;
	}

void Student::show2()  //显示
    {
        cout<<'\n'<<endl<<"   -----上机成功-----"<<endl;
        cout<<"姓名："<<m_name<<endl
            <<"班级："<<m_clas<<endl
            <<"学号："<<m_ID<<endl
            <<"开始上机时间："<<asctime(localtime(&stime))<<"上机号："<<m_compNum<<endl;
    }



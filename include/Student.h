#ifndef STUDENT_H
#define STUDENT_H
#include "time.h"
#define MAX 30


class Student
{
public:
    Student();
    char * getName();    //获取姓名
	int getID();        //获取学号
	int getClas();       //获取班级
	int getCompNum();    //获取上机号
	int getTag();       //获取上机标记
	time_t getTime();   //获取当前时间
	void setotime();    //获取下机时间
    void upcomp(char name[MAX], int ID, int clas, int compNum); //上机操作
    int downcomp();      //下机
	void tagChange();      //更改上机标记
	double countht();      //计算总上机时间
	int countm();       //计算上机费用
	void show();        //显示
	void show2();       //显示2

private:
    int tag;            //标记
    char m_name[MAX];   //姓名
    int m_ID;           //学号
    int m_clas;        //班级
    int m_compNum;      //电脑号
    time_t stime;       //开始时间
    time_t otime;       //结束时间
    double htime;       //总时间
    int money;          //网费


};

#endif // STUDENT_H

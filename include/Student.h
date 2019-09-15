#ifndef STUDENT_H
#define STUDENT_H
#include "time.h"
#define MAX 30


class Student
{
public:
    Student();
    char * getName();    //��ȡ����
	int getID();        //��ȡѧ��
	int getClas();       //��ȡ�༶
	int getCompNum();    //��ȡ�ϻ���
	int getTag();       //��ȡ�ϻ����
	time_t getTime();   //��ȡ��ǰʱ��
	void setotime();    //��ȡ�»�ʱ��
    void upcomp(char name[MAX], int ID, int clas, int compNum); //�ϻ�����
    int downcomp();      //�»�
	void tagChange();      //�����ϻ����
	double countht();      //�������ϻ�ʱ��
	int countm();       //�����ϻ�����
	void show();        //��ʾ
	void show2();       //��ʾ2

private:
    int tag;            //���
    char m_name[MAX];   //����
    int m_ID;           //ѧ��
    int m_clas;        //�༶
    int m_compNum;      //���Ժ�
    time_t stime;       //��ʼʱ��
    time_t otime;       //����ʱ��
    double htime;       //��ʱ��
    int money;          //����


};

#endif // STUDENT_H

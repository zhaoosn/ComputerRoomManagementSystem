#ifndef STUDATA_H
#define STUDATA_H
#include "Student.h"
#define MAX 30

class StuData
{
public:
    StuData();
    Student * searchName(char * name);  //����������
    Student * searchID(int ID);         //��ѧ������
    Student * searchClas(int clas);     //���༶����
    void upcomp(char name[MAX], int ID, int clas, int compNum); //�ϻ�����
    void showClas(int clas);        //���༶��ʾ
    void showAll();             //��ʾ����ѧ��
    int search();               //����ѧ����ѯ


private:
    int top;
    Student student[MAX];

};

#endif // STUDATA_H

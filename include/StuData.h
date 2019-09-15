#ifndef STUDATA_H
#define STUDATA_H
#include "Student.h"
#define MAX 30

class StuData
{
public:
    StuData();
    Student * searchName(char * name);  //按姓名搜索
    Student * searchID(int ID);         //按学号搜索
    Student * searchClas(int clas);     //按班级搜索
    void upcomp(char name[MAX], int ID, int clas, int compNum); //上机操作
    void showClas(int clas);        //按班级显示
    void showAll();             //显示所有学生
    int search();               //机房学生查询


private:
    int top;
    Student student[MAX];

};

#endif // STUDATA_H

#ifndef COMPDATA_H
#define COMPDATA_H

#include "Computer.h"

class CompData
{
public:
	CompData();    //���캯��
	Computer * searchComp();     //�������е���
	Computer * searchNum(int compnum); //�����Ժ���������
	int upcomp();      //�ϻ�
	void disp();    //��ʾ
	void disp2();


private:
	Computer computer[30];

};

#endif // COMPDATA_H

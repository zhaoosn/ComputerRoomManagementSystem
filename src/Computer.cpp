#include "Computer.h"

Computer::Computer()   //���캯��
	{
		tag = 0;
	}

void Computer::setCompNum(int compnum)  //���õ��Ժ�
	{
		m_compnum = compnum;
	}

int Computer::getCompNum()    //��ȡ���Ժ�
	{
		return m_compnum;
	}

void Computer::upcomp()     //�ϻ�
	{
		tag = 1;
	}

void Computer::downcomp()  //�»�
	{
		tag = 0;
	}

int Computer::getTag()  //��ȡ�ϻ����
	{
		return tag;
	}

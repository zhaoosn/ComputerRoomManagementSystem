#include "Computer.h"

Computer::Computer()   //构造函数
	{
		tag = 0;
	}

void Computer::setCompNum(int compnum)  //设置电脑号
	{
		m_compnum = compnum;
	}

int Computer::getCompNum()    //获取电脑号
	{
		return m_compnum;
	}

void Computer::upcomp()     //上机
	{
		tag = 1;
	}

void Computer::downcomp()  //下机
	{
		tag = 0;
	}

int Computer::getTag()  //获取上机标记
	{
		return tag;
	}

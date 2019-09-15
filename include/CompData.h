#ifndef COMPDATA_H
#define COMPDATA_H

#include "Computer.h"

class CompData
{
public:
	CompData();    //构造函数
	Computer * searchComp();     //搜索空闲电脑
	Computer * searchNum(int compnum); //按电脑号搜索电脑
	int upcomp();      //上机
	void disp();    //显示
	void disp2();


private:
	Computer computer[30];

};

#endif // COMPDATA_H

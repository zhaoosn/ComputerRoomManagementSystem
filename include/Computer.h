#ifndef COMPUTER_H
#define COMPUTER_H


class Computer
{
public:
	Computer();   //构造函数
	void setCompNum(int compnum);  //设置电脑号
	int getCompNum();        //获取电脑号
	void upcomp();           //上机
	void downcomp();         //下机
	int getTag();           //获取上机标记

private:
	int tag;
	int m_compnum;


};

#endif // COMPUTER_H

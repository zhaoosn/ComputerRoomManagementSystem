#ifndef COMPUTER_H
#define COMPUTER_H


class Computer
{
public:
	Computer();   //���캯��
	void setCompNum(int compnum);  //���õ��Ժ�
	int getCompNum();        //��ȡ���Ժ�
	void upcomp();           //�ϻ�
	void downcomp();         //�»�
	int getTag();           //��ȡ�ϻ����

private:
	int tag;
	int m_compnum;


};

#endif // COMPUTER_H

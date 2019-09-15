#include <iostream>
#include <string.h>
#include <windows.h>
#include "Student.h"
#include "StuData.h"
#include "Computer.h"
#include "CompData.h"

#define MAX 30

using namespace std;


StuData StudentD;
Student * s;
CompData ComputerD;
Computer * c;


int main()
{
    int select;
    char name[MAX];
	int ID;
	int clas;
	int num;    //ѡ���λ

    while(true) {
        cout<<"****************************************"<<endl;
        cout<<"**************����ѧ����ѯ**************"<<endl;
        cout<<"************   1.�ϻ�         **********"<<endl;
        cout<<"************   2.�»�         **********"<<endl;
        cout<<"************   3.����ѧ����ѯ **********"<<endl;
        cout<<"************   4.����ʹ����� **********"<<endl;
        cout<<"************   0.�˳�         **********"<<endl;
        cout<<"****************************************"<<endl;
        cout<<"������������в�������Ӧ�ı��:"<<endl;
        cin>>select;

        cin.clear();    //��ջ�����
        cin.sync();

        switch(select)
        {
        case 1:     //�ϻ�����
            {
                system("cls");

                cout<<endl<<endl<<"�������ϻ�����Ϣ��"<<endl;
                cout<<"������"<<endl;
                cin>>name;
                cout<<"ѧ�ţ�"<<endl;
                cin>>ID;
                cout<<"�༶��"<<endl;
                cin>>clas;

                if(strlen(name)<=MAX && ID>0 && clas>0) {   //�ж������ʽ
                    s = StudentD.searchID(ID);

                    if(s==NULL && (ComputerD.searchComp())!=NULL) {

                        ComputerD.disp2();


                        StudentD.upcomp(name,ID,clas,ComputerD.upcomp());
                        s = StudentD.searchID(ID);


                        //system("cls");
                        s->show2();
                        system("pause");
                        system("cls");
                    }
                    else
                        if(s==NULL) {
                            cout<<"���������������ĵȴ���"<<endl;
                            system("pause");
                            system("cls");
                        }
                        else    {
                            cout<<"��ѧ������ʹ�ã�������ȷ�Ϻ��ϻ���"<<endl;
                            system("pause");
                            system("cls");
                        }
                }
                else
                {
                    cout<<endl<<"------�ϻ�ʧ��------"<<endl;
                    cout<<"��ʽ������ȷ�Ϻ������ϻ���"<<endl;
                    system("pause");
                    system("cls");
                }
                break;
            }
        case 2:     //�»�����
            {
                system("cls");
                cout<<"��������Ҫ�»����˵�ѧ�ţ�"<<endl;
                cin>>ID;
                s = StudentD.searchID(ID);
                if(s!=NULL)
                {
                    c = ComputerD.searchNum(s->getCompNum());
                    cout<<"�»��ɹ���"<<endl;
                    s->downcomp();
                    c->downcomp();
                    system("pause");
                    system("cls");
                }
                else
                    cout<<"����û�д��ˣ�������ȷ�Ϻ����»���"<<endl;
                break;
            }
        case 3:     //ѧ����ѯ
            {
                system("cls");
                StudentD.search();
                break;

            }
        case 4:     //����ʹ�����
            {
                system("cls");  //��������
                ComputerD.disp();
                system("pause");
                system("cls");
                break;

            }
        case 0:     //�˳�
            {
                cout<<"��ȷ��Ҫ�˳���ǰ����ϵͳ����1--��  2--�񣩣�"<<endl;
                int chanc = 0;
                cin>>chanc;
                if(chanc == 1)  {
                    cout<<"��ӭ�´�ʹ�ã�"<<endl;
                    exit(0);
                }
                else
                {
                    system("cls");
                    continue;
                }
            }
        default:
            {
                cout<<"�����������������룡"<<endl;
                Sleep(1000);
                system("cls");
            }
        }

    }



    return 0;
}

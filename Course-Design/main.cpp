#include <windows.h>  
#include <stdio.h>  
#include<iostream>
using namespace std;
#include"tree.h"
void fill_cmd() {				//�������
	string fill_str = "";
	for (int i = 1; i < 100 * 100; i++)
	{
		if (i % 99 != 0)
			fill_str += " ";
		else fill_str += "\n";
	}
	cout << fill_str;
}
int main() {
	// ��ȡ��׼��������豸���  
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD	mouseRec;
	DWORD			res;
	COORD			crPos, crHome = { 0, 0 };
	tree a = tree();
	string fill_str = "";
	int flag1 = 1, flag2 = 1, flag3 = 1;
	while (flag1)							//��ѭ��
	{
		SetConsoleCursorPosition(hOut, { 0,0 });
		printf("����굱ǰλ�á� X: %2lu  Y: %2lu �����˫�����˴��˳�����ϵͳ��\n", 0, 0);	// ��ʼ״̬
		cout << "\t\t\t��ҵ����ϵͳ\n"
			<< "\t1.�½���ҵԱ����״��\t2.���ļ��ж�ȡ��״��\n"
			<<"\t3.��ӡ��ҵԱ����״��\t4.��ѯ��Ŀͳ����Ϣ\n"
			<<"\t5.�������ļ�";
		while (flag2)						//�û�������ȡ
		{
			ReadConsoleInput(hIn, &mouseRec, 1, &res);
			if (mouseRec.EventType == MOUSE_EVENT)
			{
				crPos = mouseRec.Event.MouseEvent.dwMousePosition;
				GetConsoleScreenBufferInfo(hOut, &bInfo);
				SetConsoleCursorPosition(hOut, crHome);
				printf("����굱ǰλ�á� X: %2lu  Y: %2lu �����˫�����˴��˳�����ϵͳ��\n", crPos.X, crPos.Y);
				if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
					{
						crPos = mouseRec.Event.MouseEvent.dwMousePosition;
						break;
					}
				}
			}
		}
		//���ݵ��λ���жϸ���ʲô
		if (crPos.Y == 0) {					//�˳�ϵͳ	
			SetConsoleCursorPosition(hOut, { 0,0 });
			fill_cmd();
			flag1 = 0; break; 
		}
		else
		{
			SetConsoleCursorPosition(hOut, { 0,10 });
			fill_cmd();
			SetConsoleCursorPosition(hOut, { 0,10 });
			if (crPos.Y == 2) {					//�ڶ��е�ѡ��
				if (crPos.X < 30)
				{
					a.create_tree();
				}
				else
				{
					a.load_tree();
				}
			}
			if (crPos.Y == 3) {					//�ڶ��е�ѡ��
				if (crPos.X < 30)
				{
					a.print_tree();
				}
				else
				{
					cout << "����ͳ�Ƶ���Ŀ: ";
					string str;
					cin >> str;
					a.print_statistics(str);
				}
			}
			if (crPos.Y == 4) {
				if (crPos.X < 30) {
					a.save_tree();
				}
				if (crPos.X > 30) {

				}
			}
		}

	}
	system("pause");
	CloseHandle(hOut);  // �رձ�׼����豸���  
	CloseHandle(hIn);   // �رձ�׼�����豸��� 
	return 0;

}
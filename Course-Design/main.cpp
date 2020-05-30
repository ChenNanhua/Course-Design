#include <windows.h>  
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
		cout << "����굱ǰλ�á� X: 0  Y: 0 �����˫�����˴��˳�����ϵͳ��" << endl;	// ��ʼ״̬
		cout << "\t\t\t��ҵ����ϵͳ\n"
			<< "\t1.�½���ҵԱ����״��\t2.���ļ��ж�ȡ��״��\n"
			<< "\t3.��ӡ��ҵԱ����״��\t4.��ѯ��Ŀͳ����Ϣ\n"
			<< "\t5.����Ա����ָ���ڵ�\t6.ɾ��ָ��Ա��\n"
			<< "\t7.��ӡԱ����Ϣ\t\t8.�޸�Ա����Ϣ\n"
			<< "\t\t\t\t9.������ҵ��Ϣ���ļ�";
		while (flag2)						//�û�������ȡ
		{
			ReadConsoleInput(hIn, &mouseRec, 1, &res);
			if (mouseRec.EventType == MOUSE_EVENT)
			{
				crPos = mouseRec.Event.MouseEvent.dwMousePosition;
				GetConsoleScreenBufferInfo(hOut, &bInfo);
				SetConsoleCursorPosition(hOut, crHome);
				cout << "����굱ǰλ�á� X: " << crPos.X << " Y: " << crPos.Y << "�����˫�����˴��˳�����ϵͳ��\n";
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
		if (crPos.Y == 0) {					//�������0�У��˳�ϵͳ	
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
					a.create_tree();
				else
					a.load_tree();
			}
			if (crPos.Y == 3) {					//�����е�ѡ��
				if (crPos.X < 30)
					a.print_tree();
				else
				{
					cout << "����ͳ�Ƶ���Ŀ: ";
					string str;
					cin >> str;
					a.print_statistics(str);
				}
			}
			if (crPos.Y == 4) {					//������ѡ��
				if (crPos.X < 30) {
					cout << "����������һ��Ա��id�����Ƿ��Ǻ��ӽڵ�: ";
					int id, child_or_not;
					cin >> id >> child_or_not;
					a.insert_node(id, child_or_not);
				}
				if (crPos.X > 30) {
					cout << "����Ҫɾ����Ա��id:";
					int id;
					cin >> id;
					a.delete_node(id);
				}
			}
			if (crPos.Y == 5) {					//�����е�ѡ��
				if (crPos.X < 30) {
					cout << "����Ҫ��ӡ��Ա��id:";
					int id;
					cin >> id;
					a.print_person(id);
				}
				else {
					cout << "����Ա��id���޸ĵ���Ŀ������: ";
					int id; string item, content;
					cin >> id >> item >> content;
					a.modify_info(id, item, content);
				}
			}
			if (crPos.Y == 6) {					//�����е�ѡ��
				a.save_tree();
			}
		}
	}
	system("pause");
	CloseHandle(hOut);  // �رձ�׼����豸���  
	CloseHandle(hIn);   // �رձ�׼�����豸��� 
	return 0;

}
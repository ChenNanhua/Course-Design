#include <windows.h>  
#include<iostream>
using namespace std;
#include"tree.h"
void fill_cmd() {				//填充清屏
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
	// 获取标准输入输出设备句柄  
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD	mouseRec;
	DWORD			res;
	COORD			crPos, crHome = { 0, 0 };
	tree a = tree();
	string fill_str = "";
	int flag1 = 1, flag2 = 1, flag3 = 1;
	while (flag1)							//总循环
	{
		SetConsoleCursorPosition(hOut, { 0,0 });
		cout << "【鼠标当前位置】 X: 0  Y: 0 （左键双击击此处退出管理系统）" << endl;	// 初始状态
		cout << "\t\t\t企业管理系统\n"
			<< "\t1.新建企业员工树状表\t2.从文件中读取树状表\n"
			<< "\t3.打印企业员工树状表\t4.查询条目统计信息\n"
			<< "\t5.插入员工到指定节点\t6.删除指定员工\n"
			<< "\t7.打印员工信息\t\t8.修改员工信息\n"
			<< "\t\t\t\t9.保存企业信息至文件";
		while (flag2)						//用户操作读取
		{
			ReadConsoleInput(hIn, &mouseRec, 1, &res);
			if (mouseRec.EventType == MOUSE_EVENT)
			{
				crPos = mouseRec.Event.MouseEvent.dwMousePosition;
				GetConsoleScreenBufferInfo(hOut, &bInfo);
				SetConsoleCursorPosition(hOut, crHome);
				cout << "【鼠标当前位置】 X: " << crPos.X << " Y: " << crPos.Y << "（左键双击击此处退出管理系统）\n";
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
		//根据点击位置判断该做什么
		if (crPos.Y == 0) {					//点击到第0行，退出系统	
			SetConsoleCursorPosition(hOut, { 0,0 });
			fill_cmd();
			flag1 = 0; break;
		}
		else
		{
			SetConsoleCursorPosition(hOut, { 0,10 });
			fill_cmd();
			SetConsoleCursorPosition(hOut, { 0,10 });
			if (crPos.Y == 2) {					//第二行的选项
				if (crPos.X < 30)
					a.create_tree();
				else
					a.load_tree();
			}
			if (crPos.Y == 3) {					//第三行的选项
				if (crPos.X < 30)
					a.print_tree();
				else
				{
					cout << "输入统计的条目: ";
					string str;
					cin >> str;
					a.print_statistics(str);
				}
			}
			if (crPos.Y == 4) {					//第四行选项
				if (crPos.X < 30) {
					cout << "输入插入的上一级员工id，及是否是孩子节点: ";
					int id, child_or_not;
					cin >> id >> child_or_not;
					a.insert_node(id, child_or_not);
				}
				if (crPos.X > 30) {
					cout << "输入要删除的员工id:";
					int id;
					cin >> id;
					a.delete_node(id);
				}
			}
			if (crPos.Y == 5) {					//第五行的选项
				if (crPos.X < 30) {
					cout << "输入要打印的员工id:";
					int id;
					cin >> id;
					a.print_person(id);
				}
				else {
					cout << "输入员工id，修改的项目及内容: ";
					int id; string item, content;
					cin >> id >> item >> content;
					a.modify_info(id, item, content);
				}
			}
			if (crPos.Y == 6) {					//第六行的选项
				a.save_tree();
			}
		}
	}
	system("pause");
	CloseHandle(hOut);  // 关闭标准输出设备句柄  
	CloseHandle(hIn);   // 关闭标准输入设备句柄 
	return 0;

}
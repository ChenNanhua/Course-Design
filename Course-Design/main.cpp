#include <windows.h>  
#include <stdio.h>  
#include<iostream>
using namespace std;
#include"tree.h"
int main() {

	{
		// ��ȡ��׼��������豸���  
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO bInfo;
		INPUT_RECORD	mouseRec;
		DWORD			res;
		COORD			crPos, crHome = { 0, 0 };
		printf("[Cursor Position] X: %2lu  Y: %2lu\n", 0, 0);	// ��ʼ״̬


		while (1)
		{
			ReadConsoleInput(hIn, &mouseRec, 1, &res);

			if (mouseRec.EventType == MOUSE_EVENT)
			{
				if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
					{
						tree *a = new tree();
						a->load_tree();
						a->print_tree();
						break;	// ���˫�� �˳�ѭ��
					}
				}

				crPos = mouseRec.Event.MouseEvent.dwMousePosition;
				GetConsoleScreenBufferInfo(hOut, &bInfo);
				SetConsoleCursorPosition(hOut, crHome);
				printf("[Cursor Position] X: %2lu  Y: %2lu �����˫�� �˳���", crPos.X, crPos.Y);
				SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);
				//cout << "kaishi switch" << endl; //-----------------------------------------
				switch (mouseRec.Event.MouseEvent.dwButtonState)
				{
				case FROM_LEFT_1ST_BUTTON_PRESSED:			// ��� ���A
					FillConsoleOutputCharacter(hOut, 'A', 1, crPos, &res);
					break;		// ���ʹ��printf�������֮ǰ��Ҫ�����ù���λ��

				case RIGHTMOST_BUTTON_PRESSED:				// �Ҽ� ���a
					FillConsoleOutputCharacter(hOut, 'a', 1, crPos, &res);
					break;

				default:
					continue;
				}
			}
		}


		system("pause");
		CloseHandle(hOut);  // �رձ�׼����豸���  
		CloseHandle(hIn);   // �رձ�׼�����豸��� 
		return 0;
	}

}
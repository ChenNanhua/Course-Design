#pragma once
#ifndef _INFO_H
#define _INFO_H
#include<string>
#include"person_info.h"
using namespace std;
class info
{
public:
	info();
	~info();
	friend class tree;
	static string item_all[10];
	void create_info();				//����Ա��������Ϣ
	string find_info(string item);	//�ҵ�Ա����Ϣ���ж�Ӧ��ֵ
	void modify_info(string item, string content);	//�޸�Ա����Ϣ���ж�Ӧ��ֵ
	string save_info();				//��Ա����Ϣת��Ϊ�ַ���
private:	
	//Ա��������Ϣ��Ŀ����
	person_info *head;
};

#endif // !_INFO_H


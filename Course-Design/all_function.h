#pragma once
#ifndef _ALL_FUNCTION_H
#define _ALL_FUNCTION_H
#include<iostream>
#include<string>
using namespace std;
#include"person_info.h"
#include"person_tree.h"

void create_info(person_info *head) {		//����Ա��������Ϣ
	person_info *p;
	p = head;
	string temp_str = "";
	string item_all[9] = {"����","������","��������","�μӹ�������","�Ա�","���","ѧ��","ְҵ","ְ��" };
	for (int i = 0; i < 8; i++)
	{
		cout << "������"<<item_all[i]<<": ";
		cin >> temp_str;
		person_info *temp_per_info = new person_info();
		p->next = temp_per_info;
		temp_per_info->setinfo(item_all[i], temp_str);
		p = p->next;
	}
}

void creat_tree() {

}

#endif // !_ALL_FUNCTION_H

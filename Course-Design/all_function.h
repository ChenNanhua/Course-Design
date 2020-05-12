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
	for (int i = 0; i < 9; i++)
	{
		cout << "������"<<item_all[i]<<": ";
		cin >> temp_str;
		person_info *temp_per_info = new person_info();
		p->next = temp_per_info;
		temp_per_info->setinfo(item_all[i], temp_str);
		p = p->next;
	}
}

void create_tree(person_tree *root_node,person_tree *father) {
	cout << "����1¼�룬����0�˳���";
	int flag;
	cin >> flag;
	person_tree *p;
	if (root_node != NULL)
		p = root_node;
	else
		p = root_node = new person_tree();
	while (flag)
	{
		person_info temp;
		create_info(&temp);
		p->set_info("����", &temp, father);
		cout << "����ͬ����Ա" << endl;
		create_tree(p->nextsibling, p);
		cout << "�����¼���Ա" << endl;
		create_tree(p->child, p);
	}
}

#endif // !_ALL_FUNCTION_H

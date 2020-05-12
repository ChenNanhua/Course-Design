#pragma once
#ifndef _ALL_FUNCTION_H
#define _ALL_FUNCTION_H
#include<iostream>
#include<string>
using namespace std;
#include"person_info.h"
#include"person_tree.h"

void create_info(person_info *head) {		//建立员工个人信息
	person_info *p;
	p = head;
	string temp_str = "";
	string item_all[9] = {"姓名","出生地","出生日期","参加工作日期","性别","身高","学历","职业","职称" };
	for (int i = 0; i < 9; i++)
	{
		cout << "请输入"<<item_all[i]<<": ";
		cin >> temp_str;
		person_info *temp_per_info = new person_info();
		p->next = temp_per_info;
		temp_per_info->setinfo(item_all[i], temp_str);
		p = p->next;
	}
}

void create_tree(person_tree *root_node,person_tree *father) {
	cout << "输入1录入，输入0退出：";
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
		p->set_info("部门", &temp, father);
		cout << "建立同级人员" << endl;
		create_tree(p->nextsibling, p);
		cout << "建立下级人员" << endl;
		create_tree(p->child, p);
	}
}

#endif // !_ALL_FUNCTION_H

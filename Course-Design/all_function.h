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
	for (int i = 0; i < 8; i++)
	{
		cout << "请输入"<<item_all[i]<<": ";
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

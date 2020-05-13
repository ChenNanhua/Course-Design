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
	void create_info();				//建立员工个人信息
	string find_info(string item);	//找到员工信息表中对应的值
	void modify_info(string item, string content);	//修改员工信息表中对应的值
	string save_info();				//把员工信息转换为字符串
private:	
	//员工个人信息项目数组
	person_info *head;
};

#endif // !_INFO_H


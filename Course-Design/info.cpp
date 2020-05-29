#include"info.h"
#include<iostream>
using namespace std;
string info::item_all[10] = { "姓名","出生地","出生日期","参加工作日期","性别","身高","学历","部门","职业","职称" };
info::info()
{
	this->next = NULL;
}
info::~info()
{
	delete next;
}
//建立员工个人信息
void info::create_info() {
	info *p ;
	p = this;
	string temp_str = "";
	for (int i = 0; i < 10; i++)
	{
		cout << "请输入" << item_all[i] << ": ";
		cin >> temp_str;
		info *temp_per_info = new info();
		p->next = temp_per_info;
		temp_per_info->item = item_all[i];
		temp_per_info->content = temp_str;
		p = p->next;
	}
}
//找到员工信息表中对应的值
string info::find_info(string item) {
	info *p = this->next;
	while (p != NULL)
	{
		if (p->item == item)
			return p->content;
		p = p->next;
	}
	return "";
}
//修改员工信息表中对应的值
void info::modify_info(string item,string content) {
	info *p = this->next;
	while (p != NULL)
	{
		if (p->item == item)
			 p->content = content;
		p = p->next;
	}
}
//把员工信息转换为字符串
string info::save_info() {
	info *p = this->next;
	string info_str = "";
	if (p != NULL) {
		for (int i = 0; i < 10; i++)
		{
			info_str += p->content + " ";
			p = p->next;
		}
	}
	return info_str;
}
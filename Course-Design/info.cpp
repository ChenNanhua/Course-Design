#include"info.h"
string info::item_all[10] = { "姓名","出生地","出生日期","参加工作日期","性别","身高","学历","部门","职业","职称" };
info::info()
{
	head = new person_info();
}
info::~info()
{
}
//建立员工个人信息
void info::create_info() {
	person_info *p;
	p = head;
	string temp_str = "";
	for (int i = 0; i < 10; i++)
	{
		cout << "请输入" << item_all[i] << ": ";
		cin >> temp_str;
		person_info *temp_per_info = new person_info();
		p->next = temp_per_info;
		temp_per_info->item = item_all[i];
		temp_per_info->content = temp_str;
		p = p->next;
	}
}
//找到员工信息表中对应的值
string info::find_info(string item) {
	person_info *p = head;
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
	person_info *p = head;
	while (p != NULL)
	{
		if (p->item == item)
			 p->content = content;
		p = p->next;
	}
}
//把员工信息转换为字符串
string info::save_info() {
	person_info *p = head;
	string info_str = "";
	if (p != NULL) {
		for (int i = 0; i < 10; i++)
		{
			p = p->next;
			info_str += p->content + " ";
		}
	}
	return info_str;
}
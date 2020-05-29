#include"info.h"
#include<iostream>
using namespace std;
string info::item_all[10] = { "����","������","��������","�μӹ�������","�Ա�","���","ѧ��","����","ְҵ","ְ��" };
info::info()
{
	this->next = NULL;
}
info::~info()
{
	delete next;
}
//����Ա��������Ϣ
void info::create_info() {
	info *p ;
	p = this;
	string temp_str = "";
	for (int i = 0; i < 10; i++)
	{
		cout << "������" << item_all[i] << ": ";
		cin >> temp_str;
		info *temp_per_info = new info();
		p->next = temp_per_info;
		temp_per_info->item = item_all[i];
		temp_per_info->content = temp_str;
		p = p->next;
	}
}
//�ҵ�Ա����Ϣ���ж�Ӧ��ֵ
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
//�޸�Ա����Ϣ���ж�Ӧ��ֵ
void info::modify_info(string item,string content) {
	info *p = this->next;
	while (p != NULL)
	{
		if (p->item == item)
			 p->content = content;
		p = p->next;
	}
}
//��Ա����Ϣת��Ϊ�ַ���
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
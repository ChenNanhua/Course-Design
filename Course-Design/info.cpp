#include"info.h"
string info::item_all[10] = { "����","������","��������","�μӹ�������","�Ա�","���","ѧ��","����","ְҵ","ְ��" };
info::info()
{
	head = new person_info();
}
info::~info()
{
}
//����Ա��������Ϣ
void info::create_info() {
	person_info *p;
	p = head;
	string temp_str = "";
	for (int i = 0; i < 10; i++)
	{
		cout << "������" << item_all[i] << ": ";
		cin >> temp_str;
		person_info *temp_per_info = new person_info();
		p->next = temp_per_info;
		temp_per_info->item = item_all[i];
		temp_per_info->content = temp_str;
		p = p->next;
	}
}
//�ҵ�Ա����Ϣ���ж�Ӧ��ֵ
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
//�޸�Ա����Ϣ���ж�Ӧ��ֵ
void info::modify_info(string item,string content) {
	person_info *p = head;
	while (p != NULL)
	{
		if (p->item == item)
			 p->content = content;
		p = p->next;
	}
}
//��Ա����Ϣת��Ϊ�ַ���
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
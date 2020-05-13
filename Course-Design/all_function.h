#pragma once
#ifndef _ALL_FUNCTION_H
#define _ALL_FUNCTION_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
#include"person_info.h"
#include"person_tree.h"


//����������
void create_tree(person_tree **root, person_tree *father) {	
	cout << "����1¼�룬����0�˳���";
	int flag;
	cin >> flag;
	if (flag)
	{
		person_tree *p;
		if (*root != NULL)
			p = *root;
		else
			p = *root = new person_tree();
		person_info *temp = new person_info();
		create_info(temp);
		p->set_tree(temp, father);
		cout << "����ͬ����Ա" << endl;
		create_tree(&p->nextsibling, p);
		cout << "�����¼���Ա" << endl;
		create_tree(&p->child, p);
	}
}
//�������ṹ���ļ���	ǰ�����
void save_tree_child(person_tree *root, ofstream &out) {
	if (root != NULL)
	{
		out << root->getid() << " " << save_info(root->head) << endl;
		save_tree_child(root->nextsibling,out);
		save_tree_child(root->child,out);
	}
	else
	{
		out << 0 << endl;
	}
}
void save_tree(person_tree *root) {
	ofstream out("file.txt");
	save_tree_child(root, out);
	out.close();
}
//���ļ����ݶ�ȡ�������� ǰ��ԭ
void load_tree_child(person_tree **root, person_tree*father,ifstream &in) {	
	string one_line;
	getline(in, one_line);				//�ȶ�ȡ�ļ���һ��
	if (one_line != "0") {
		if ((*root) == NULL)
			(*root) = new person_tree();
		istringstream strin(one_line);	//ת��Ϊ�ַ���������
		int id;							//�ֱ��ȡ��id��Ա����Ϣ
		strin >> id;
		person_info *head = new person_info();
		person_info *p = head;
		string temp_str = "";
		for (int i = 0; i < 10; i++)
		{
			strin >> temp_str;
			person_info *temp_per_info = new person_info();
			p->next = temp_per_info;
			temp_per_info->set_info(item_all[i], temp_str);
			p = p->next;
		}
		(*root)->set_tree(head, NULL);
		(*root)->set_id(id);
		load_tree_child(&(*root)->nextsibling, (*root),in);
		load_tree_child(&(*root)->child, (*root),in);
	}
	else
		return;
}
void load_tree(person_tree **root, person_tree*father) {
	ifstream in("file.txt");
	load_tree_child(&(*root), father, in);
}
//��ӡ��
void print_tree_child(person_tree *root, int depth) {
	if (root != NULL) {
		if (depth ==0)
			cout <<  root->getid() << " " << find_info("����", root->head) << endl;
		else
		{
			string flag = "\t";
			for (int i = 1; i < depth; i++)
				flag += flag;
			cout << flag << root->getid() << " " << find_info("����", root->head) << endl;
		}
	}
	else return;
	print_tree_child(root->child,depth+1);
	print_tree_child(root->nextsibling, depth);
}
void print_tree(person_tree *root) {
	int depth = 0;
	print_tree_child(root, depth);
}
#endif // !_ALL_FUNCTION_H

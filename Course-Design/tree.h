#pragma once
#ifndef _TREE_H
#define _TREE_H
#include"person_tree.h"
#include"info.h"
class tree
{
public:
	tree();
	~tree();
	person_tree * find_node(person_tree * root, int id);	//�ҵ�id��Ӧ�Ľڵ�
	void create_tree();//����������
	void create_tree_child(person_tree **root, person_tree *father);
	//�������ṹ���ļ���	ǰ�����
	void save_tree();
	void save_tree_child(person_tree *root, ofstream &out); 
	//���ļ����ݶ�ȡ�������� ǰ��ԭ
	void load_tree();
	void load_tree_child(person_tree **root, person_tree*father, ifstream &in);
	//��ӡ��
	void print_tree_child(person_tree *root, int depth);
	void print_tree();
	//�޸�Ա����Ϣ
	void modify_info(string item,string content);
	//ɾ��Ա��
	void delete_node_child(person_tree *root,int id); 
	void delete_node(int id);
	//����Ա��
	void insert_node(int id, int child_or_not);
	//��ѯԱ��
	void search_child(person_tree * root, string content);
	void search(string content);
private:
	person_tree *root;
};


#endif // !_TREE_H

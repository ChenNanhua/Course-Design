#pragma once
#ifndef _TREE_H
#define _TREE_H
#include"person_tree.h"
#include"info.h"
#include"node_file.h"
class tree
{
public:
	tree();
	~tree();
	void find_node(person_tree * root, int id, person_tree ** out);	//�ҵ�id��Ӧ�Ľڵ�
	void create_tree();												//����������
	void create_tree_child(person_tree **root, person_tree *father);
	void save_tree();												//�������ṹ���ļ���	ǰ�����
	void save_tree_child(person_tree *root, ofstream &out); 
	void load_tree_1();												//���ļ����ݶ�ȡ�������� ǰ��ԭ(�ݹ鷽��)
	void load_tree_child_1(person_tree **root, person_tree*father, ifstream &in);
	void load_tree();												//���ļ����ݶ�ȡ�������� ǰ��ԭ(�ǵݹ�)
	void print_tree_child(person_tree *root, int depth);
	void print_tree();												//��ӡ��
	void print_person_child(person_tree *root, int id);
	void print_person(int id);										//��ӡԱ����Ϣ
	void modify_info_child(person_tree *root, int id, string item, string content);
	void modify_info(int id,string item,string content);			//�޸�Ա����Ϣ
	void delete_node_child(person_tree *root,int id); 
	void delete_node(int id);										//ɾ��Ա��
	void insert_node(int id, int child_or_not);						//����Ա��
	void search_child(person_tree * root, string content);
	void search(string content);									//��ѯԱ��
	void get_statistics(person_tree *root, string item, int &sum, int &count);	//��ѯͳ��
	void print_statistics(string item);										
private:
	person_tree *root;
};


#endif // !_TREE_H

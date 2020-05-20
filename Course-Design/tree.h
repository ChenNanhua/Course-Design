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
	void find_node(person_tree * root, int id, person_tree ** out);	//找到id对应的节点
	void create_tree();												//建立二叉树
	void create_tree_child(person_tree **root, person_tree *father);
	void save_tree();												//保存树结构到文件中	前序输出
	void save_tree_child(person_tree *root, ofstream &out); 
	void load_tree_1();												//把文件内容读取到二叉树 前序复原(递归方法)
	void load_tree_child_1(person_tree **root, person_tree*father, ifstream &in);
	void load_tree();												//把文件内容读取到二叉树 前序复原(非递归)
	void print_tree_child(person_tree *root, int depth);
	void print_tree();												//打印树
	void print_person_child(person_tree *root, int id);
	void print_person(int id);										//打印员工信息
	void modify_info_child(person_tree *root, int id, string item, string content);
	void modify_info(int id,string item,string content);			//修改员工信息
	void delete_node_child(person_tree *root,int id); 
	void delete_node(int id);										//删除员工
	void insert_node(int id, int child_or_not);						//加入员工
	void search_child(person_tree * root, string content);
	void search(string content);									//查询员工
	void get_statistics(person_tree *root, string item, int &sum, int &count);	//查询统计
	void print_statistics(string item);										
private:
	person_tree *root;
};


#endif // !_TREE_H

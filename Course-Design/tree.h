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
	person_tree * find_node(person_tree * root, int id);	//找到id对应的节点
	void create_tree();//建立二叉树
	void create_tree_child(person_tree **root, person_tree *father);
	//保存树结构到文件中	前序输出
	void save_tree();
	void save_tree_child(person_tree *root, ofstream &out); 
	//把文件内容读取到二叉树 前序复原
	void load_tree();
	void load_tree_child(person_tree **root, person_tree*father, ifstream &in);
	//打印树
	void print_tree_child(person_tree *root, int depth);
	void print_tree();
	//修改员工信息
	void modify_info(string item,string content);
	//删除员工
	void delete_node_child(person_tree *root,int id); 
	void delete_node(int id);
	//加入员工
	void insert_node(int id, int child_or_not);
	//查询员工
	void search_child(person_tree * root, string content);
	void search(string content);
private:
	person_tree *root;
};


#endif // !_TREE_H

#pragma once
#ifndef _PERSON_TREE_H
#define _PERSON_TREE_H
#include"person_info.h"
extern int only_id;				//防止id重复
class person_tree
{
public:
	person_tree(string department ,person_info *head);
	~person_tree();
	string getdepartment();
	void setdeparment(string department);
	int getid();
	person_info *head;			//员工个人信息线性表
	person_tree *child;			//孩子节点
	person_tree *nextsibling;	//兄弟节点
	person_tree *father;		//父节点
private:
	int id;						//员工唯一标识符
	string department;			

};

#endif // _PERSON_TREE_H

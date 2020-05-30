#pragma once
#ifndef _PERSON_TREE_H
#define _PERSON_TREE_H
#include"info.h"
extern int only_id;				//防止id重复
class person_tree
{
public:
	person_tree();
	person_tree(info *head,int id, person_tree *father);
	~person_tree();
	friend class tree;
	void set_tree( info *head, person_tree *father);	//设置员工信息
private:
	int id;						//员工唯一标识符
	info *head;					//员工个人信息线性表
	person_tree *child;			//孩子节点
	person_tree *nextsibling;	//兄弟节点
	person_tree *father;		//父节点

};

#endif // _PERSON_TREE_H

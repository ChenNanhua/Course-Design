#pragma once
#ifndef _PERSON_TREE_H
#define _PERSON_TREE_H
#include"info.h"
extern int only_id;				//��ֹid�ظ�
class person_tree
{
public:
	person_tree();
	person_tree(info *head,int id, person_tree *father);
	~person_tree();
	friend class tree;
	void set_tree( info *head, person_tree *father);	//����Ա����Ϣ
private:
	int id;						//Ա��Ψһ��ʶ��
	info *head;					//Ա��������Ϣ���Ա�
	person_tree *child;			//���ӽڵ�
	person_tree *nextsibling;	//�ֵܽڵ�
	person_tree *father;		//���ڵ�

};

#endif // _PERSON_TREE_H

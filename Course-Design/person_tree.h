#pragma once
#ifndef _PERSON_TREE_H
#define _PERSON_TREE_H
#include"person_info.h"
#include"tree.h"
extern int only_id;				//��ֹid�ظ�
class person_tree
{
public:
	person_tree();
	~person_tree();
	void set_tree( person_info *head, person_tree *father);
	int getid();
	void set_id(int id);
	person_info *head;			//Ա��������Ϣ���Ա�
	person_tree *child;			//���ӽڵ�
	person_tree *nextsibling;	//�ֵܽڵ�
	person_tree *father;		//���ڵ�
private:
	int id;						//Ա��Ψһ��ʶ��

};

#endif // _PERSON_TREE_H

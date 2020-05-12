#pragma once
#ifndef _PERSON_TREE_H
#define _PERSON_TREE_H
#include"person_info.h"
extern int only_id;				//��ֹid�ظ�
class person_tree
{
public:
	person_tree();
	~person_tree();
	string getdepartment();
	void set_info(string department, person_info *head, person_tree *father);
	int getid();
	person_info *head;			//Ա��������Ϣ���Ա�
	person_tree *child;			//���ӽڵ�
	person_tree *nextsibling;	//�ֵܽڵ�
	person_tree *father;		//���ڵ�
private:
	int id;						//Ա��Ψһ��ʶ��
	string department;			

};

#endif // _PERSON_TREE_H

#pragma once
#ifndef _PERSON_TREE_H
#define _PERSON_TREE_H
#include"person_info.h"
class person_tree
{
public:
	person_tree(int id, string department ,person_info *head);
	~person_tree();
	string getdepartment();
	void setdeparment(string department);
	int getid();
	person_info *head;
	person_tree *child;
	person_tree *nextsibling;
	person_tree *father;
private:
	int id;
	string department;

};

#endif // _PERSON_TREE_H

#pragma once
#ifndef _PERSON_TREE_H
#define _PERSON_TREE_H
#include"person_info.h"
class person_tree
{
public:
	person_tree();
	~person_tree();

private:
	int id;
	person_info *head;
	string child;
	string nextsibling;
	person_tree *child;
	person_tree *nextsibling;
	person_tree *father;

};

#endif // _PERSON_TREE_H

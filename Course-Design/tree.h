#pragma once
#ifndef _TREE_H
#define _TREE_H
#include"person_tree.h"
class tree
{
public:
	tree();
	~tree();

private:
	person_tree *root;
};

tree::tree()
{
}

tree::~tree()
{
}
#endif // !_TREE_H

#pragma once
#ifndef _NODE_FILE_H
#define _NODE_FILE_H
#include"person_tree.h"
class node_file			//�ǵݹ鷽ʽ����������ʱ�õ������ݽṹ
{
public:
	node_file(person_tree *node,int num=0);
	~node_file();
	friend class tree;
private:
	person_tree *node;
	int num;
};

#endif // !_NODE_FILE_H


#include<iostream>
using namespace std;
#include"person_tree.h"

int only_id = 1;
person_tree::person_tree( )
{
	this->id = only_id++;
	this->head = new info();
}

person_tree::~person_tree()
{
	delete this->child;
	delete this->nextsibling;
	delete this->father;
}


void person_tree::set_tree( info *head,person_tree *father)
{
	this->head = head;
	this->child = NULL;
	this->nextsibling = NULL;
	this->father = father;
}

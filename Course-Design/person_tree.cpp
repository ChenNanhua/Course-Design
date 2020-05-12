#include<iostream>
using namespace std;
#include"person_tree.h"

int only_id = 0;
person_tree::person_tree( )
{
	this->id = only_id++;
	this->department = department;
	this->head = head;
	this->child = NULL;
	this->nextsibling = NULL;
	this->father = NULL;
}

person_tree::~person_tree()
{
	delete this->child;
	delete this->nextsibling;
	delete this->father;
}

string person_tree::getdepartment()
{
	return this->department;
}

void person_tree::set_info(string department, person_info *head,person_tree *father)
{
	this->id = only_id++;
	this->department = department;
	this->head = head;
	this->child = NULL;
	this->nextsibling = NULL;
	this->father = NULL;
}

int person_tree::getid()
{
	return this->id;
}

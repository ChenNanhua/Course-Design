#pragma once
#ifndef _PERSON_INFO_H
#define _PERSON_INFO_H
#include<iostream>
#include<string>
using namespace std;
class person_info
{
public:
	person_info();
	~person_info();
	friend class info;
	friend class tree;
private:
	string item;
	string content;
	person_info *next;
};



#endif // !_PERSON_INFO_H
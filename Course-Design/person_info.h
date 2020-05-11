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
	void setinfo(string item, string content);
	string getitem();
	string getcontent();
	void setcontent(string newcontent);
	person_info *next;
private:
	string item;
	string content;
};



#endif // !_PERSON_INFO_H
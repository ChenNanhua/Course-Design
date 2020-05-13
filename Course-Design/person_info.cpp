#include<iostream>
using namespace std;
#include"person_info.h"

person_info::person_info() {
	this->next = NULL;
}

person_info::~person_info() {
	delete next;

}

void person_info::set_info(string item, string content)
{
	this->item = item;
	this->content = content;
}

string person_info::getitem()
{
	return this->item;
}

string person_info::getcontent()
{
	return this->content;
}

void person_info::setcontent(string newcontent)
{
	this->content = newcontent;
}

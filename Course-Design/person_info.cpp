#include<iostream>
using namespace std;
#include"person_info.h"

person_info::person_info(string item, string content) {
	this->item = item;
	this->content = content;
}

person_info::~person_info() {
	delete next;

}

string person_info::getitem()
{
	return this->item;
}

string person_info::getcontent()
{
	return this->content;
}

string person_info::setcontent(string newcontent)
{
	return this->content = newcontent;
}

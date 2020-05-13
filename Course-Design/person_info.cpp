#include<iostream>
using namespace std;
#include"person_info.h"

person_info::person_info() {
	this->next = NULL;
}

person_info::~person_info() {
	delete next;

}

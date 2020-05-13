#include <iostream>
using namespace std;
#include"info.h"
#include"tree.h"
int main() {
	tree *a = new tree();
	a->create_tree();
	a->save_tree();
	a->load_tree();
	a->print_tree();
	return 0;
}
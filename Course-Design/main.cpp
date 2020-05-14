#include <iostream>
using namespace std;
#include"info.h"
#include"tree.h"
int main() {
	tree *a = new tree();
	a->load_tree();
	a->print_tree();
	a->modify_info(6, "Éí¸ß", "180");
	a->print_person(6);
	a->delete_node(6);
	a->print_tree();
	a->insert_node(5, 0);
	a->print_tree();
	return 0;
}
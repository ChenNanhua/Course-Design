#include <iostream>
using namespace std;
#include"person_info.h"
#include"person_tree.h"
#include"all_function.h"
int main() {
	person_tree *a = new person_tree();
	create_tree(&a,NULL);
	save_tree(a);
	load_tree(&a,NULL);
	print_tree(a);
	return 0;
}
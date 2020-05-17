#include <iostream>
using namespace std;
#include"info.h"
#include"tree.h"
int main() {
	tree *a = new tree();
	a->load_tree();
	a->print_tree();;
	a->print_statistics("Éí¸ß");
	return 0;
}
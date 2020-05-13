#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
#include"tree.h"

tree::tree()
{
	root = new person_tree();
}

tree::~tree()
{
}
//�ҵ�id��Ӧ�Ľڵ�
person_tree * tree::find_node(person_tree * root, int id)
{
	if (root->id == id) return root;
	else
	{
		find_node(root->nextsibling, id);
		find_node(root->child, id);
	}
	return nullptr;
}
//����������
//����������
void tree::create_tree_child(person_tree **root, person_tree *father) {
	cout << "����1¼�룬����0�˳���";
	int flag;
	cin >> flag;
	if (flag)
	{
		person_tree *p;
		if (*root != NULL)
			p = *root;
		else
			p = *root = new person_tree();
		info *temp = new info();
		temp->create_info();
		p->set_tree(temp, father);
		cout << "����ͬ����Ա" << endl;
		create_tree_child(&p->nextsibling, p);
		cout << "�����¼���Ա" << endl;
		create_tree_child(&p->child, p);
	}
}
void tree::create_tree() {
	create_tree_child(&this->root, NULL);
}
//�������ṹ���ļ���	ǰ�����
void tree::save_tree_child(person_tree *root, ofstream &out) {
	if (root != NULL)
	{
		out << root->id << " " << root->head->save_info() << endl;
		save_tree_child(root->nextsibling, out);
		save_tree_child(root->child, out);
	}
	else
	{
		out << 0 << endl;
	}
}
void tree::save_tree() {
	ofstream out("file.txt");
	save_tree_child(this->root, out);
	out.close();
}
//���ļ����ݶ�ȡ�������� ǰ��ԭ
void tree::load_tree_child(person_tree **root, person_tree*father, ifstream &in) {
	string one_line;
	getline(in, one_line);				//�ȶ�ȡ�ļ���һ��
	if (one_line != "0") {
		if ((*root) == NULL)
			(*root) = new person_tree();
		istringstream strin(one_line);	//ת��Ϊ�ַ���������
		int id;							//�ֱ��ȡ��id��Ա����Ϣ
		strin >> id;
		info *head = new info();
		person_info *p = head->head;
		string temp_str = "";
		for (int i = 0; i < 10; i++)
		{
			strin >> temp_str;
			person_info *temp_per_info = new person_info();
			p->next = temp_per_info;
			temp_per_info->item = info::item_all[i];
			temp_per_info->content = temp_str;
			p = p->next;
		}
		(*root)->set_tree(head, NULL);
		(*root)->id = id;
		load_tree_child(&(*root)->nextsibling, (*root), in);
		load_tree_child(&(*root)->child, (*root), in);
	}
	else
		return;
}
void tree::load_tree() {
	ifstream in("file.txt");
	load_tree_child(&this->root, NULL, in);
}
//��ӡ��
void tree::print_tree_child(person_tree *root, int depth) {
	if (root != NULL) {
		if (depth == 0)
			cout << root->id << " " << root->head->find_info("����") << endl;
		else
		{
			string flag = "\t";
			for (int i = 1; i < depth; i++)
				flag += flag;
			cout << flag << root<< " " << root->head->find_info("����") << endl;
		}
	}
	else return;
	print_tree_child(root->child, depth + 1);
	print_tree_child(root->nextsibling, depth);
}
void tree::print_tree() {
	int depth = 0;
	print_tree_child(root, depth);
}
//�޸Ľڵ���Ϣ
void tree::modify_info(string item,string content)
{
	root->head->modify_info(item, content);
}
//ɾ���ڵ�
void tree::delete_node_child(person_tree *root, int id)
{
	if (root->id == id) {
		if (root->father->head->find_info("����") != root->head->find_info("����"))		//�ж���ɾ�����ڵ���ӽڵ㻹���ֵܽڵ�
			root->father->nextsibling = root->nextsibling;			//ֱ��ɾ���ýڵ㼰���ӽڵ�
		else
			root->father->child = root->nextsibling;
	}
	else
	{
		delete_node_child(root->nextsibling, id);
		delete_node_child(root->child,id);
	}
}
void tree::delete_node(int id)
{
	delete_node_child(this->root, id);
}
//����ڵ�
void tree::insert_node(int id, int child_or_not)
{
	person_tree *p = find_node(this->root, id);
	person_tree *new_node = new person_tree();
	new_node->head->create_info();
	if (child_or_not==0)
	{
		new_node->nextsibling = p->nextsibling;
		p->nextsibling = new_node;
	}
	else
	{
		new_node->father = p;
		p->child = new_node;
	}
}
//������Ϣ
void tree::search_child(person_tree *root ,string content)
{
	if (root != NULL) {
		person_info *p = root->head->head;
		while (p != NULL)
		{
			if (p->content == content || p->item == content) {
				cout << root->id << " " << root->head->save_info();
				break;
			}
			p = p->next;
		}
		search_child(root->nextsibling, content);
		search_child(root->child, content);
	}
}
void tree::search(string content)
{
	search_child(this->root, content);
}

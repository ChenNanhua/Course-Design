#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;
#include"tree.h"
//�ڵ�ջ
stack<node_file*> node_stack;
tree::tree()
{
	root = new person_tree();
}
tree::~tree()
{
}
//�ҵ�id��Ӧ�Ľڵ�
void tree::find_node(person_tree * root, int id, person_tree ** out)
{
	if (root == NULL)
		return;
	if (root->id == id) {
		(*out) = root;
	}
	else
	{
		find_node(root->nextsibling, id, out);
		find_node(root->child, id, out);
	}
	return;
}
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
void tree::load_tree_child_1(person_tree **root, person_tree*father, ifstream &in) {
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
		for (int i = 0; i < 10; i++)	//ת����Ա����Ϣ���Ա�
		{
			strin >> temp_str;
			person_info *temp_per_info = new person_info();
			p->next = temp_per_info;
			temp_per_info->item = info::item_all[i];
			temp_per_info->content = temp_str;
			p = p->next;
		}
		(*root)->set_tree(head, father);
		(*root)->id = id;
		load_tree_child_1(&(*root)->nextsibling, (*root), in);
		load_tree_child_1(&(*root)->child, (*root), in);
	}
	else
		return;
}
void tree::load_tree_1() {
	ifstream in("file.txt");
	load_tree_child_1(&this->root, NULL, in);
}
void tree::load_tree()
{
	ifstream in("file.txt");
	node_stack.push(new node_file(this->root, 0));
	while (1)
	{
		if (!node_stack.empty()) {
			string one_line;
			getline(in, one_line);				//�ȶ�ȡ�ļ���һ��
			node_file *n_f = node_stack.top();
			if (one_line != "0") {				//����������
				istringstream strin(one_line);	//ת��Ϊ�ַ���������
				int id;							//�ֱ��ȡ��id��Ա����Ϣ
				strin >> id;
				info *head = new info();
				person_info *p = head->head;
				string temp_str = "";
				for (int i = 0; i < 10; i++)	//ת����Ա����Ϣ���Ա�
				{
					strin >> temp_str;
					person_info *temp_per_info = new person_info();
					p->next = temp_per_info;
					temp_per_info->item = info::item_all[i];
					temp_per_info->content = temp_str;
					p = p->next;
				}
				if (n_f->num == 0) {
					n_f->num = 1;
					n_f->node->head = head;
				}
				else {
					if (n_f->num == 1) {
						n_f->num = 2;
						n_f->node->nextsibling = new person_tree(head, n_f->node);
						node_stack.push(new node_file(n_f->node->nextsibling, 1));
					}
					else {
						if (n_f->num == 2) {
							n_f->num = 3;
							n_f->node->child = new person_tree(head, n_f->node);
							node_stack.pop();
							node_stack.push(new node_file(n_f->node->child, 1));
						}
					}
				}
			}
			else
			{
				if (n_f->num == 0) {
					n_f->num = 1;
					n_f->node = NULL;
					return;
				}
				else {
					if (n_f->num == 1) {
						n_f->num = 2;
						n_f->node->nextsibling = NULL;
					}
					else {
						if (n_f->num == 2) {
							n_f->num = 3;
							n_f->node->child = NULL;
							node_stack.pop();
						}
					}
				}
			}
		}
		if (in.peek() == EOF)
			break;
		else
			if (node_stack.empty())
			{
				string temp;
				getline(in, temp);
			}
	}
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
			cout << flag << root->id << " " << root->head->find_info("����") << endl;
		}
	}
	else return;
	print_tree_child(root->child, depth + 1);
	print_tree_child(root->nextsibling, depth);
}
void tree::print_tree() {
	int depth = 0;
	print_tree_child(this->root, depth);
}
//��ӡԱ����Ϣ
void tree::print_person_child(person_tree * root, int id)
{
	if (root == NULL)
		return;
	if (root->id == id) {
		cout << id << " " << root->head->save_info() << endl;
	}
	else
	{
		print_person_child(root->nextsibling, id);
		print_person_child(root->child, id);
	}
}
void tree::print_person(int id)
{
	print_person_child(this->root, id);
}
//�޸Ľڵ���Ϣ
void tree::modify_info(int id, string item, string content)
{
	modify_info_child(this->root, id, item, content);
}
void tree::modify_info_child(person_tree * root, int id, string item, string content)
{
	if (root == NULL)
		return;
	if (root->id == id)
		root->head->modify_info(item, content);
	else
	{
		modify_info_child(root->nextsibling, id, item, content);
		modify_info_child(root->child, id, item, content);
	}
}
//ɾ���ڵ�
void tree::delete_node_child(person_tree *root, int id)
{
	if (root == NULL)
		return;
	if (root->id == id) {
		if (root->father == NULL) {
			this->root = NULL;
			return;
		}
		if (root->father->head->find_info("����") != root->head->find_info("����"))		//�ж���ɾ�����ڵ���ӽڵ㻹���ֵܽڵ�
			root->father->nextsibling = root->nextsibling;			//ֱ��ɾ���ýڵ㼰���ӽڵ�
		else
			root->father->child = root->nextsibling;
	}
	else
	{
		delete_node_child(root->nextsibling, id);
		delete_node_child(root->child, id);
	}
}
void tree::delete_node(int id)
{
	delete_node_child(this->root, id);
}
//����ڵ�
void tree::insert_node(int id, int child_or_not)
{
	person_tree *p = new person_tree();
	find_node(this->root, id, &p);
	person_tree *new_node = new person_tree();
	new_node->head->create_info();
	if (child_or_not == 0)
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
void tree::search_child(person_tree *root, string content)
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
//ͳ����Ϣ
void tree::get_statistics(person_tree *root, string item, int &sum, int &count)
{
	if (root == NULL)
		return;
	string temp_str = root->head->find_info(item);
	if (temp_str != "") {
		sum += atoi(temp_str.c_str());
		count++;
	}
	get_statistics(root->nextsibling, item, sum, count);
	get_statistics(root->child, item, sum, count);
}

void tree::print_statistics(string item)
{
	int sum = 0, count = 0;
	get_statistics(this->root, item, sum, count);
	cout << "ƽ��" << item << ": " << sum / count << endl;
}

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;
#include"tree.h"
//节点栈
stack<node_file*> node_stack;
tree::tree()
{
	root = new person_tree();
}
tree::~tree()
{
}
//找到id对应的节点
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
//建立二叉树
void tree::create_tree_child(person_tree **root, person_tree *father) {
	cout << "输入1录入，输入0退出：";
	int flag;
	cin >> flag;
	if (flag)
	{
		only_id = 0;
		person_tree *p;
		if (*root != NULL)
			p = *root;
		else
			p = *root = new person_tree();
		info *temp = new info();
		temp->create_info();
		p->set_tree(temp, father);
		cout << "建立同级人员" << endl;
		create_tree_child(&p->nextsibling, p);
		cout << "建立下级人员" << endl;
		create_tree_child(&p->child, p);
	}
}
void tree::create_tree() {
	create_tree_child(&this->root, NULL);
}
//保存树结构到文件中	前序输出
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
//把文件内容读取到二叉树 前序复原
void tree::load_tree_child_1(person_tree **root, person_tree*father, ifstream &in) {
	string one_line;
	getline(in, one_line);				//先读取文件的一行
	if (one_line != "0") {
		if ((*root) == NULL)
			(*root) = new person_tree();
		istringstream strin(one_line);	//转换为字符串输入流
		int id;							//分别读取出id，员工信息
		strin >> id;
		info *head = new info();
		info *p = head->next;
		string temp_str = "";
		for (int i = 0; i < 10; i++)	//转换出员工信息线性表
		{
			strin >> temp_str;
			info *temp_per_info = new info();
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
			getline(in, one_line);				//先读取文件的一行
			node_file *n_f = node_stack.top();
			if (one_line != "0") {				//建立二叉树
				istringstream strin(one_line);	//转换为字符串输入流
				int id;							//分别读取出id，员工信息
				strin >> id;
				info *head = new info();
				info *p = head;
				string temp_str = "";
				for (int i = 0; i < 10; i++)	//转换出员工信息线性表
				{
					strin >> temp_str;
					info *temp_per_info = new info();
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
	cout << "装载完成" << endl;
}
//打印树
void tree::print_tree_child(person_tree *root, int depth, string item) {
	if (root != NULL) {
		if (item == "")
			item = "姓名";
		if (depth == 0)
			cout << root->id << " " << root->head->find_info(item) <<"-"<< root->head->find_info("职称") << endl;
		else
		{
			string flag = "++++++++";
			for (int i = 1; i < depth; i++)
				flag += flag;
			cout << flag << root->id << " " << root->head->find_info(item)<<"-"<< root->head->find_info("职称") << endl;
		}
	}
	else return;
	print_tree_child(root->child, depth + 1, item);
	print_tree_child(root->nextsibling, depth, item);
}
void tree::print_tree() {
	int depth = 0;
	print_tree_child(this->root, depth);
}
//打印员工信息
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
//修改节点信息
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
//删除节点
void tree::delete_node_child(person_tree *root, int id)
{
	if (root == NULL)
		return;
	if (root->id == id) {
		if (root->father == NULL) {
			this->root = NULL;
			return;
		}
		if (root->father->head->find_info("部门") != root->head->find_info("部门"))		//判断是删除父节点的子节点还是兄弟节点
			root->father->nextsibling = root->nextsibling;			//直接删除该节点及其子节点
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
//插入节点
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
//搜索信息
void tree::search_child(person_tree *root, string content)
{
	if (root != NULL) {
		info *p = root->head->next;
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
//统计信息
void tree::get_statistics(person_tree *root, string item, int &sum, int &count, int &max, int &min)
{
	if (root == NULL)
		return;
	string xueli[] = { "小学","初中","中专","大专","本科","硕士","博士","博士后", };
	string temp_str = root->head->find_info(item);
	if (item == "身高") {
		if (temp_str != "") {
			sum += atoi(temp_str.c_str());
			count++;
		}
	}
	if (item == "出生日期") {
		if (temp_str != "") {
			sum += (2020 - atoi((temp_str.substr(0, 4)).c_str()));
			count++;
		}
	}
	if (item == "学历") {
		if (temp_str != "") {
			for (int i = 0; i < 8; i++) {
				if (temp_str == xueli[i]) {
					if (i > max)
						max = i;
					if (i < min)
						min = i;
					sum += i;
					count++;
					continue;
				}
			}
		}
	}
	if (item == "性别")
	{
		if (temp_str != "") {
			if (temp_str == "男") {
				sum += 1;
			}
			count++;
		}
	}
	get_statistics(root->nextsibling, item, sum, count, max, min);
	get_statistics(root->child, item, sum, count, max, min);
	return;
}

void tree::print_statistics(string item)
{
	if (item == "年龄")
		item = "出生日期";
	int sum = 0, count = 0, max = 0, min = 7;
	get_statistics(this->root, item, sum, count, max, min);
	if (item == "身高") {
		cout << "平均" << item << ": " << sum / count << endl;
		return;
	}
	if (item == "性别") {
		cout << "男性占比: " << float(sum) / float(count) << endl;
		return;
	}
	if (item == "出生日期") {
		cout << "平均" << "年龄" << ": " << sum / count << endl;
		return;
	}
	if (item == "学历") {
		string xueli[] = { "小学","初中","中专","大专","本科","硕士","博士","博士后", };
		cout << "平均" << item << ": " << xueli[sum / count] << endl;
		cout << "最高学历: " << xueli[max] << "\t最低学历: " << xueli[min] << endl;
		return;
	}
	if (item == "企业")
	{
		print_tree_child(this->root, 0, "部门");
		return;
	}
	cout << "条目错误,重新输入" << endl;
}

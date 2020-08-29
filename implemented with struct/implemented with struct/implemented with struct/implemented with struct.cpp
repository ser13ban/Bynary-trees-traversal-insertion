#include <iostream>
#include <queue>
using namespace std;
struct node {
	int data;
	struct node* st, * dr;
	node(int data) {
		this->data = data;
		st = dr = nullptr;
	}
};

void insert(node* temp, int data) {
	queue <node*> p;
	//initializing the queue with the root
	p.push(temp);

	while (!p.empty()) {
		node* temp = p.front();
		p.pop();

		if (!temp->st) {
			temp -> st = new node(data);
			break;
		}	else
				p.push(temp->st);

		if (!temp->dr)
		{
			temp->dr = new node(data);
			break;
		}	else
				p.push(temp->dr);
	}
}

void inOrder(struct node* node) {
	//first left child, then root, then right child ( lRd )
	if (node == nullptr)
		return;
	inOrder(node->st);
	cout << node->data  << " ";
	inOrder(node->dr);
}
void preOrder(struct node* node) {
	//first the root, then the left child , then the right child;
	if (node == nullptr)
		return;
	cout << node->data << " ";
	preOrder(node->st);
	preOrder(node->dr);
}
void postOrder(struct node* node) {
	//left child, right child, root;
	if (node == nullptr)
		return;
	postOrder(node->st);
	postOrder(node->dr);
	cout << node->data << " ";

}
int main() {
	struct node* root = new node(1);
	//root->st = new node(2);
	//root->dr = new node(3);
	//root->st->st = new node(4);
	//root->st->dr = new node(8);
	for (int i = 2; i <= 10; ++i) {
		insert(root, i);
	}
	cout << "Inorder:";
	inOrder(root);
	cout << "\nPreorder: ";
	preOrder(root);
	cout << "\nPostorder: ";
	postOrder(root);
}

#include <iostream>
#include <queue>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		left = right = nullptr;
	}
};

class btree
{
public:
	btree();
	~btree();
	void insert(int key);
	void inOrder();
	void postOrder();
	void preOrder();
private:
	void insert( node* leaf,int key);
	void inOrder(node* leaf);
	void postOrder(node* leaf);
	void preOrder(node* leaf);
	void destroy_tree(node* leaf);
	node* root;
};

btree::btree()
{
	root = nullptr;

}

btree::~btree()
{
	destroy_tree(root);

}
void btree::destroy_tree(node* leaf) {
	root = nullptr;
	
	if (!leaf) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
	
}
void btree::insert(node* leaf, int key) {
	queue <node*> q;
	q.push(leaf);

	while (!q.empty()) {
		node* leaf = q.front();
		q.pop();

		if (leaf->left==NULL) {
			leaf->left = new node(key);
			
			break;
		}
		else q.push(leaf->right);
		if (leaf->right==NULL) {
			leaf->right = new node(key);
			break;
		}
		else q.push(leaf->right);
	}
}
void btree::insert(int key) {
	if (root==nullptr) {
		root = new node(key);
		
	}
	else
	{
		insert(root, key);
	}
}

void btree::inOrder() {
	cout << "In order: ";
	inOrder(root);
	cout << '\n';
}
void btree::inOrder(node* leaf) {
	//first left child, then the root, then the right child;
	if (leaf == nullptr)
		return;

	inOrder(leaf->left);
	cout << leaf->data << " ";
	inOrder(leaf -> right);
}

void btree::postOrder() {
	cout << "Post order: ";
	inOrder(root);
	cout << '\n';
}
void btree::postOrder(node* leaf) {
	//left child, right child, root;
	if (leaf == nullptr)
		return;

	postOrder(leaf->left);
	postOrder(leaf->right);
	cout << leaf->data << " ";
}

void btree::preOrder() {
	cout << "Pre order: ";
	inOrder(root);
	cout << '\n';
}
void btree::preOrder(node* leaf) {
	//first the root, then the left child , then the right child;
	if (leaf == nullptr)
		return;
	cout << leaf->data << " ";
	preOrder(leaf->left);
	preOrder(leaf->right);
}


int main() {
	btree *tree = new btree();
	for (int i = 1; i <= 10; ++i) {
		tree->insert(i);
	}
	tree->inOrder();
	tree->postOrder();
	tree->preOrder();

	delete tree;
}
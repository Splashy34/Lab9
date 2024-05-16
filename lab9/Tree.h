#pragma once
#include <iostream>
using namespace std;

class Tree
{
private:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
		Node(int data) : data(data), left(nullptr), right(nullptr) {};
	};
	int size;
	Node* root;
	void clearnode(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		clearnode(node->left);
		clearnode(node->right);
		delete node;
	}

	Node* deleteByMerging(Node*& node) {
		Node* tmp = node;
		if (node != nullptr) {
			if (!node->right) node = node->left;
			else if (node->left == nullptr) node = node->right;
			else {
				tmp = node->left;
				while (tmp->right != nullptr) tmp = tmp->right;
				tmp->right = node->right;
				tmp = node;
				node = node->left;
			}
			delete tmp;
			size--;
			return node;
		}
	}
	void fillArrayHelper(Node *node, int* array, int& index)
	{
		if (node == nullptr)
		{
			return;
		}
		fillArrayHelper(node->left, array, index);
		array[index++] = node->data;
		fillArrayHelper(node->right, array, index);
	}
public:
	Tree();
	~Tree();
	void add(int data);
	void remove(int data);
	bool contains(int data);
	int count();
	void clear();
	void fillArray(int* array, int& index);
};
Tree::Tree()
{
	size = 0;
	root = nullptr;
}

Tree::~Tree()
{
	clear();
}

void Tree::add(int data)
{
	if (contains(data))
	{
		return;
	}
	Node* newnode = new Node(data);
	if (root == nullptr)
	{
		root = newnode;
	}
	else
	{
		Node* current = root;
		while (true)
		{
			if (data < current->data)
			{
				if (current->left == nullptr)
				{
					current->left = newnode;
					break;
				}
				current = current->left;
			}
			else
			{
				if (current->right == nullptr)
				{
					current->right = newnode;
					break;
				}
				current = current->right;
			}
		}
	}
	size++;
}

void Tree::remove(int data) {
	Node* node = root, * prev = 0;
	while (node != nullptr) {
		if (node->data == data)
			break;
		prev = node;
		if (data < node->data)
			node = node->left;
		else node = node->right;
	}
	if (node != nullptr && node->data == data) {
		if (node == root)
			root = deleteByMerging(root);
		else if (prev->left == node)
			prev->left = deleteByMerging(prev->left);
		else
			prev->right = deleteByMerging(prev->right);
	}
}

bool Tree::contains(int data)
{
	Node* current = root;
	while (current != nullptr)
	{
		if (current->data == data)
		{
			return true;
		}
		if (data < current->data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return false;
}

int Tree::count()
{
	return size;
}

void Tree::clear()
{
	clearnode(root);
	root = nullptr;
	size = 0;
}

void Tree::fillArray(int*array, int&index)
{
	fillArrayHelper(root, array, index);
}


#pragma once
#include <iostream>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

void removeNode(node*& root, const int& digit) {
	if (!root) return;
	if (digit <= root->data) {
		removeNode(root->left, digit);
	}
	else if (digit > root->data) {
		removeNode(root->right, digit);
	}
	else
	{
		if (root->left && root->right) {
			node* tmp = max(root->left);
			root->data = tmp->data;
			removeNode(tmp, digit);
		}
		else {
			if (root->left) {
				node* tmp = root;
				root = root->left;
				delete tmp;
			}
			else {
				node* tmp = root;
				root = root->right;
				delete tmp;
			}
		}
	}
}
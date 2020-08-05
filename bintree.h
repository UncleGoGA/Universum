#ifndef _CREATE_SYSTEM_H
#define _CREATE_SYSTEM_H

#include <iostream>


struct tree {
	std::string value;
	tree* left, * right;
};

bool NilTree(tree* root)
{
	return (root == NULL ? true : false);
}

void Insertvalue(tree*& root, std::string value) {
	if (root == NULL) {
		tree* new_root = new tree;
		new_root->value = value;
		new_root->left = new_root->right = NULL;
		root = new_root;
	}
	else {
		tree* cur = root, * previous = NULL;
		while (cur != NULL) {
			previous = cur;
			if (value > cur->value) {
				cur = cur->right;
			}
			else{
				cur = cur->left;
			}
		}
		tree* new_root = new tree;
		new_root->value = value;
		new_root->left = new_root->right = NULL;
		//if (value > cur->value) {
		//	cur->right = new_root;
		//}
		//
		if (value > previous->value) {
			previous->right = new_root;
		}
		else {
			previous->left = new_root;
		}
	}
}

void findtree(tree*& root, std::string value, tree*& cur, tree*& prev) { //by the cur we took back pointer on interested leaf
	cur = root;
	while (cur != NULL) {
		if (cur->value == value) {
			break;
		}
		prev = cur;
		value > cur->value ? cur = cur->right : cur = cur->left;
	}

	if (cur == NULL) {
		prev = NULL;
	}
}

void postOrderTravers(tree* root, size_t& count) {
	if (root != NULL) {
		count++;
		postOrderTravers(root->left, count);
		postOrderTravers(root->right, count);
	}
}

void deltree(tree*& root, std::string value) {
	tree* cur, * prev = NULL;
	findtree(root, value, cur, prev);
	if (cur != NULL) {
		if (cur == root) {
			if (cur->left == NULL && cur->right == NULL) {
				cur = NULL;
				std::cout << "currently deleted" << std::endl;
			}
			if (cur->left != NULL && cur->right == NULL) {
				cur = cur->left;
				std::cout << "currently deleted" << std::endl;
			}
			if (cur->left == NULL && cur->right != NULL) {
				cur = cur->right;
				std::cout << "currently deleted" << std::endl;
			}
			if (cur->left != NULL && cur->right != NULL) {
				tree* new_cur = cur, * new_prev = new_cur->right;
				while (new_prev->left != NULL) {
					new_cur = new_prev;
					new_prev = new_prev->left;
				}
				cur->value = new_cur->value;
				new_prev->left = NULL;
				std::cout << "currently deleted" << std::endl;
			}
		}
		else {
			if (cur->left == NULL && cur->right == NULL) {
				prev->left == cur ? prev->left = NULL : prev->right = NULL;
				std::cout << "currently deleted" << std::endl;
			}
			if (cur->left != NULL && cur->right == NULL) {
				prev->left = cur->left;
				std::cout << "currently deleted" << std::endl;
			}
			if (cur->left == NULL && cur->right != NULL) {
				prev->right = cur->right;
				std::cout << "currently deleted" << std::endl;
			}
			if (cur->left != NULL && cur->right != NULL) {
				tree* new_cur = cur, * new_prev = new_cur->right;
				while (new_prev->left != NULL) {
					new_cur = new_prev;
					new_prev = new_prev->left;
				}
				cur->value = new_cur->value;
				new_prev->left = NULL;
				std::cout << "currently deleted" << std::endl;
			}
		}
	}
	else {
		std::cout << "cant delete" << std::endl;
	}
}

void del_subtree(tree*& root, std::string value, char volume) {
	tree* cur, * prev;
	findtree(root, value, cur, prev);
	if (cur != NULL) {
		volume == 'L' ? cur->left = NULL : cur->right = NULL;
		std::cout << "currently deleted" << std::endl;
	}
	else {
		std::cout << "cant delete" << std::endl;
	}
}

void TreeView1(tree*& root)
{
	if (root != NULL)
	{
		std::cout << root->value << " ";
		TreeView1(root->left);
		TreeView1(root->right);
	}
}

void TreeView2(tree*& root)
{
	if (root != NULL)
	{
		TreeView2(root->left);
		std::cout << root->value << " ";
		TreeView2(root->right);
	}
}

void TreeView3(tree*& root)
{
	if (root != NULL)
	{
		TreeView3(root->left);
		TreeView3(root->right);
		std::cout << root->value << " ";
	}
}

#endif // !_CREATE_SYSTEM_H

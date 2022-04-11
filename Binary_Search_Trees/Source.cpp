#include<iostream>
#include<stdio.h>
#include<stdbool.h>
#include<queue>

using namespace std;

struct node {
	int data;
	node* right;
	node* left;
};


node* insert_val(node* root, int x) {
	node* temp = (node*)malloc(sizeof(node));
	node* position = root;
	while (true)
	{
		if (root == NULL) {
			root = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		else if (x <= position->data && position->left == NULL) {
			printf("%d\n/\n%d'<-end'\n\n", position->data, x);
			position->left = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return root;
		}
		else if (x >= position->data && position->right == NULL) {
			printf("%d\n\\\n%d'<-end'\n\n", position->data, x);
			position->right = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return root;
		}
		else if (x <= position->data) {
			printf("%d\n/\n", position->data);
			position = position->left;
		}
		else if (x >= position->data) {
			printf("%d\n\\\n",position->data);
			position = position->right;
		}
	}
}

void print_tree_level(node* root) {
	if (root == NULL) return;
	node* temp;
	queue<node*> Q;
	queue<int> level;
	Q.push(root);
	level.push(0);
	while (!Q.empty()) {
		temp = Q.front();
		int old_level = level.front();
		if (temp->left != NULL) {
		Q.push(temp->left);
		level.push(level.front() + 1);
	}
		if (temp->right != NULL){
			Q.push(temp->right);
			level.push(level.front() + 1);
			}
		printf("%d level %d           ", temp->data, level.front());
		Q.pop();
		level.pop();

		if (!level.empty() && old_level != level.front() ) {
			printf("\n\n");
		}
	}
	printf("\n------------------------------\n");
}


node* rec_insert_val(node* root, int x) {
	if (root == NULL) {
		node* temp = (node*)malloc(sizeof(node));
		root = temp;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
		printf("%d<-end\n-------------------------\n", x);
		return root;
	}
	else if (x <= root->data) {
		printf("%d\n/\n", root->data);
		root->left=rec_insert_val(root->left, x);
	}
	else {
		printf("%d\n\\\n", root->data);
		root->right = rec_insert_val(root->right, x);
	}
	return root;
}

bool data_exists(node* root, int x) {
	bool temp;
	if (root == NULL) {
		printf("The data dosen't exist\n");
		return false;
	}
	else if (x == root->data) {
		printf("The data exists\n");
		return true;
	}
	else if (x <= root->data) {
		temp = data_exists(root->left, x);
		return temp;
	}
	else {
		temp = data_exists(root->right, x);
		return temp;
	}
}

node* data_exist_position(node* root, int x){
	node* temp = root;
	if (temp == NULL) {
		return temp;
	}
	else if (x == temp->data) {
		return temp;
	}
	else if (x <= temp->data) {
		temp = data_exist_position(temp->left, x);
		return temp;
	}
	else {
		temp = data_exist_position(temp->right, x);
		return temp;
	}
}
node* min_value(node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}
node* max_value(node* root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

node* data_delete(node* root, int x) {
	if (root == NULL) return root;
	else if (x < root->data) root->left = data_delete(root->left,x);
	else if (x > root->data) root->right = data_delete(root->right,x);
	else if (root->left==NULL && root->right==NULL){
		delete root;
		return NULL;
	}
	else if (root->left == NULL || root->right == NULL){
		if (root->left != NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		else {
			node* temp = root->right;
			delete root;
			return temp;
		}
	}
	else if (root->left != NULL && root->right != NULL) {
		node* temp = min_value(root->right);
		root->data = temp->data;
		root->right = data_delete(root->right, temp->data);
		
	}
	return root;
 }

int main() {
	bool test_data;
	node* root_tree_1 = NULL;
	root_tree_1= rec_insert_val(root_tree_1,10);
	root_tree_1 = rec_insert_val(root_tree_1,13);
	root_tree_1 = rec_insert_val(root_tree_1,8);
	root_tree_1 = rec_insert_val(root_tree_1, 7);
	root_tree_1 = rec_insert_val(root_tree_1, 12);
	root_tree_1 = rec_insert_val(root_tree_1, 6);
	root_tree_1 = rec_insert_val(root_tree_1, 17);
	root_tree_1 = rec_insert_val(root_tree_1, 14);
	root_tree_1 = rec_insert_val(root_tree_1, 18);
	print_tree_level(root_tree_1);
	root_tree_1=data_delete(root_tree_1, 13);
	print_tree_level(root_tree_1);
	root_tree_1 = data_delete(root_tree_1, 10);
	print_tree_level(root_tree_1);
	//printf("%d",root_tree_1->right);
}
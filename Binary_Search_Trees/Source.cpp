#include<iostream>
#include<stdio.h>

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

/*void print_tree() {
	node* position = root;
	node* position_left = position->left;
	node* position_right = position->right;
	printf("%d\n", position->data);
	if (position_left != NULL || position_right != NULL) {
		printf("/    |\n");
		if (position_left != NULL) {
			printf("%d", position_left->data);
		}
		if (position_right != NULL) {
			printf("    %d", position_right->data);
		}

	}
}
*/

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

int main() {

	node* root_tree_1 = NULL;
	root_tree_1= rec_insert_val(root_tree_1,10);
	root_tree_1 = rec_insert_val(root_tree_1,13);
	root_tree_1 = rec_insert_val(root_tree_1,8);
	root_tree_1 = insert_val(root_tree_1, 12);
}
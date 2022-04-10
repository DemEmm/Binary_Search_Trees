#include<iostream>
#include<stdio.h>

struct node {
	int data;
	node* right;
	node* left;
};
node* root = NULL;

void insert_val(int x) {
	node* temp = (node*)malloc(sizeof(node*));
	node* position = root;
	while (true)
	{
		if (root == NULL) {
			root = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return;
		}
		else if (x <= position->data && position->left == NULL) {
			printf("%d\n/\n%d'<-end'\n\n", position->data, x);
			position->left = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return;
		}
		else if (x >= position->data && position->right == NULL) {
			printf("%d\n\\\n%d'<-end'\n\n", position->data, x);
			position->right = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return;
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

void print_tree() {
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

int main() {
	insert_val(1);
	insert_val(13);
	insert_val(8);
	insert_val(12);
	insert_val(14);
	insert_val(4);
	insert_val(2);
	insert_val(5);
	//printf("%d", root->right->left->left->data);
}
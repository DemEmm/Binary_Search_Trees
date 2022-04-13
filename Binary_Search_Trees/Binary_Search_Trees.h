#pragma once
struct node {
	int data;
	node* right;
	node* left;
};
struct tree_Number {
	int tree_Num;
	node* addres_tree;
	tree_Number* next_tree;
};
node* Create_root();
node* insert_val(node* root, int x);
node* rec_insert_val(node* root, int x);
bool data_exists(node* root, int x);
node* data_exist_position(node* root, int x);
void print_tree_level(node* root);
node* min_value(node* root);
node* max_value(node* root);
node* data_delete(node* root, int x);
node* tree_delete(node* root);
#include<iostream>
#include<stdio.h>
#include<stdbool.h>
#include<queue>
#include<string>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

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
node* Create_root() {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = NULL;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
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
		else if (x < position->data && position->left == NULL) {
			printf("%d\n/\n%d'<-end'\n\n", position->data, x);
			position->left = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return root;
		}
		else if (x > position->data && position->right == NULL) {
			printf("%d\n\\\n%d'<-end'\n\n", position->data, x);
			position->right = temp;
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			return root;
		}
		else if (x == position->data) {
			printf("\nData %d already exists\n", position->data);
			return root;
		}
		else if (x < position->data) {
			printf("%d\n/\n", position->data);
			position = position->left;
		}
		else if (x >= position->data) {
			printf("%d\n\\\n",position->data);
			position = position->right;
		}
	}
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
	else if (x < root->data) {
		printf("%d\n/\n", root->data);
		root->left=rec_insert_val(root->left, x);
	}
	else if(x > root->data) {
		printf("%d\n\\\n", root->data);
		root->right = rec_insert_val(root->right, x);
	}
	else {
		printf("\nData %d already exists\n", root->data);
		return root;

	}
	return root;
}

bool data_exists(node* root, int x) {
	bool temp;
	if (root == NULL) {
		printf("The data doesn't exist\n");
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

void print_tree_level(node* root) {
	if (root == NULL) {
		printf("\nThere is no data in this tree root.\n");
		return;
	}
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
		if (temp->right != NULL) {
			Q.push(temp->right);
			level.push(level.front() + 1);
		}
		printf("%d level %d           ", temp->data, level.front());
		Q.pop();
		level.pop();

		if (!level.empty() && old_level != level.front()) {
			printf("\n\n");
		}
	}
	printf("\n------------------------------\n");
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
	if (root == NULL) {
		printf("\nThere isn't inserted data in this tree root\n");
		return root;
	}
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
node* tree_delete(node* root) {
	if (root->left != NULL) root->left=tree_delete(root->left);
	if (root->right != NULL) root->right=tree_delete(root->right);
	printf("\nTree is being deleted: Node %d will be deleted...\n", root->data);
	if (root->left == NULL && root->right == NULL) delete root;
	return NULL;
}

tree_Number* tree_P;
tree_Number* first_tree;

int main() {

	char oper;
	bool tree_exist = 0;


	while (true) {
		cout << "\n\nEnter an operation:\n1:Create a tree root\n2:Add new number\n3:Delete specific number\n";
		cout << "4:Delete the hole tree\n5:Print all numbers of tree roots\n6:Print specific tree levels\n7:Press 7 If you are Zack Perbolarakis!!! for BM.\nProgram is waiting for your operation command: \n\n";
		cin >> oper;
		switch (oper) {
		case '1': {
			if (tree_exist == 0) {
				first_tree = (tree_Number*)malloc(sizeof(tree_Number));
				first_tree->tree_Num = 1;
				first_tree->addres_tree = NULL;//Create_root();
				first_tree->next_tree = NULL;
				tree_exist = 1;
				tree_P = first_tree;
				printf("/n tree number 1 has been created\n");
			}
			else {
				tree_P = first_tree;
				while (tree_P->next_tree != NULL) {
					tree_P = tree_P->next_tree;
				}
				int old_num = tree_P->tree_Num;
				tree_P->next_tree = (tree_Number*)malloc(sizeof(tree_Number));
				tree_P = tree_P->next_tree;
				tree_P->next_tree = NULL;
				tree_P->tree_Num = old_num + 1;
				tree_P->addres_tree = NULL; //Create_root();
				printf("/n tree number %d has been created\n", tree_P->tree_Num);
			}
			break;
		}

		case '2':{
			int tree_nn;
			int data;
			try_again:
			printf("\nGive specific number of tree that will be inserted:\n");
			cin >> tree_nn;
			printf("\nGive specific number that will inserted:\n");
			cin >> data;
			tree_P = first_tree;
			if (tree_exist == 0) {
				printf("\There isn't tree root please create a tree root with command '1' and try again\n");
					break;
			}
			while (tree_P->tree_Num != tree_nn) {
				tree_P = tree_P->next_tree;
				if (tree_P == NULL) {
					printf("\nError: Wrong number of tree. There is no tree with number %d\n Please try again!\n", tree_nn);
					goto try_again;
				}
			}
			tree_P->addres_tree = rec_insert_val(tree_P->addres_tree, data);
			break;
		}
		case '3': {
			int tree_nn;
			int data;
		try_again2:
			printf("\nGive specific number of tree that will be deleted a number:\n");
			cin >> tree_nn;
			printf("\nGive specific number that will be deleted:\n");
			cin >> data;
			tree_P = first_tree;
			if (tree_exist == 0) {
				printf("\There isn't tree root please create a tree root with command '1' and try again\n");
				break;
			}
			while (tree_P->tree_Num != tree_nn) {
				tree_P = tree_P->next_tree;
				if (tree_P == NULL) {
					printf("\nError: Wrong number of tree. There is no tree with number %d\n Please try again!\n", tree_nn);
					goto try_again2;
				}
			}
			tree_P->addres_tree = data_delete(tree_P->addres_tree, data);
			break;
		}
			case '4':{
				int num;
				printf("\nGive specific number of tree that will be deleted\n");
				cin >> num;
				tree_P = first_tree;
				tree_Number* prev_tree = NULL;
				while (tree_P->tree_Num != num) {
					prev_tree = tree_P;
					tree_P = tree_P->next_tree;
				}
				num = tree_P->tree_Num;
				prev_tree->next_tree = tree_P->next_tree;
				printf("test %d", tree_P->addres_tree);
				tree_P->addres_tree=tree_delete(tree_P->addres_tree);
				delete(tree_P);
				printf("\nTree %d deleted\n", num );
				break;
			}
			case '5': {
				int num;
				tree_P = first_tree;
				printf("\n");
				while (tree_P->next_tree != NULL) {
					printf("  %d  ", tree_P->tree_Num);
					tree_P = tree_P->next_tree;
				}
				printf("\n");
				break; 
			}
			case '6': {
				int tree_nn;
			try_again3:
				printf("\nGive specific number of tree that will be printed:\n");
				cin >> tree_nn;
				tree_P = first_tree;
				if (tree_exist == 0) {
					printf("\There isn't tree root please create a tree root with command '1' and try again\n");
					break;
				}
				while (tree_P->tree_Num != tree_nn) {
					tree_P = tree_P->next_tree;
					if (tree_P == NULL) {
						printf("\nError: Wrong number of tree. There is no tree with number %d\n Please try again!\n", tree_nn);
						goto try_again3;
					}
				}
				print_tree_level(tree_P->addres_tree);
				break;
			}
			case '7': {
				printf("\033c");
				while (true) {
					fstream myfile;
					myfile.open("ez1.txt", ios::in);
					if (myfile.is_open()) {
						string line;
						while (getline(myfile, line)) {
							cout << line << endl;

							//printf("%s\n",line);
							Sleep(5);
						}
						myfile.close();
						printf("\033c");
					}
					myfile.open("ez2.txt", ios::in);
					if (myfile.is_open()) {
						string line;
						while (getline(myfile, line)) {
							cout << line << endl;

							//printf("%s\n",line);
							Sleep(5);
						}
						myfile.close();
						printf("\033c");
					}
				}
				break;
			}
			default: {
				printf("\nError: Wrong operation try again!\n");
				break; 
			}
		}
	}
}
	/*/bool test_data;
	node* root_tree_1 = NULL;
	root_tree_1= rec_insert_val(root_tree_1,10);
	root_tree_1 = insert_val(root_tree_1, 10);
	root_tree_1 = insert_val(root_tree_1,13);
	root_tree_1 = rec_insert_val(root_tree_1,8);
	root_tree_1 = rec_insert_val(root_tree_1, 7);
	root_tree_1 = rec_insert_val(root_tree_1, 12);
	root_tree_1 = rec_insert_val(root_tree_1, 6);
	root_tree_1 = rec_insert_val(root_tree_1, 17);
	root_tree_1 = rec_insert_val(root_tree_1, 14);
	root_tree_1 = rec_insert_val(root_tree_1, 18);
	root_tree_1 = rec_insert_val(root_tree_1, 18);
	print_tree_level(root_tree_1);
	root_tree_1=data_delete(root_tree_1, 13);
	print_tree_level(root_tree_1);
	root_tree_1 = data_delete(root_tree_1, 10);
	print_tree_level(root_tree_1);
	root_tree_1 = tree_delete(root_tree_1);
	print_tree_level(root_tree_1);
	//printf("%d",root_tree_1->right);*/
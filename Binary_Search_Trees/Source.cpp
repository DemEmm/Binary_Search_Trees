#include<iostream>
#include<stdio.h>
#include<stdbool.h>
#include<queue>
#include<string>
#include<fstream>
#include<string>
#include<Windows.h>
#include"Binary_Search_Trees.h"
using namespace std;

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
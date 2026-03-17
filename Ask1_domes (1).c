#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 200

#define OK 		1
#define NOT_OK 	2

#define NUMBER 	1
#define CHAR	2

typedef struct TreeNode{
	char symbol;
	int number;
	int type;
	
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

typedef struct StackNode{
	TreeNode* root;
	
	struct StackNode* lower;
} StackNode;


void delete_tree(TreeNode* root){
	if (root == NULL) return;
	
	delete_tree(root->left);
	delete_tree(root->right);
	
	free(root);
}


int ypologismos_apotelesmatos(TreeNode *root){
	int leftResult, rightResult;
	
	if (root == NULL) {
		printf("Vrika NULL komvo, lathos!\n");
		return 0;
	}
	
	if (root->type == NUMBER) return root->number;
	
	leftResult = ypologismos_apotelesmatos(root->left);
	rightResult = ypologismos_apotelesmatos(root->right);
	
	if (root->symbol == '+'){
		return leftResult + rightResult;
	}
	if (root->symbol == '-'){
		return leftResult - rightResult;
	}
	if (root->symbol == '*'){
		return leftResult * rightResult;
	}
	if (root->symbol == '%'){
		return leftResult % rightResult;
	}
	if (root->symbol == '/' && rightResult != 0){
		return leftResult / rightResult;
	}
	else {
		printf("Diairesi me to 0!\n");
		return leftResult;
	}
}

StackNode* makeSmallTree(StackNode* top){
	TreeNode* leftChild  = NULL;
	TreeNode* root       = NULL;
	TreeNode* rightChild = NULL;
	StackNode* oldTop    = NULL;
	
	
	if (top->lower == NULL) return top;

	rightChild = top->root;
	oldTop = top;
	
	top  = top->lower;
	root = top->root;
	
	free(oldTop);
	
	oldTop = top;
	
	top = top->lower;
	leftChild = top->root;
	
	free(oldTop);
	
	root->left = leftChild;
	root->right = rightChild;
	
	top->root = root;
	
	return top;
}

void printProthematiki(TreeNode* root){
	if (root == NULL) return;
	
	if (root->type == NUMBER){
		printf("%d", root->number);
	}
	else {
		printf("%c", root->symbol);
	}
	
	printProthematiki(root->left);
	printProthematiki(root->right);
}

void printMetathematiki(TreeNode* root){
	if (root == NULL) return;

	printMetathematiki(root->left);
	printMetathematiki(root->right);
	
	if (root->type == NUMBER){
		printf("%d", root->number);
	}
	else {
		printf("%c", root->symbol);
	}
}

int check_parastasi(char eisodos[N]){
	char ch;
	int i;
	int len = strlen(eisodos);
	
	for (i = 0 ; i < len ; i++){
		ch = eisodos[i];
		
		if (isdigit(ch)	) 	continue;
		if (ch == '('	) 	continue;
		if (ch == ')'	) 	continue;
		if (ch == '+'	) 	continue;
		if (ch == '-'	) 	continue;
		if (ch == '*'	) 	continue;
		if (ch == '/'	) 	continue;
		if (ch == '%'	) 	continue;
		
		printf("Lathos xaraktiras '%c'\n", ch);
		return NOT_OK;
	}
	return OK;
}

int einai_praksi(char ch){
	if (ch == '-') return OK;
	if (ch == '+') return OK;
	if (ch == '/') return OK;
	if (ch == '*') return OK;
	if (ch == '%') return OK;
	
	return NOT_OK;
}

StackNode* make_new_stack_node(TreeNode* treeNode){
	StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
	if (newStackNode == NULL){
		printf("malloc error!\n");
		exit(1);
	} 
	
	newStackNode->root  = treeNode;
	newStackNode->lower = NULL;
	
	return newStackNode;
}

TreeNode* make_new_tree_node_with_char(char ch){
	TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (newTreeNode == NULL){
		printf("malloc error!\n");
		exit(1);
	} 
	
	newTreeNode->number = 0;
	newTreeNode->symbol = ch;
	newTreeNode->type 	= CHAR;
	
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	
	return newTreeNode;
}

TreeNode* make_new_tree_node_with_number(int number){
	TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (newTreeNode == NULL){
		printf("malloc error!\n");
		exit(1);
	} 
	
	newTreeNode->number = number;
	newTreeNode->symbol = 0;
	newTreeNode->type 	= NUMBER;
	
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	
	return newTreeNode;
}

StackNode* addCharToStack(StackNode* top, char ch){
	TreeNode* newTreeNode   = NULL;
	StackNode* newStackNode = NULL;
	
	newTreeNode  = make_new_tree_node_with_char(ch);
	newStackNode = make_new_stack_node(newTreeNode);
	
	newStackNode->lower = top;
	
	return newStackNode;
}

StackNode* addNumberToStack(StackNode* top, int number){
	TreeNode* newTreeNode   = NULL;
	StackNode* newStackNode = NULL;
	
	newTreeNode  = make_new_tree_node_with_number(number);
	newStackNode = make_new_stack_node(newTreeNode);
	
	newStackNode->lower = top;
	
	return newStackNode;
}

TreeNode* make_binary_tree(char eisodos[N]){
	TreeNode* root = NULL;
	StackNode* top = NULL;
	int i, number, len = strlen(eisodos);
	char ch;
	
	
	for (i = 0 ; i < len ; i++){
		ch = eisodos[i];
		
		if (einai_praksi(ch) == OK){
			top = addCharToStack(top, ch);
		}
		else if (isdigit(ch)) {
			number = atoi(&eisodos[i]);
			
			top = addNumberToStack(top, number);
			top = makeSmallTree(top);
			
			while (isdigit(eisodos[i+1])) i++;
		}
		else if (ch == '(') {
			
		}
		else if (ch == ')'){
			
		}
		else {
			
		}
		
	}
	
	root = top->root;
	
	free(top);
	
	return root;
}



int main(){
	char eisodos[N];
	TreeNode* root = NULL;
	
	
	do{
		printf("\n1. Eisodos parastasis\n");
		printf("2. Ypologismos parastasis\n");
		printf("3. Emfanisi prothematikis morfis\n");
		printf("4. Emfanisi metathematikis morfis\n");
		printf("5. Ektiposi diadikou dentrou\n");
		printf("0. Eksodos\n");
		printf("Epilogi: ");
		scanf("%s", eisodos);
		
		if (strcmp(eisodos, "1") == 0){
			printf("\nDoste parastasi: ");
			scanf("%s", eisodos);
			
			if (check_parastasi(eisodos) == OK){
				if (root != NULL) delete_tree(root);
				
				root = make_binary_tree(eisodos);
			}
		}
		else if (strcmp(eisodos, "2") == 0){
			if (root == NULL){
				printf("\n*** Den exete dosei parastasi!\n");
			}
			else {
				printf("\nApotelesma: %d\n", 
					ypologismos_apotelesmatos(root));
			}
		}
		else if (strcmp(eisodos, "3") == 0){
			if (root == NULL){
				printf("\n*** Den exete dosei parastasi!\n");
			}
			else {
				printf("\nProthematiki morfi: ");
				printProthematiki(root);
				printf("\n");
			}
		}
		else if (strcmp(eisodos, "4") == 0){
			if (root == NULL){
				printf("\n*** Den exete dosei parastasi!\n");
			}
			else {
				printf("\nMetathematiki morfi: ");
				printMetathematiki(root);
				printf("\n");
			}
		}
		else if (strcmp(eisodos, "5") == 0){
			
		}
	} while (strcmp(eisodos, "0") != 0);
	
	if (root != NULL) delete_tree(root);
	
	return 0;
}
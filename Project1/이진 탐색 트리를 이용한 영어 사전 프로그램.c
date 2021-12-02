#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

typedef struct TreeNode {
	element key;
	TreeNode* left, * right;
}TreeNode;
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
	//만약 e1<e2이면 -1 반환
	//만약 e1==e2이면 0 반환
	//만약 e1>e2이면 1 반환
}
//이진 탐색 트리 출력 함수
void display(TreeNode* p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
}
//이진 탐색 트리 탐색 함수
TreeNode* search(TreeNode* root, element key)
{
	TreeNode* p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p;
}
TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, element key)
{
	if (node == NULL)
		return new_node(key);
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
//키가 저장된 노드 삭제,새로운 루트 노드를 반환
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL) return root;
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
void help()
{
	printf("\n**** i: 입력,d: 삭제,s: 탐색,p:출력,q:종료 ****: ");
}
int main()
{
	char command;
	element e;
	TreeNode *root = NULL;
	TreeNode* tmp;
	
	do {
		help();
		command = getchar();
		getchar();
		switch (command) {
		case 'i':
			printf("단어:");
			gets(e.word);
			printf("의미:");
			gets(e.meaning);
			root = insert_node(root, e);
			break;
		case 'd':
			printf("단어:");
			gets(e.word);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("단어:");
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미:%s\n", e.meaning);
			break;
		}
	} while (command != 'q');
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)
		return NULL;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key)
{
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (node == NULL)
		return new_node(key);
	//�׷��� ������ ��ȯ������ Ʈ���� �᳻������.
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
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
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL)
		return root;
	//���� Ű�� ��Ʈ���� ������->���� ���� Ʈ���� �ִ� ��
	if (key < root->key)
		root->left = delete_node(root->left, key);
	//���� Ű�� ��Ʈ���� ũ��->������ ���� Ʈ���� �ִ� ��
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	//Ű�� ��Ʈ�� ������->��带 �����Ѵ�.
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

		//�߿� ��ȸ�� �İ� ��带 �����Ѵ�
		root->key = temp->key;
		//�߿� ��ȸ�� �İ� ��带 �����Ѵ�
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
//���� ��ȸ
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d]", root->key);
		inorder(root->right);
	}
}
int main()
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	int numbers[11] = { 11, 3, 4, 1, 56, 5, 6, 2, 98, 32, 23 };

	for (int i = 0; i <11; i++)
	{
		root = insert_node(root, numbers[i]);
	}

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");

	return 0;
}
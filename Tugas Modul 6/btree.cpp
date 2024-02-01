#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};


Node* newNode(int data)
{
	Node *node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void printPostorder(Node *node){
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout<<node->data<<" ";
}

void printInorder(Node *node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

void printPreorder(Node *node){
	if (node == NULL)
		return;
	cout<<node->data<<" ";
	
	printPreorder(node->left);
	printPreorder(node->right);
}

int main(){
	Node* root = newNode(7);
	root->left = newNode(1);
	root->right = newNode(9);
	root->left->left = newNode(0);
	root->left->right = newNode(3);
	root->right->left = newNode(8);
	root->right->right = newNode(10);
	root->left->right->left = newNode(2);
	root->left->right->right = newNode(5);
	root->left->right->right->left = newNode(4);
	root->left->right->right->right = newNode(6);


	printf("\nPreorder traversal of binary tree adalah : \n");
	printPreorder(root);
	printf("\nInorder traversal of binary tree adalah : \n");
	printInorder(root);
	printf("\nPostorder traversal of binary tree adalah : \n");
	printPostorder(root);
	
	return 0;
}

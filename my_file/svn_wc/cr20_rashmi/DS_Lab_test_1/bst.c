#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct bst_node {
	int info;
	struct bst_node *left;
	struct bst_node *right;
	}BST;

BST* getnode(int);

int sum_of_elements(int sum , BST* root)
{
	if(root == NULL)
		return sum;

	sum = sum_of_elements(sum, root -> left);
	sum = sum + root->info;
	sum = sum_of_elements(sum, root -> right);
}



BST* insert(BST *root , int data)
{

	if(root == NULL) {
		root = getnode(data);
		return root;
	}

	else if(data < root->info) 
		root -> left = insert(root->left , data);

	else
		root->right = insert(root->right , data);

	return root;
}

BST* getnode(int data)
{
	BST *new_node = NULL;
	if(NULL == (new_node= (BST *) malloc (sizeof(BST)))){
        perror("malloc failed");
        exit(EXIT_FAILURE);
	}

	new_node->info = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

int search(BST* root)
{
	while(root->left != NULL){
		root = root->left;
	}
	return (root->info);
}

void display(BST *root)
{
	if(root == NULL)
		return;

	display(root -> left);
	printf("%d\n", root -> info);
	display(root -> right);
}
int main(void)
{
	BST* root = NULL;
	int num_node = 0;
	char *buf = NULL;
	int i = 0;
	int data;
	int least = 0;

	printf("Enter the number of nodes:\n");

	if(NULL == (buf = (char *) malloc (sizeof(int) * MAX))){
		perror("malloc failed");
		exit(EXIT_FAILURE);
		}

	if(NULL == (fgets(buf , MAX , stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
		}
	
		num_node = atoi(buf);
		
		while( i < num_node) {
		
			printf("Enter the data to be inserted:\n");

    		if(NULL == (fgets(buf , MAX , stdin))){
        		perror("fgets failed");
        		exit(EXIT_FAILURE);
        		}
			data = atoi(buf);

			root = insert(root , data);	
		 i++;
		display(root);
	
		}
	
	printf("least element in BST is = %d\n", search(root));

	int sum = 0;

	printf("sum of nodes in BST = %d\n", sum_of_elements(sum, root));

	return 0;
} 

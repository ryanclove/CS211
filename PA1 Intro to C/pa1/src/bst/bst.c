#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

//new node
struct node *newNode(int item) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

//traverse
void traverse(struct node *root) {
	if (root != NULL) {
		printf("(");
		traverse(root->left);
		printf("%d", root->key);
		traverse(root->right);
		printf(")");
	}
}
struct node* search(struct node* root, int key) {
	//Base case
	if (root == NULL || root->key == key) {
		return root;
	}
	if (root->key < key) {
		return search(root->right, key);
	}
	return search(root->left, key);
}
//insert
struct node* insert(struct node* node, int key) {
	if (node == NULL) {
		printf("inserted\n");
		return newNode(key);
	}
	if (key < node->key) {
		node->left = insert(node->left, key);
	} else if (key > node->key) {
		node->right = insert(node->right, key);
	} else if (key == node->key)  {
		printf("duplicate\n");
	}
	return node;
}
struct node * minValue(struct node* node) {
	struct node* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
//delete
struct node* delete(struct node* root, int key) {
	if (root == NULL) {
		return root;
	}
	if (key < root->key) {
		root->left = delete(root->left, key);
	} else if (key > root->key) {
		root->right = delete(root->right, key);
	} else {
		//one or no child
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		//two children
		struct node* temp = minValue(root->right);
		root->key = temp->key;
		root->right = delete(root->right, temp->key);
	}
	return root;
}

int valid(char command) {
	if(command == 'i' || command == 'd' || command == 's' || command == 'p') {
 	return 1;
} else { 
	return 0;
	}
}

int main(int argc, char **argv) {
	char command;
	int n;
	struct node *root = NULL;
	FILE *f1;
	f1 = fopen(argv[1], "r");
	if (f1 == NULL) {
		return 0;
	}

	fscanf(f1, "%n", &n);
	do {
		fscanf("%c", &command);
		if(command == 'i') {
			fscanf("%d", &n);
			root = insert(root, n);
		} else if (command == 'd') {
			fscanf("%d", &n);
			root = delete(root, n);
			printf("deleted\n");
		} else if (command == 's') {
			fscanf("%d", &n);
			if (search(root, n)) {
				printf("present\n");
			} else {
				printf("absent\n");
		 	}
		} else if (command == 'p') {
			traverse(root);
			printf("\n");
		} else command = 'q';
			while ((getchar()) != '\n');
		}
	while(valid(command));
	return 0;
}				

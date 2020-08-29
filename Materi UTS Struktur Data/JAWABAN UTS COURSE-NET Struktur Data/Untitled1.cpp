#include <stdio.h>
#include <stdlib.h>

struct Data {
	int number;
	Data *left, *right;
} *root = NULL;

Data* insert (Data *node, int number){
	// belum ada data
	if (node == NULL){
		Data *curr = (Data*) malloc(sizeof(struct Data));
		curr->number = number;
		curr->left = curr->right = NULL;
		printf("Data berhasil diinput");
		return curr;
	}
	// angka yang diinput sudah ada
	else if(node->number == number){
		printf("Insert gagal, angka sudah ada");
	}
	// angka diinsert ke kiri
	else if(number < node->number){
		node->left = insert(node->left, number);
	}
	// angka diinsert ke kanan
	else if(number > node->number){
		node->right = insert(node->right, number);
	}
	return node;
}

void inOrder (Data *node){
	if(node == NULL) return;

	inOrder(node->left);
	printf("%d ", node->number);
	inOrder(node->right);
}

Data* deleteNumber (Data *node,  int number){
	printf("asd");
	// angka tidak ditemukan
	if(node == NULL){
		printf("Angka tidak ditemukan");
	}
	// angka delete ditemukan
	else if(node->number ==  number){
		// angka tidak punya child
		if(node->left == NULL && node->right == NULL){
			printf("asd");
			free(node);
			node = NULL;
		}
		// angka punya left child
		else if(node->left != NULL && node->right == NULL){
			Data *temp = node->left;
			free(node);
			return temp;
		}
		// angka punya right child
		else if(node->left == NULL && node->right != NULL){
			Data *temp = node->right;
			free(node);
			return temp;
		}
		// angka punya 2 child
		else{
			Data *temp = node->left;
			while(temp->right != NULL){
				temp = temp->right;
			}
			node->number = temp->number;
			node->left = deleteNumber (node->left, temp->number);
		}
	}
	// angka delete ada di left
	else if(number < node->number){
		node->left = deleteNumber (node->left, number);
	}
	// angka delete ada di right
	else if(number > node->number){
		node->right = deleteNumber (node->right, number);
	}
	
	return node;
}

int main(){
	int number, menu;

	do{
		system("CLS");
		inOrder(root);
		printf("\n\n");
		printf("Binary Search Tree\n");
		printf("1. Push data\n");
		printf("2. Remove data\n");
		printf("3. Exit\n");
		printf("Choose : ");
		scanf("%d", &menu); fflush(stdin);

		switch (menu){
			case 1 :
				printf("Insert number : ");
				scanf("%d", &number);fflush (stdin);
				root = insert (root, number);

				break;

			case 2 :
				printf("Delete number : ");
				scanf("%d", &number);fflush (stdin);
				root = deleteNumber (root, number);
				break;
		}
		getchar();
	}while (menu!=3);

}

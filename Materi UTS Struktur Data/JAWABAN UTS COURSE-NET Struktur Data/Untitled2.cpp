#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinarySearchTree{
	int number;
	BinarySearchTree *left,*right;
}*root=NULL;

BinarySearchTree *insert(BinarySearchTree *node,int number)
{
	if(node==NULL)

	{
		BinarySearchTree *current = (BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
		current->number=number;
		current->left=current->right=NULL;
	
		printf(" Berhasil Diinput\n");getchar();
	
		return current;
	}
	else if(node->number==number)
	{
		printf("Insert gagal,  sudah ada\n");getchar();
	}
	else if(number < node->number)
	{
		node->left = insert(node->left,number);	
	}	
	else if(number > node->number)
	{
		node->right = insert(node->right,number);
	}
	return node;
}

BinarySearchTree *deleteNumber( BinarySearchTree *node,int number)
{
	if(node==NULL)
	{
		printf("Angka tidak Ditemukan\n");getchar();
	}
	else if(node->number==number)
	{
		if(node->left==NULL && node->right==NULL)
		{
			free(node);
			node=NULL;
		}
		else if(node->left != NULL && node->right==NULL)
		{
			BinarySearchTree *temp = node->left;
			free(node);
		}
		else if(node->left == NULL && node->right != NULL)
		{
			BinarySearchTree *temp = node->right;
			free(node);
		}
		else
		{
			BinarySearchTree *temp = node->left;
			
			while(temp->right != NULL)
			{
				temp=temp->right;
			}
			node->number=temp->number;
			node->left = deleteNumber(node->left,temp->number);
		}
	}
	else if(number < node->number)
	{
		node->left = deleteNumber(node->left,number);
	}
	else if(number > node->number)
	{
		node->right = deleteNumber(node->right,number);
	}
	return node;
}

void preOrder(BinarySearchTree *node)
{
	if(node==NULL)
	{
		return;
	}
	printf("%d ",node->number);
	preOrder(node->left);
	preOrder(node->right);
}

void inOrder(BinarySearchTree *node)
{
	if(node==NULL)
	{
		return;
	}
	inOrder(node->left);
	printf("%d ",node->number);
	inOrder(node->right);
}

void postOrder(BinarySearchTree *node)
{
	if(node==NULL)
	{
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	printf("%d ",node->number);
}

int main()
{
	int pilihan,number;
	
	do{
		system("cls");
		printf("BINARY SEARCH TREE MENU\n");
		printf("1. Push Data\n");
		printf("2. Delete Data\n");
		printf("3. View PreOrder\n");
		printf("4. View InOrder\n");
		printf("5. View PostOrder\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d",&pilihan);fflush(stdin);
		
		switch(pilihan)
		{
			case 1:
				printf("Masukkan Angka : ");
				scanf("%d",&number);fflush(stdin);
				root = insert(root,number);
				break;
			case 2:
				printf("Masukkan Angka yang ingin dihapus : ");
				scanf("%d",&number);fflush(stdin);
				root = deleteNumber(root,number);
				break;
			case 3:
				printf("PreOrder  : ");preOrder(root);getchar();
				break;
			case 4:
				printf("InOrder   : ");inOrder(root);getchar();
				break;
			case 5:
				printf("PostOrder : ");postOrder(root);getchar();
				break;
		}
	}while(pilihan != 6);
}

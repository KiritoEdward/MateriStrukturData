#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char nama[100];
	char ID[100];
	data *next;
}*head,*tail,*current;

void pushTail(char nama[],char ID[])
{
	current = (data*)malloc(sizeof(struct data));
	
	strcpy(current->nama,nama);
	strcpy(current->ID,ID);
	current->next=NULL;
	
	if(head==NULL)
	{
		head = tail = current;
	}
	else
	{
		tail->next=current;
		tail=current;
	}
	tail->next=NULL; 
}

void pop(){
	// code pop dari queue
	
	if(head==NULL){
		printf("Tidak ada data\n");
	
	}else if(head==tail){
		
		head=tail=NULL;
		
		free(current);
	}else{
		data *temp=head;

		while(temp->next!=tail){
			temp=temp->next;
		}
		current=tail;
		tail=temp;
		free(current);
		tail->next=NULL;
	}
}

void view()
{
	current = head;
	
	if(current==NULL)
	{
		printf("%s(%s)->",current->nama,current->ID);
		current=current->next;
	}
}

int main()
{
	int pilihan;
	char ID[100];
	char nama[100];
	
	do{
		system("cls");
		printf("Queue Menu Single Linked List\n");
		view();printf("\n");
		printf("1. Push Data\n");
		printf("2. Pop Data\n");
		printf("3. Exit\n");
		printf("Masukkan Pilihan: ");
		scanf("%d",&pilihan);fflush(stdin);
		
		switch(pilihan)
		{
			case 1:
				printf("Masukkan Nama Anda : ");
				scanf("%s",nama);fflush(stdin);
				printf("Masukkan NIM Anda : ");
				scanf("%s",ID);fflush(stdin);
				pushTail(nama,ID);
				break;
			case 2:
					pop();
				break;
		}
	}while(pilihan !=3);
}

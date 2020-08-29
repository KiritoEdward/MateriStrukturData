#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char nama[100];
	data *next,*prev;
}*head[10],*tail[10],*current;

int hash(char nama[])
{
	int totalAscii=0;
	
	for(int i=0;i<strlen(nama);i++)
	{
		totalAscii=totalAscii+nama[i];
	}
	return totalAscii%10;
}

void insertHash(char nama[])
{
	current = (data*)malloc(sizeof(struct data));
	
	strcpy(current->nama,nama);
	current->next=current->prev=NULL;
	
	int hasilHash = hash(nama);
	
	if(head[hasilHash]==NULL)
	{
		head[hasilHash]=tail[hasilHash]=current;
	}
	else
	{
		tail[hasilHash]->next=current;
		current->prev=tail[hasilHash];
		tail[hasilHash]=current;
	}
}

void viewAll()
{
	for(int i=0;i<10;i++)
	{
		printf("%d: ",i);
		
		if(head[i]==NULL)
		{
			printf("NULL\n");
		}
		else
		{
			current = head[i];
			
			while(current != NULL)
			{
				printf("%s -> ",current->nama);
				current=current->next;
			}
			puts("");
		}
	}
}

int main()
{
	int pilihan;
	char nama[100];
	
	do{
		system("cls");
		viewAll();
		printf("Hash Table Menu Example\n");
		printf("1. Push Hash\n");
		printf("2. Exit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d",&pilihan);fflush(stdin);
		
		switch(pilihan)
		{
			case 1:
				printf("Masukkan Nama Anda : ");
				scanf("%[^\n]",nama);fflush(stdin);
				insertHash(nama);
				break;
		}
	}while(pilihan != 2);
}

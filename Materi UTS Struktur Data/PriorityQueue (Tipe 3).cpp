#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct customer{
	 char nama[30];
	 char status[25];
	 int umur;
	 int prioritas;
	 struct customer *next;
 };
struct customer *head=NULL;

void insert_data(struct customer *new_customer){
	struct customer *ptr;
	ptr=head;
	if(head == NULL || new_customer ->prioritas < head->prioritas){
		new_customer->next = head;
		head=new_customer;
	}else{
		while(ptr->next != NULL && new_customer->prioritas >= ptr->next->prioritas){
			ptr = ptr->next;
		}
		new_customer->next = ptr->next;
		ptr->next = new_customer;
	}
 }

void display(){
	 struct customer *ptr;
	 int i=1;
	 ptr=head;
	 printf("==============================================\n");
	 printf("| No. | Nama                 | Status | Umur |\n");
	 printf("==============================================\n");
	 while(ptr!=NULL)
	 {
		 printf("| %3d | %20s | %6s | %4d |\n",  i, ptr->nama, ptr->status, ptr->umur);
		 i=i+1;
		 ptr=ptr->next;

	 }
	 printf("==============================================\n");
 }

 void panggil_customer(){
	struct customer *ptr;
	char panggilan[10];
	ptr=head;
	if(ptr==NULL)
	{
	    printf("No Data !!!");
    }
    else {
        printf("%s Silahkan Menuju Ke Counter\n",ptr->nama);
    }
	head = head ->next;
	free(ptr);
 }

 int cek_nama(char nama[30]){
	int flag=0;
	for(int i = 0 ; i < strlen(nama) ; i++){
		 if(isalpha(nama[i]) || nama[i] == ' '){
			flag= 1;
		 }else{
			flag = 0;
			break;
		 }
	 }
	 return flag;
 }

 int cek_status(char status[30]){
	 int flag = 0;
	 if((strcmpi(status , "Regular") == 0 ||strcmpi(status , "Silver") == 0) || strcmpi(status , "Gold") == 0 || strcmpi(status , "Platinum") == 0){
			 flag = 1;
	 }else{
		 flag = 0;
	 }

	 return flag;
 }

int main()
{
	int choice, umur;
	struct customer *new_customer;
	
	char nama[30], status[30];
	do
	{
		system("cls");
		printf("KiritoAsuna Bank\n");
		printf("================\n\n");
		//display
		display();
		printf("\n\n1. Registrasi customer\n");
		printf("2. Panggil customer\n");
		printf("3. Exit\n");
		printf(">> Masukkan pilihan: "); scanf("%d", &choice); fflush(stdin);
		switch(choice)
		{
		case 1:
			system("cls");
			do{
			printf("1. Masukkan nama [5..20]: "); 
			scanf("%[^\n]", nama); 
			fflush(stdin);
			}while(cek_nama(nama) == 0 || (strlen(nama) < 5 || strlen(nama) > 20));

			printf("2. Masukkan umur [5..100]: "); 
			scanf("%d", &umur); 
			fflush(stdin);

			do{
			printf("3. Masukkan Status: "); 
			scanf("%[^\n]", status); 
			fflush(stdin);
			}while(cek_status(status) == 0);
			new_customer= (customer*)malloc(sizeof(customer));
			strcpy(new_customer->nama,nama);
			new_customer->umur = umur;
			strcpy(new_customer->status,status);

			if(strcmpi(status , "Platinum") == 0){
				new_customer->prioritas = 1;
			}else if(strcmpi(status , "Gold") == 0){
				new_customer->prioritas = 2;
			}else if(strcmpi(status , "Silver") == 0){
				new_customer->prioritas = 3;
		    }else{
				new_customer->prioritas = 4;
			}
			insert_data(new_customer);
			printf("\nCustomer berhasil diregistrasi.. ");
			getchar();
			break;
		case 2:
			system("cls");
			panggil_customer();
			getchar();
			break;
		}
	}while(choice!=3);
	return 0;
}

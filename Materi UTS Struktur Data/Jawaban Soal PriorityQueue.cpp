#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct penumpang{
	 char nama[30];
	 char status[25];
	 int umur;
	 int prioritas;
	 struct penumpang *next;
 };
struct penumpang *head=NULL;

void insert_data(struct penumpang *new_penumpang){
	struct penumpang *ptr;
	ptr=head;
	if(head == NULL || new_penumpang ->prioritas < head->prioritas){
		new_penumpang->next = head;
		head=new_penumpang;
	}else{
		while(ptr->next != NULL && new_penumpang->prioritas >= ptr->next->prioritas){
			ptr = ptr->next;
		}
		new_penumpang->next = ptr->next;
		ptr->next = new_penumpang;
	}
 }

void display(){
	 struct penumpang *ptr;
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

 void panggil_penumpang(){
	struct penumpang *ptr;
	char panggilan[10];
	ptr=head;
	if(ptr==NULL)
	{
	    printf("No Data !!!");
    }
    else {
        printf("%s Silahkan Masuk Ke Pesawat\n",ptr->nama);
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
	 if((strcmpi(status , "VIP") == 0 ||strcmpi(status , "Regular") == 0)){
			 flag = 1;
	 }else{
		 flag = 0;
	 }

	 return flag;
 }

int main()
{
	int choice, umur;
	struct penumpang *new_penumpang;
	
	char nama[30], status[30];
	do
	{
		system("cls");
		printf("XYZ Airline\n");
		printf("===========\n\n");
		//display
		display();
		printf("\n\n1. Registrasi penumpang\n");
		printf("2. Panggil penumpang\n");
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
			new_penumpang= (penumpang*)malloc(sizeof(penumpang));
			strcpy(new_penumpang->nama,nama);
			new_penumpang->umur = umur;
			strcpy(new_penumpang->status,status);

			if(strcmpi(status , "VIP") == 0){
				new_penumpang->prioritas = 1;
			}else if(strcmpi(status , "Regular") == 0 && new_penumpang->umur > 55){
			    strcpy(new_penumpang->status,"Elderly");
				new_penumpang->prioritas = 2;
			}else{
				new_penumpang->prioritas = 3;
			}
			insert_data(new_penumpang);
			printf("\nPenumpang berhasil diregistrasi.. ");
			getchar();
			break;
		case 2:
			system("cls");
			panggil_penumpang();
			getchar();
			break;
		}
	}while(choice!=3);
	return 0;
}

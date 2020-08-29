#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct pasien{
	 char nama[30];
	 char penyakit[30];
	 char gender[10];
	 int umur;
	 char jenis_penyakit[10];
	 int prioritas;
	 struct pasien *next;
 };
struct pasien *head=NULL;

void insert_data(struct pasien *new_pasien){
	struct pasien *ptr;
	ptr=head;
	if(head == NULL || new_pasien ->prioritas < head->prioritas){
		new_pasien->next = head;
		head=new_pasien;
	}else{
		while(ptr->next != NULL && new_pasien->prioritas >= ptr->next->prioritas){
			ptr = ptr->next;
		}
		new_pasien->next = ptr->next;
		ptr->next = new_pasien;
	}

 }

void display(){
	 struct pasien *ptr;
	 int i=1;
	 ptr=head;
	 printf("==============================================================================\n");
	 printf("| No. | Nama                 | Gender | Umur |   Penyakit   | Jenis Penyakit |\n");
	 printf("==============================================================================\n");
	 while(ptr!=NULL)
	 {
		 printf("| %3d | %20s | %6s | %4d | %12s | %14s |\n",  i, ptr->nama, ptr->gender, ptr->umur, ptr->penyakit, ptr->jenis_penyakit);
		 i=i+1;
		 ptr=ptr->next;

	 }
	 printf("==============================================================================\n");
 }

 void panggil_dokter(){
	struct pasien *ptr;
	char panggilan[10];
	ptr=head;
	if(strcmp(ptr->gender,"pria")==0)
	{
	    printf("Bapak %s Silahkan Masuk Ke Ruangan\n",ptr->nama);
    }
    else
    {
        printf("Ibu %s Silahkan Masuk Ke Ruangan\n",ptr->nama);
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

 int cek_penyakit(char penyakit[30]){
	 int flag = 0;
	 if((strcmpi(penyakit , "batuk") == 0 ||strcmpi(penyakit , "demam") == 0 ||strcmpi(penyakit , "flu") == 0) 
		 ||strcmpi(penyakit , "cacar") == 0 ||strcmpi(penyakit , "campak") == 0 ||strcmpi(penyakit , "diare") == 0
		 ||strcmpi(penyakit , "hepatitis") == 0 ||strcmpi(penyakit , "kanker") == 0 ||strcmpi(penyakit , "usus buntu") == 0){
			 flag = 1;
	 }else{
		 flag = 0;
	 }

	 return flag;
 }

int main()
{
	int choice, umur;
	struct pasien *new_pasien;
	
	char nama[30], penyakit[30], jenis_penyakit[10], gender[10];
	do
	{
		system("cls");
		printf("Klinik Dr. Jonni\n");
		printf("================\n\n");
		//display
		display();
		printf("\n\n1. Registrasi pasien\n");
		printf("2. Panggil pasien\n");
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

			printf("3. Masukkan gender [pria | wanita]: "); 
			scanf("%s", gender); 
			fflush(stdin);
			do{
			printf("4. Masukkan penyakit: "); 
			scanf("%[^\n]", penyakit); 
			fflush(stdin);
			}while(cek_penyakit(penyakit) == 0);
			new_pasien= (pasien*)malloc(sizeof(pasien));
			strcpy(new_pasien->nama,nama);
			new_pasien->umur = umur;
			strcpy(new_pasien->gender,gender);
			strcpy(new_pasien->penyakit,penyakit);

			if(strcmpi(penyakit , "batuk") == 0 ||strcmpi(penyakit , "demam") == 0 ||strcmpi(penyakit , "flu") == 0){
				strcpy(new_pasien->jenis_penyakit,"ringan");
				new_pasien->prioritas = 3;
			}else if(strcmpi(penyakit , "cacar") == 0 ||strcmpi(penyakit , "campak") == 0 ||strcmpi(penyakit , "diare") == 0){
				strcpy(new_pasien->jenis_penyakit,"sedang");
				new_pasien->prioritas = 2;
			}else{
				strcpy(new_pasien->jenis_penyakit,"parah");
				new_pasien->prioritas = 1;
			}
			insert_data(new_pasien);
			printf("\nPasien telah teregistrasi.. ");
			getchar();
			break;
		case 2:
			system("cls");
			panggil_dokter();
			getchar();
			break;
		}
	}while(choice!=3);
	return 0;
}

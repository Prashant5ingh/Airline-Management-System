#include<stdio.h>
#include<conio.h>
#include<string.h>

#include<process.h>


int Main_Menu();
int Login();


char password[20];
char username[15];

struct Airline_data{
int Flight_no;
char Flight_name[20];
char destination[20];
char A_time[20];
char D_time[20];
float cost;
}A;

struct User_data{
	int User_id;
	char Name[20];
	char Address[20];
	int Mob;
	char dest[20];
	char Book_C[20];
	char Payment_M[20];
};
void Airline_Insert()
{
   	FILE*fp;
  fp = fopen ("Airline_data","a");
  printf("\n\t***** ENTER THE DETAILS OF AIRLINE *****\n\n");
  printf("Enter Flight No: ");
  scanf("%d",&A.Flight_no);
  printf("Enter Flight Name: ");
  scanf("%s",&A.Flight_name);
  printf("Enter Flight Destination: ");
  scanf("%s",&A.destination);
  printf("Enter Arrival Time of Flight: ");
  scanf("%s",&A.A_time);
  printf("Enter Departure Time of Flight:");
  scanf("%s",&A.D_time);
  printf("Enter Cost Of Flight: ");
  scanf("%f",&A.cost);

  fwrite(&A,sizeof (A),1,fp);
  fclose(fp);
  printf("\n***** Airline Data Entry is added *****\n");
}

void Airline_Display()
{
	FILE*fp;

	fp=fopen("Airline_data","r");
	if(fp==NULL)
	{ printf("\n File Not Found");
	}
while(fread(&A,sizeof(struct Airline_data),1,fp))
	{printf("\n\t***** DETAILS OF AIRLINE *****\n\n");
	 printf("Airline Flight No    : %d\n",A.Flight_no);
	 printf("Airline Flight Name  : %s\n",A.Flight_name);
	 printf("Flight Destination   : %s\n",A.destination);
	 printf("Flifgt Arrival Time  : %s\n",A.A_time);
	 printf("Flight Departure Time: %s\n",A.D_time);
     printf("Airline Flight Cost  : %f\n",A.cost);
	}
	fclose(fp);
	printf("\n\nEnter Any Key To Continue\n");
	getch();
}

void User_Insert()
{ struct User_data U;
	FILE*fs;
  fs=fopen("User Record","a");
  printf("\n\t***** ENTER THE DETAILS OF USER *****\n\n");
  printf("Enter User Id: ");
  scanf("%d",&U.User_id);
  printf("Enter User Name: ");
  scanf("%s",&U.Name);
  printf("Enter User Address: ");
  scanf("%s",&U.Address);
  printf("Enter User Mobile No: ");
  scanf("%d",&U.Mob);
  printf("Enter User Destination: ");
  scanf("%s",&U.dest);
  printf("Enter User Booking Class: ");
  scanf("%s",&U.Book_C);
  printf("Enter User Payment Mode: ");
  scanf("%s",&U.Payment_M);
  fwrite(&U,sizeof (struct User_data),1,fs);
  fclose(fs);
  printf("\n***** User Data Entry is added *****\n");
}

void User_Display()
{  struct User_data U;
	FILE*fs;
	fs=fopen("User Record","r");
	if(fs==NULL)
	{ printf("\n File Not Found");
	}


	while(fread(&U,sizeof(struct User_data),1,fs))
	{
	printf("\n\t***** DETAILS OF USER *****\n\n");	
	printf("\nUser ID        : %d", U.User_id);
    printf("\nName           : %s", U.Name);
    printf("\nUser Address   : %s", U.Address);
    printf("\nMobile No      : %d", U.Mob);
    printf("\nDestination    : %s", U.dest);
    printf("\nBooking Class  : %s", U.Book_C);
    printf("\nPayment Mode   : %s", U.Payment_M);

	}
	fclose(fs);
	printf("\n\nEnter Any Key");
	getch();
}
void search()
{  int n;
   printf("\n\nEnter to Search data of User or Airline(1/2) : ");
   scanf("%d",&n);
	if(n==1)
	{
    FILE *fp; int i,ser,found=0;
    struct User_data U;

	printf("\nEnter User ID to Search:");
	scanf("%d",&ser);
    fp=fopen("User Record","r");
    if(fp==NULL)
     {
      printf("\nFile not Exits");
      exit(0);
     }
    fseek(fp,0,SEEK_SET);
    while(fread(&U,sizeof( struct User_data),1,fp)!=NULL)
    {
       if(U.User_id==ser)
          {
          	found=1;
          	printf("\nRecord Found");
          	exit(0);
		  }
    }
    fclose(fp);
    if(found==0)
     printf("\nRecord Not Found");
}
else if(n==2)
{ FILE *fp1; int i,ser,found=0;
    struct Airline_data A;

	printf("Enter Airline Flight No. to Search: ");
	scanf("%d",&ser);
    fp1=fopen("Airline_data","r");
    if(fp1==NULL)
     {
      printf("\nFile not Exits");
      exit(0);
     }
    fseek(fp1,0,SEEK_SET);
    while(fread(&A,sizeof( struct Airline_data),1,fp1)!=NULL)
    {
       if(A.Flight_no==ser)
          {
          	found=1;
          	printf("\nRecord Found");
          	exit(0);
		  }
    }
    fclose(fp1);
    if(found==0)
     printf("\nRecord Not Found");
	
}
else
{ printf("Invalid Option");
}

}

void sort()
{ int n;
   printf("\n\nEnter to Sort data of User or Airline(1/2) : ");
   scanf("%d",&n);
if(n==1)
{ struct User_data U;
 int a[20], c=0, i, j, t, n;
 FILE *f2;
 f2 = fopen("User Record", "r");
 while (fread(&U, sizeof(struct User_data), 1, f2))
 {
  a[c] = U.User_id;
  c++;
 }
 n = c;
 for (i=0;i<c - 1;i++)
 {
  for (j=i+1; j<c; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    
    a[i] = a[j];
    a[j] = t;
   }
  }
 }

 c = n;
 for (i=0; i<c; i++)
 {
  rewind(f2);
  while (fread(&U, sizeof(U), 1, f2))
  {
   if (a[i] == U.User_id)
   {
    printf("\nUser ID        : %d", U.User_id);
    printf("\nName           : %s", U.Name);
    printf("\nUser Address   : %s", U.Address);
    printf("\nMobile No      : %d", U.Mob);
    printf("\nDestination    : %s", U.dest);
    printf("\nBooking Class  : %s", U.Book_C);
    printf("\nPayment Mode   : %s", U.Payment_M);
   }

  }

 }
}
else if(n==2)
{
struct Airline_data A;
 int a[20], c=0, i, j, t, n;
 FILE *f2;
 f2 = fopen("Airline_data", "r");
 while (fread(&A, sizeof(struct Airline_data), 1, f2))
 {
  a[c] = A.Flight_no;
  c++;
 }
 n = c;
 for (i=0;i<c-1;i++)
 {
  for (j=i+1; j<c; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    
    a[i] = a[j];
    a[j] = t;
   }
  }
 }

 c = n;
 for (i=0; i<c; i++)
 {
  rewind(f2);
  while (fread(&A, sizeof(A), 1, f2))
  {
   if (a[i] == A.Flight_no)
   { 
     printf("Airline Flight No    : %d\n",A.Flight_no);
	 printf("Airline Flight Name  : %s\n",A.Flight_name);
	 printf("Flight Destination   : %s\n",A.destination);
	 printf("Flifgt Arrival Time  : %s\n",A.A_time);
	 printf("Flight Departure Time: %s\n",A.D_time);
     printf("Airline Flight Cost  : %f\n",A.cost);
     printf("\n");
   }

  }

 }
}
  else
  { printf("Invalid option");
  }
  }

int Login()
{ char ch,pass[10];    int i=0;
printf("\n\n************************** AIRLINE MANAGEMENT SYSTEM ***********************\n\n");

int n=1;

 while(n<=3)
 {printf("\nENTER YOUR USERNAME : ");
    scanf("%s",&username);

 printf("\nENTER YOUR PASSWORD : ");
 //scanf("%s",&password);
    int p=0;
    do{
    	password[p]=getch();
    	if(password[p]!='\r'){
    	printf("*");
	}
    p++;
}while(password[p-1]!='\r');
password[p-1]='\0';
    
 if(strcmp(username,"prime")==0){
	if(strcmp(password,"github")==0){

	printf("\n\n\t\t\t:-) Login Successful :-)\n\n");

	printf("\t\t....PRESS ENTER TO CONTINUE TO MAIN MENU.... \n\n");
	getch();
    Main_Menu();
    break;
 }


 else {

	printf("\n\n\t\tXXXX...WRONG PASSWORD ...XXXX\n");
	printf("\n\t    You have only %d chances left to login.\n",3-n);
	}
 }
else{
printf("\n\n\t\t\t*****User is not valid*****\n\n");
printf("\n\t\t  You have only %d chances left to login.\n",3-n); 
 }
n++;
 }
 printf("\n\n    Press Enter to Exit...  ");
 getch();
 return 0;
 }

int Main_Menu()
{
     int ch;
     while(1){

printf("\n\n___ MAIN MENU ___\n\n");
printf(" 1. Airline Data Entry\n 2. Airline Data Display\n 3. Airline Data Update\n 4. User data Entry\n 5. User Data Display\n 6. Search\n 7. Sort\n 8. Exit \n\n");
printf("Enter Your Choice:  ");
scanf("%d",&ch);
switch(ch)
{ case 1: Airline_Insert();
      break;
  case 2:  Airline_Display();
	  break;
  case 3: printf("Airline Update Module");
      break;
  case 4:   User_Insert();
	  break;
  case 5: User_Display();
	  break;
  case 6: search();
	  break;
  case 7: sort();
	  break;
  case 8:
	  printf("\n Thank You For Visiting Here....");
	  exit(0);
	  break;
 default: printf("Invalid Option");
	  break;
}}
return 0;
}

int main()
 {
       Login();
 }








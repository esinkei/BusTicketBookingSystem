#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
 void login()//login for admin access
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  +++++++++++++++BUS TICKET BOOKING SYSTEM  LOGIN  ++++++++++++++++++++++++++++++  ");
    printf(" \n\n                  ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\n                  ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getchar();//hold the screen while the pw is being typed
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR BUS TICKET BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");

}

//structure for our data storing purpose
struct book
{
	int rtno;
	char rtname[50];
	int cost;


}b;


void insert_details();
void viewAll();
void book_ticket();
void old_record();

void main()
{

	 int ch;
 	do{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n");
	printf("\t Bus Ticket Booking System ");
	printf("\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

	printf("\nEnter >1< To Insert Details of the available bus routes(Admin)");
   	printf("\nEnter >2< To View All Available Bus Routes");
	printf("\nEnter >3< To Book Tickets");
	printf("\nEnter >4< To View All Transactions");
   	printf("\nEnter >0< To Exit ");

   	printf("\nEnter your Choice ::");
   	scanf("%d",&ch);
	   system("cls");

   	switch (ch)
   	{
    	case 1 :
    	 	insert_details();
   		break;

		case 2:
    		viewAll();
   		break;

		case 3:
		book_ticket();
		break;

		case 4:
		old_record();
		break;

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);





}
//For inserting details of the new available roots.
void insert_details()
{
    login();

	FILE *fp;  //file pointer
	struct book b;   //book structure variable b declared
	printf("\nEnter the route no");
	scanf("%d",&b.rtno);
	printf("\nEnter the name of the route(Eg. Destination1-Destination2) :- ");
	scanf("%s",b.rtname);
	printf("\nEnter Ticket Price:- ");
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a");//append mode

	if(fp == NULL)
	{
		printf("FIle not Found");//error handling of the file
	}
	else
	{
		fprintf(fp,"%d %s %d \n",b.rtno,b.rtname,b.cost);
		printf("Recorded Successfully");
	}
		printf("\n");
	fclose(fp);
	system("cls");
}

void viewAll()
{

	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}

	fclose(fp);

}

void book_ticket()
{
 struct book b;

	FILE *fp;     //for pointing to data.txt

	FILE *ufp;    //for pointing to oldtransaction.txt

	int total_seat,mobile,total_amount;
	char name[50];


	char ch; //used in display all bus
	int rtnum; //for searching

	// disply all bus by default for bus code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);

	//display ends
	printf("\n For Booking ticket ,Choose the bus route\n");
	printf("\n Enter the bus route no :");
	scanf("%d",&rtnum);
	//system("clear");
	fp = fopen("data.txt","r");//read
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while(getc(fp) != EOF) //until we reach the end of file
		{
			fscanf(fp,"%d %s %d",&b.rtno,b.rtname,&b.cost);
			if(b.rtno==rtnum)
			{
				printf("\n Record Found \n");
				printf("\n\t\tBus Route Code ::%d",b.rtno);
				printf("\n\t\tRoute name ::%s",b.rtname);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}

	}
	printf("\n* Fill Details  *");
	printf("\n your name(Name_Surname) :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);


	total_amount = b.cost * total_seat;

	printf("\n ENJOY YOUR JOURNEY \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %d",mobile);
	printf("\n\t\tBus route  : %s",b.rtname);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);


	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.rtname,b.cost);
		printf("\n Record inserted Sucessfully to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);

}


//To view  old record of the the bus ticket system
void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");

	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);


}




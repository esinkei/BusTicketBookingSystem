#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

int landingpage();
int lanchoice=landingpage();
switch (lanchoice)
{
case 1:
	printf("You have chosen 1\n");
	int rat =purchase_ticket();
	printf("Your phone no is %d",rat);
	break;

case 2:
	printf("You have chosen 2\n");
	break;

case 3:
	printf("You have chosen 3\n");
	break;

case 4:
	printf("You have chosen 4\n");
	break;


case 5:
	printf("You have chosen 5\n");
	break;


default:
	printf("Wrong Input\n");
	break;
}

return 0;
}

int landingpage(void){
	int choice;
    printf("                 Bus Ticket Booing System                          \n");
	printf(" ==================================================================\n");
	printf("||             1- Purchase TICKET                                 ||\n");
	printf("||             2- Show booking history                            ||\n");
	printf("||             3- Cancel Ticket                                   ||\n");
	printf("||             4- Admin access                                    ||\n");
	printf("||             5- Exit system                                     ||\n");
	printf("||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}

int purchase_ticket(void){
	int phno;
	printf("Enter your phone no.\n");
	scanf("%d",&phno);

	return phno;
}

void show_booking_history(void){


}

void cancel_ticket(){

}

void adminaccess(){

}

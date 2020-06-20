#include <stdio.h>

#include <string.h>
#include <stdlib.h>


int main(){

landingpage();


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

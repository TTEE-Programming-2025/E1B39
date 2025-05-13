#include <stdio.h> 
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <time.h>   
#include <string.h> 
int main(void)
{
	//Personal style picture
	printf("--------------------------------------------------\n");
	printf("|            ¡@¡@¡@¡@ ¡@¡@  ¡Ä¡Ä¡Ä               |\n");
    printf("|             ¡@¡@¡@ ¡@¡@¡þ¡Ö¡@¡@  ¡Ö            |\n");
    printf("|            ¡@ ¡@¡@ ¡@¡@| ¡@_¡@ _ l             |\n");
    printf("|             ¡@ ¡@¡@ ¡@¡þ`  ¡Äx¡Ä /             |\n");
    printf("|            ¡@ ¡@ ¡@ /¡@¡@¡@ ¡@  |              |\n");
    printf("|             ¡@¡@¡@ /¡@ \\¡@ ¡@  /               |\n");
    printf("|                   ¢x¡@¡@ |¡@|  |                |\n");
    printf("|             ¡@¡þ¡Ã|¡@¡@ |¡@|¡@|                |\n");
    printf("|             ¡@| (¡Ã\\¡Ä_ ¢@__)__)               |\n");
    printf("|             ¡@¢@¤G¡^                           |\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|               I have a cat here.               |\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|  Please enter a 4-digit password to continue.  |\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|               made by:   E1B39                 |\n");
	printf("|                          ÂÅ­§´Å                |\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("--------------------------------------------------\n");
	
	
	//Request password
	int ps,cps=2025,wrong = 0;//The correct password is 2025

    while (wrong < 3) {
		printf("Please enter a 4-digit password:\n");
		printf("--->");
		scanf("%d", &ps); 
		
		if (ps==cps) { 
			break; // Password is correct. Exit the loop.
		}else { 
			printf("\nWrong password! Please re-enter\n\n");
			wrong++;
		}
	}
	
	if (wrong == 3) {
		printf("Wrong password entered three times! Program ends!\n");
		printf("\a"); //Warning sound
		return 1;
	}
 
	
	// Below is the main menu cycle
    char choice;
    int run = 1;

    while (run)// End when run=0
    {
        system("cls"); 
    	printf("----------[Booking System]----------\n");
    	printf("| a. Available seats               |\n");
    	printf("| b. Arrange for you               |\n");
    	printf("| c. Choose by yourself            |\n");
    	printf("| d. Exit                          |\n");
    	printf("------------------------------------\n");
    	printf("Tips¡G\n");
		printf("Please enter a or b or c or d to continue:\n");
		printf("--->");
		
		fflush(stdin);
        choice = getch();
        choice = tolower(choice);
        printf("%c\n", choice);
        
        switch (choice)
        {
            case 'a':
            {
            	
            }
            case 'b':
            {
            	
            }
            case 'c':
            {
            	
            }
            case 'd':
            {
            	char confirm;
				while(1) {
                        printf("Continue? (y/n): ");
                        confirm = tolower(getch());
                        printf("%c\n", confirm);
                        
                        if(confirm == 'n') {
                            printf("Exiting program...\n");
                            return 0; // Program ends
                        } 
                        else if(confirm == 'y') {
                            break; // Exit this loop and return to the main menu
                        } 
                        else {
                            printf("Invalid input! ");
                        }
                    }
                break;
            }
            default:
            {
                printf("Invalid option, please re-enter.\n");
                system("pause");
                break;
            }
        }
    }

    return 0;
}


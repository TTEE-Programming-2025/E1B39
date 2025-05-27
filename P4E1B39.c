#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{	
	
	//Personal style picture
	printf("--------------------------------------------------\n");
	printf("|            　　　　 　　  ＿＿＿               |\n");
    printf("|             　　　 　　／＞　　  ＞            |\n");
    printf("|            　 　　 　　| 　_　 _ l             |\n");
    printf("|             　 　　 　／`  ＿x＿ /             |\n");
    printf("|            　 　 　 /　　　 　  |              |\n");
    printf("|             　　　 /　 \\　 　  /               |\n");
    printf("|                   │　　 |　|  |                |\n");
    printf("|             　／￣|　　 |　|　|                |\n");
    printf("|             　| (￣\\＿_ ＼__)__)               |\n");
    printf("|             　＼二）                           |\n");
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
	printf("|                          藍郁棠                |\n");
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
	
	printf("歡迎\nPress any key to continue...");
    getch();
    
	// Below is the main menu cycle
    char choice;
    while (1) {
        system("cls");
        printf("------------[Grade System]------------\n");
        printf("|  a. Enter student grades           |\n");
        printf("|  b. Display student grades         |\n");
        printf("|  c. Search for student grades      |\n");
        printf("|  d. Grade ranking                  |\n");
        printf("|  e. Exit system                    |\n");
        printf("--------------------------------------\n");
        printf("Tips：\n");
		printf("Please enter a or b or c or d or e to continue:\n");
		printf("--->");
		
		fflush(stdin);
        choice = getch();
        choice = tolower(choice);
        printf("%c\n", choice);

        switch (choice) {
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e': 
			{
                char confirm;
				while(1) {
                        printf("確定離開？ (y/n): ");
                        confirm = tolower(getch());
                        printf("%c\n", confirm);
                        
                        if(confirm == 'y') {
                            printf("Exiting program...\n");
                            return 0; // Program ends
                        } 
                        else if(confirm == 'n') {
                            break; // Exit this loop and return to the main menu
                        } 
                        else {
                            printf("Invalid input! \n");
                        }
                    }
                break;
            }
            default:
            {
                printf("Invalid option, please re-enter.\n");
                printf("Press any key to return to menu...\n");
                getch();
                break;
            }
        }
    }
    return 0;
}


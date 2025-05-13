#include <stdio.h> 
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <time.h>   
#include <string.h> 

#define SIZE 9

char seats[SIZE][SIZE];     // ��e�y�쪬�A
int i,j; 

void Seats() {
    // Step 1: ������l�Ƭ��Ŧ� '-'

    for (i=0; i < SIZE; i++) {
        for (j=0; j < SIZE; j++) {
            seats[i][j] = '-';
        }
    }

    // Step 2: �H���ͦ�10�� '*'�]�w�w�q�y��^
    int count = 0;
    while (count < 10) {
        // �ͦ��H����M�C�]�d��G0~8�^
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        // �ˬd�O�_�w�Q����
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            count++; // ���\�]�m��p��
        }
    }
}

void displaySeats() {
	
    printf("\\123456789\n");  // �C�L�C��
    for (i=0; i<SIZE; i++) {
        printf("%d", SIZE-i);  // �渹�q9��1
        for (j=0; j<SIZE; j++)
            printf("%c", seats[i][j]);
        printf("\n");
    }
}

void Arrange() {
    int need;
    printf("How many seats do you need (1-4)? ");
    scanf("%d", &need);

    int placed = 0;
    for (i = 0; i < SIZE && !placed; i++) {
        for (j = 0; j <= SIZE - need; j++) {
            int ok = 1;
            int k;
            for (k = 0; k < need; k++) {
                if (seats[i][j + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (k = 0; k < need; k++)
                    seats[i][j + k] = '@';
                placed = 1;
                break;
            }
        }
    }

    if (!placed && need == 4) {
        for (i = 0; i < SIZE - 1 && !placed; i++) {
            for (j = 0; j < SIZE; j++) {
                if (seats[i][j] == '-' && seats[i + 1][j] == '-') {
                    seats[i][j] = seats[i + 1][j] = '@';
                    seats[i][(j + 1) % SIZE] = seats[i + 1][(j + 1) % SIZE] = '@';
                    placed = 1;
                    break;
                }
            }
        }
    }

    displaySeats();
    printf("Are you satisfied? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response == 'y') {
        for (i = 0; i < SIZE; i++)
            for (j = 0; j < SIZE; j++)
                if (seats[i][j] == '@') seats[i][j] = '*';
    } else {
        for (i = 0; i < SIZE; i++)
            for (j = 0; j < SIZE; j++)
                if (seats[i][j] == '@') seats[i][j] = '-';
    }
}

int main(void)
{	
	srand(time(NULL));
	//Personal style picture
	printf("--------------------------------------------------\n");
	printf("|            �@�@�@�@ �@�@  �ġġ�               |\n");
    printf("|             �@�@�@ �@�@���֡@�@  ��            |\n");
    printf("|            �@ �@�@ �@�@| �@_�@ _ l             |\n");
    printf("|             �@ �@�@ �@��`  ��x�� /             |\n");
    printf("|            �@ �@ �@ /�@�@�@ �@  |              |\n");
    printf("|             �@�@�@ /�@ \\�@ �@  /               |\n");
    printf("|                   �x�@�@ |�@|  |                |\n");
    printf("|             �@����|�@�@ |�@|�@|                |\n");
    printf("|             �@| (��\\��_ �@__)__)               |\n");
    printf("|             �@�@�G�^                           |\n");
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
	printf("|                          �ŭ���                |\n");
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
	Seats(); 
    while (run)// End when run=0
    {
        system("cls"); 
    	printf("----------[Booking System]----------\n");
    	printf("| a. Available seats               |\n");
    	printf("| b. Arrange for you               |\n");
    	printf("| c. Choose by yourself            |\n");
    	printf("| d. Exit                          |\n");
    	printf("------------------------------------\n");
    	printf("Tips�G\n");
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
            	displaySeats();
            	printf("Press any key to return to menu...\n");
    			getch();
				break; 
            }
            case 'b':
            {
            	Arrange();
            	break;
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
/*�p�Ӹ`�`�`���� debug ����Y�h*/

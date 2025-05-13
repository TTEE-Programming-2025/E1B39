#include <stdio.h> 
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <time.h>   
#include <string.h> 

#define SIZE 9

char seats[SIZE][SIZE];     // 當前座位狀態
int i,j; 

void Seats() {
    // Step 1: 全部初始化為空位 '-'

    for (i=0; i < SIZE; i++) {
        for (j=0; j < SIZE; j++) {
            seats[i][j] = '-';
        }
    }

    // Step 2: 隨機生成10個 '*'（已預訂座位）
    int count = 0;
    while (count < 10) {
        // 生成隨機行和列（範圍：0~8）
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        // 檢查是否已被佔用
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            count++; // 成功設置後計數
        }
    }
}

void displaySeats() {
	
    printf("\\123456789\n");  // 列印列號
    for (i=0; i<SIZE; i++) {
        printf("%d", SIZE-i);  // 行號從9到1
        for (j=0; j<SIZE; j++)
            printf("%c", seats[i][j]);
        printf("\n");
    }
}


int main(void)
{	
	srand(time(NULL));
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
    	printf("Tips：\n");
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
/*小細節常常讓我 debug 到很頭痛*/

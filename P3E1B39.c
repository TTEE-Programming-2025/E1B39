#include <stdio.h> 
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
int main(void)
{
	//�ӤH���檺�e��
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
 
	
	// �H�U�O�D���`��
    char choice;
    int run = 1;

    while (run)// run=0 �ɵ��� 
    {
        system("cls"); // �C�����s��ܰ��b�����
		//�i�o�]�p�F������ҥH��d�Ҥ@�Ҥ@�� 
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
            	
            }
            case 'b':
            {
            	
            }
            case 'c':
            {
            	
            }
            case 'd':
            {
                run = 0;// When run=0, the while (run) loop ends.
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

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

// �ǥ͵��c��w�q
struct Student {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
};

// �����ܼ�
struct Student students[10]; // �̦h�s10�Ӿǥ�
int student_count = 0;        // ��e�ǥͼƶq

// �禡�ŧi
void enter_grades();
void display_grades();

int main(void)
{	
	
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
	
	printf("�w��\nPress any key to continue...");
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
        printf("Tips�G\n");
		printf("Please enter a or b or c or d or e to continue:\n");
		printf("--->");
		
		fflush(stdin);
        choice = getch();
        choice = tolower(choice);
        printf("%c\n", choice);

        switch (choice) {
            case 'a':
                enter_grades();
                break;
            case 'b':
                display_grades();
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e': 
			{
                char confirm;
				while(1) {
                        printf("�T�w���}�H (y/n): ");
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

// �\��禡��{-------------------------------------------------
void enter_grades() {
    system("cls");
    printf("=== ��J�ǥ͸�� ===\n");
    
    // ��J�ǥͤH��
    int n;
	while (1) 
	{
    	printf("�п�J�ǥͤH��(5-10): ");
    
    	// �ˬd��J�O�_�����ļƦr
    	if (scanf("%d", &n) != 1) 
		{
        	// �M�ſ�J�w�İ�
        	while(getchar() != '\n'); 
        	printf("���~�I�п�J�Ʀr\n");
        	continue;
    	}
    
    	// ���ҼƦr�d��
    	if (n >=5 && n <=10) 
		{
        	break; // ��J���T�A�h�X�j��
    	} else {
        printf("�H�ƽd����~�I�п�J5-10�������Ʀr\n");
    	}
	}

    // ��J�ǥ͸��
    int i=0; 
    for (i=0; i<n; i++) {
        printf("\n�ǥ� #%d\n", i+1);
        
        // ��J�m�W
        printf("�m�W: ");
        while(getchar() != '\n'); // �M�ſ�J�w��
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // �h�������

        // ��J�Ǹ�
        while (1) {
            printf("�Ǹ�(6���): ");
            scanf("%d", &students[i].id);
            if (students[i].id >= 100000 && students[i].id <= 999999) break;
            printf("�Ǹ������O6��Ʀr�I\n");
        }

        // ��J���Z
        while (1) {
            printf("�ƾǦ��Z(0-100): ");
            scanf("%d", &students[i].math);
            if (students[i].math >=0 && students[i].math <=100) break;
            printf("���ƽd����~�I\n");
        }
        while (1) {
            printf("���z���Z(0-100): ");
            scanf("%d", &students[i].physics);
            if (students[i].math >=0 && students[i].math <=100) break;
            printf("���ƽd����~�I\n");
        }
        while (1) {
            printf("�^�妨�Z(0-100): ");
            scanf("%d", &students[i].english);
            if (students[i].math >=0 && students[i].math <=100) break;
            printf("���ƽd����~�I\n");
        }
        
        // �p�⥭��
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
    student_count = n;
    printf("\n��ƿ�J�����IPress any key to return to menu...\n");
    getch();
}

void display_grades() {
    system("cls");
    printf("=== ��ܩҦ��ǥͦ��Z ===\n");
    
    if (student_count == 0) {
        printf("�|�L��ơI\n");
    } else {
    	int i=0;
        for (i=0; i<student_count; i++) {
            printf("\n�m�W: %s\n", students[i].name);
            printf("�Ǹ�: %d\n", students[i].id);
            printf("�ƾ�: %d\t���z: %d\t�^�y: %d\n", 
                students[i].math, students[i].physics, students[i].english);
            printf("����: %.1f\n", students[i].average);
        }
    }
    printf("\nPress any key to return to menu...");
    getch();
}


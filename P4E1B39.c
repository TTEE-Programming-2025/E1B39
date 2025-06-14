#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

// 學生結構體定義
struct Student {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
};

// 全局變數
struct Student students[10]; // 最多存10個學生
int student_count = 0;        // 當前學生數量

// 函式宣告
void enter_grades();
void display_grades();
void search_grades();
void grade_ranking();
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
                enter_grades();
                break;
            case 'b':
                display_grades();
                break;
            case 'c':
                search_grades();
                break;
            case 'd':
                grade_ranking();
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

// 功能函式實現-------------------------------------------------
void enter_grades() {
    system("cls");
    printf("=== 輸入學生資料 ===\n");
    
    // 輸入學生人數
    int n;
	while (1) 
	{
    	printf("請輸入學生人數(5-10): ");
    
    	// 檢查輸入是否為有效數字
    	if (scanf("%d", &n) != 1) 
		{
        	// 清空輸入緩衝區
        	while(getchar() != '\n'); 
        	printf("錯誤！請輸入數字\n");
        	continue;
    	}
    
    	// 驗證數字範圍
    	if (n >=5 && n <=10) 
		{
        	break; // 輸入正確，退出迴圈
    	} else {
        printf("人數範圍錯誤！請輸入5-10之間的數字\n");
    	}
	}

    // 輸入學生資料
    int i=0; 
    for (i=0; i<n; i++) {
        printf("\n學生 #%d\n", i+1);
        
        // 輸入姓名
        printf("姓名: ");
        while(getchar() != '\n'); // 清空輸入緩衝
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // 去除換行符

        // 輸入學號
        while (1) {
            printf("學號(6位數): ");
            scanf("%d", &students[i].id);
            if (students[i].id >= 100000 && students[i].id <= 999999) break;
            printf("學號必須是6位數字！\n");
        }

        // 輸入成績
        while (1) {
            printf("數學成績(0-100): ");
            scanf("%d", &students[i].math);
            if (students[i].math >=0 && students[i].math <=100) break;
            printf("分數範圍錯誤！\n");
        }
        while (1) {
            printf("物理成績(0-100): ");
            scanf("%d", &students[i].physics);
            if (students[i].math >=0 && students[i].math <=100) break;
            printf("分數範圍錯誤！\n");
        }
        while (1) {
            printf("英文成績(0-100): ");
            scanf("%d", &students[i].english);
            if (students[i].math >=0 && students[i].math <=100) break;
            printf("分數範圍錯誤！\n");
        }
        
        // 計算平均
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
    student_count = n;
    printf("\n資料輸入完成！Press any key to return to menu...\n");
    getch();
}

void display_grades() {
    system("cls");
    printf("=== 顯示所有學生成績 ===\n");
    
    if (student_count == 0) {
        printf("尚無資料！\n");
    } else {
    	int i=0;
        for (i=0; i<student_count; i++) {
            printf("\n姓名: %s\n", students[i].name);
            printf("學號: %d\n", students[i].id);
            printf("數學: %d\t物理: %d\t英語: %d\n", 
                students[i].math, students[i].physics, students[i].english);
            printf("平均: %.1f\n", students[i].average);
        }
    }
    printf("\nPress any key to return to menu...");
    getch();
}
void search_grades() 
{
	char searchName[50];
    int found = 0;
    system("cls");
    printf("=== 搜尋學生資料 ===\n");
    printf("請輸入要搜尋的姓名：\n");
    scanf("%s", searchName);
    int i=0;
    for (i = 0; i < student_count; i++) 
	{
        if (strcmp(searchName, students[i].name) == 0) 
		{
            printf("\n找到學生資料：\n");
            printf("姓名: %s\n", students[i].name);
            printf("學號: %d\n", students[i].id);
            printf("數學: %d\n物理: %d\n英文: %d\n平均: %.1f\n",students[i].math, students[i].physics,students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("\n找不到姓名為 %s 的學生\n",searchName);
    }

    printf("\nPress any key to return to menu...");
    getch();
}

void grade_ranking() 
{
    system("cls");
    printf("=== 成績排名 ===\n");
    
    if (student_count == 0) 
	{
        printf("尚無資料可排序！\n");
        getch();
        return;
    }

    
    int i=0;
    for(i=0; i<student_count-1; i++) 
	{
    	int j=0;
        for(j=0; j<student_count-i-1; j++) 
		{
            if(students[j].average < students[j+1].average) 
			{
                // 交換結構體內容
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }

    // 顯示排序結果
    printf("排名\t姓名\t\t學號\t平均成績\n");

    for(i=0; i<student_count; i++) 
	{
        printf("%d\t%-10s\t%d\t%.1f\n", 
              i+1, students[i].name, students[i].id, students[i].average);
    }

    printf("\nPress any key to return to menu...");
    getch();
}
/*=============================================
			程式設計心得與說明
	檔案名稱：P4E1B39.c
	開發者：藍郁棠 (E1B39)
	最後更新日期：2025/05/27
=============================================*/
/*
本次實作讓我深刻體會到：
1. 模組化設計的重要性：將功能拆分成函式後，除錯效率大幅提升
2. 結構體的強大：相較於多個獨立陣列，結構體讓資料管理更直覺
3. 善用printf()進行除錯
4. 各種除不完的bug
5. 寫程式必須休養身心靈 
*/


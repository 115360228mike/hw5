// hw6.19.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 36000

int main(void) {
    int count[13] = { 0 };
    int die1, die2, sum;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < ROLLS; i++) {
        die1 = 1 + rand() % 6;
        die2 = 1 + rand() % 6;
        sum = die1 + die2;
        count[sum]++;
    }

    printf("%s%12s%14s\n", "點數和", "出現次數", "期望次數");
    for (int s = 2; s <= 12; s++) {
        int ways = (s <= 7) ? (s - 1) : (13 - s);
        double expected = (double)ROLLS * ways / 36.0;
        printf("%4d%14d%16.1f\n", s, count[s], expected);
    }

    printf("\n7 點合理性檢查：\n");
    printf("7 點實際出現次數：%d（約佔 %d 次投擲的 %.2f%%）\n",
        count[7], ROLLS, (double)count[7] * 100.0 / ROLLS);
    printf("7 點理論期望次數（1/6）：%d\n", ROLLS / 6);
    system("pause");
    return 0;
}
// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

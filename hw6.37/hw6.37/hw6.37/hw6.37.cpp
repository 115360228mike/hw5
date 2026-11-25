// hw6.37.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int recursiveMaximum(const int a[], int size);

int main(void) {
    int values[100]={0};
    int count = 0;
	printf("請輸入一串整數（例如 20 50 100），結束請輸入非數字或按 Ctrl+Z：\n");
    while (count < 100 && scanf("%d", &values[count]) == 1) {
        count++;
    }
    int size = sizeof(values) / sizeof(values[0]);
    printf("Maximum value: %d\n", recursiveMaximum(values, size));
    system("pause");
    return 0;
}

int recursiveMaximum(const int a[], int size) {
    int maxOfRest;

    if (size == 1) {
        return a[0];
    }

    maxOfRest = recursiveMaximum(a, size - 1);
    return (a[size - 1] > maxOfRest) ? a[size - 1] : maxOfRest;
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

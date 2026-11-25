// hw6.33.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define SIZE 15

int binarySearch(const int b[], int low, int high, int searchKey);

int main(void) {
    int a[SIZE];
    int searchKey, result;

    for (int i = 0; i < SIZE; i++) {
        a[i] = 2 * i;
    }

    printf("Enter an integer search key: ");
    if (scanf("%d", &searchKey) != 1) {
        return 1;
    }

    result = binarySearch(a, 0, SIZE - 1, searchKey);

    if (result != -1) {
        printf("Found value at index %d\n", result);
    }
    else {
        printf("Value not found\n");
    }
    system("pause");
    return 0;
}

int binarySearch(const int b[], int low, int high, int searchKey) {
    int middle;

    if (low > high) {
        return -1;
    }

    middle =  (high +low) / 2;

    if (searchKey == b[middle]) {
        return middle;
    }
    else if (searchKey < b[middle]) {
        return binarySearch(b, low, middle - 1, searchKey);
    }
    else {
        return binarySearch(b, middle + 1, high, searchKey);
    }
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

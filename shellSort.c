#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 配列の要素を表示する関数
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// シェルソートを行う関数
void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    printf("ソート前の配列: ");
    printArray(arr, n);

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        printf("ギャップ %d の間隔でのソート結果: ", gap);
        printArray(arr, n);
    }
}

// ユーザー入力を受け取り、配列に格納する関数
void getInputArray(int arr[], int *count) {
    char input[100];
    printf("カンマ区切りの数値列を入力してください: ");
    fgets(input, sizeof(input), stdin);

    // 改行文字を削除
    input[strcspn(input, "\n")] = 0;

    // カンマで区切られた数値を抽出して配列に格納
    char *token = strtok(input, ",");
    while (token != NULL) {
        arr[(*count)++] = atoi(token);
        token = strtok(NULL, ",");
    }
}

int main() {
    int arr[50]; // 最大50個の要素を扱うことを想定
    int count = 0;

    // ユーザーからの入力を処理
    getInputArray(arr, &count);

    // シェルソートの実行
    shellSort(arr, count);

    // 最終的なソート結果を表示
    printf("最終的なソート結果: ");
    printArray(arr, count);

    return 0;
}

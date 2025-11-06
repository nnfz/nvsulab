#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

#define LO 40
#define HI 150

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n, i, j;
    int **a;
    srand(time(NULL));

    wprintf(L"Введите размер массива: ");
    scanf("%d", &n);
    
    a = (int **)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++){
        a[i] = (int *)malloc(n * sizeof(int));
    }

    wprintf(L"\nИсходный массив: [\n");
    int min_val = HI + 1;
    int min_r = 0, min_c = 0;
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            a[i][j] = LO + rand() % (HI - LO + 1);
            printf("%-4d ", a[i][j]);
            
            if(a[i][j] < min_val){
                min_val = a[i][j];
                min_r = i;
                min_c = j;
            }
        }
        printf("\n");
    }
    printf("]\n");

    wprintf(L"\nМинимальный элемент: %d на [%d][%d]\n", min_val, min_r, min_c);

    for (int k = 0; k < n; k++) {
        int temp = a[min_r][k];
        a[min_r][k] = a[k][min_c];
        a[k][min_c] = temp;
    }

    wprintf(L"Результат: [\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%-4d", a[i][j]);
        }
        printf("\n");
    }
    printf("]\n");

    for(i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
    
    system("pause");
    return 0;
}
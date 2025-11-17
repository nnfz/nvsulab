#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

#include "mymod.h"

#define LO -100
#define HI  100

int main() {
    setlocale(LC_ALL, "");
    int n, i, p, r;
    int *a;
    srand(time(NULL));
    
    wprintf(L"Длина массива: ");
    scanf("%d", &n);
    
    a = (int *)malloc(n * sizeof(int));
    if (!a) {
        wprintf(L"Ошибка выделения памяти\n");
        return 1;
    }

    wprintf(L"Исходный массив: [");
    for(i = 0; i < n; i++) {
        a[i] = LO + rand() % (HI - LO + 1);
        if(i < n - 1) {
            printf("%d, ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("]\n");

    wprintf(L"Кол-во элементов: ");
    scanf("%d", &p);
    
    wprintf(L"На что умножаем: ");
    scanf("%d", &r);

    ma(a, p, r);

    wprintf(L"Результат: [");
    for(i = 0; i < n; i++) {
        if(i < n - 1) {
            printf("%d, ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("]\n");

    free(a);
    system("pause");
    return 0;
}

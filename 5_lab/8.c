#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LO -100
#define HI  100

void ma(int *a, int p, int r) {
    for(int i = 0; i < p; i++) {
        a[i] = a[i] * r;
    }
}

int main() {
    int n, i, p, r;
    int *a;
    srand(time(NULL));
    
    printf("Длина массива: ");
    scanf("%d", &n);
    
    a = (int *)malloc(n * sizeof(int));

    printf("Исходный массив: [");
    for(i = 0; i < n; i++) {
        a[i] = LO + rand() % (HI - LO + 1);
        if(i < n - 1) {
            printf("%d, ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("]\n");

    printf("Кол-во элементов: ");
    scanf("%d", &p);
    
    printf("На что умножаем: ");
    scanf("%d", &r);

    ma(a, p, r);

    printf("Результат: [");
    for(i = 0; i < n; i++) {
        if(i < n - 1) {
            printf("%d, ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("]\n");

    free(a);
    return 0;
}
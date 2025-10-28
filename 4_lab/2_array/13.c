#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LO 40
#define HI 150

int main() {
    int r, c, i, p;
    int **a;
    srand(time(NULL));

    printf("Колво строк: ");
    scanf("%d", &r);
    printf("Колво столбцов: ");
    scanf("%d", &c);
    if(r == c){
        printf("Колво столбцов (прямоугольная): %d + 1\n", c);
        c += 1;
    }

    a = (int **)malloc(r * sizeof(int*));
    for(i = 0; i < r; i++){
        a[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Исходный массив: [\n");
    for(i = 0; i < r; i++) {
        for(p = 0; p < c; p++) {
            a[i][p] = LO + rand() % (HI - LO + 1);
            printf("%3d ", a[i][p]);
        }
        printf("\n");
    }
    printf("]\n");

    int s_min, s_max;
    int min_index, max_index;
    int *sums;

    sums = (int *)malloc(r * sizeof(int));

    for(i = 0; i < r; i++){
        for(p = 0; p < c; p++) {
            sums[i] += a[i][p];
        }
    }

    for(i = 1; i < r; i++){
        if(sums[i] < s_min) {
            s_min = sums[i];
            min_index = i;
        }
        if(sums[i] > s_max) {
            s_max = sums[i];
            max_index = i;
        }
    }

    printf("\nСтрока с мин суммой (%d): [", s_min);
    for(p = 0; p < c; p++) {
        printf("%d", a[min_index][p]);
        if(p < c - 1) printf(", ");
    }
    printf("]\n");

    printf("Строка с макс суммой (%d): [", s_max);
    for(p = 0; p < c; p++) {
        printf("%d", a[max_index][p]);
        if(p < c - 1) printf(", ");
    }
    printf("]\n");

    free(sums);
    for(i = 0; i < r; i++){
        free(a[i]);
    }
    free(a);

    return 0;
}
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
    
    int min_i = 0, min_p = 0, min_v = a[0][0];
    for(i = 0; i < r; i++){
        for(p = 0; p < c; p++){
            if(a[i][p] < min_v){
                min_v = a[i][p];
                min_i = i;
                min_p = p;
            }
        }
    }

    printf("Мин элемент %d, вот тут [%d][%d] \n", min_v, min_i, min_p);

    int **result = (int **)malloc(r * sizeof(int*));
    for(i = 0; i < r; i++){
        result[i] = (int *)malloc(c * sizeof(int));
    }
    
    for(i = 0; i < r; i++) {
        for(p = 0; p < c; p++) {
            result[i][p] = a[i][p];
        }
    }
    
    for(p = 0; p < c; p++) {
        if(p < r) {  
            result[min_i][p] = a[p][min_p];
        }
    }
    
    for(i = 0; i < r; i++) {
        if(i < c) {  
            result[i][min_p] = a[min_i][i];
        }
    }

    printf("Результат: [\n");
    for(i = 0; i < r; i++) {
        for(p = 0; p < c; p++) {
            printf("%3d ", result[i][p]);
        }
        printf("\n");
    }
    printf("]\n");

    for(i = 0; i < r; i++){
        free(a[i]);
        free(result[i]);
    }
    free(a);
    free(result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Длина гадостей
#define LO -100
#define HI  100

int main() {
    int n, i, s = 0;
    int *a;
    int *c;
    srand(time(NULL));
    
    printf("Длина массва: ");
    scanf("%d", &n);
    
    a = (int *)malloc(n*sizeof(int));
    
    printf("Исходный массив: [");
    for(i = 0; i < n; i++){
        a[i] = LO + rand() % (HI - LO + 1);
        if(i < n - 1){
            printf("%d, ", a[i]);
        }else{
            printf("%d", a[i]);
        }
    }
    printf("] \n");

    if(n > 0){
        for(i = 1; i < n; i++){
            if(a[i - 1] < 0 && a[i] > 0){
                s++;
            }else if(a[i - 1] > 0 && a[i] < 0){
                s++;
            }
        }
        
    }

    c = (int *)malloc(s*sizeof(int));

    int o = 0;
    if(n > 0){
        for(i = 1; i < n; i++){
            if(a[i - 1] < 0 && a[i] > 0){
                c[o] = i;
                o++;
            }else if(a[i - 1] > 0 && a[i] < 0){
                c[o] = i;
                o++;
            }
        }
        
    }
    
    printf("Результат: [");
    for(i = 0; i < s; i++){
        if(i < s - 1){
            printf("%d, ", c[i]);
        }else{
            printf("%d", c[i]);
        }
    }
    printf("] \n");

    free(a);
    free(c);
    
    return 0;
}
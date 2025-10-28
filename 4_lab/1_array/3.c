#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Длина гадостей
#define LO -100
#define HI  100

int main() {
    int n, i;
    int *a;
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
    
    int max = 0, min = 0;
    for(i = 1; i < n; i++){
        if(a[i] > a[max]){
            max = i;
        }
        if(a[i] < a[min]){
            min = i;
        }
    }
    
    int l = (min < max) ? min : max;
    int r = (min > max) ? min : max;
    int k = r - l - 1;
    if(k > 0){        
        for(i = r; i < n; i++){
            a[i - k] = a[i];
        }
        n -= k;
    }
    
    printf("Резултат: [");
    for(i = 0; i < n; i++){
        if(i < n - 1){
            printf("%d, ", a[i]);
        }else{
            printf("%d", a[i]);
        }
    }
    printf("]");
    
    free(a);
    return 0;
}
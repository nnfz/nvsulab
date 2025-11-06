#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

// Длина гадостей
#define LO -100
#define HI  100

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n, i;
    int *a;
    srand(time(NULL));
    
    wprintf(L"Длина массва: ");
    scanf("%d", &n);
    
    a = (int *)malloc(n*sizeof(int));
    
    wprintf(L"Исходный массив: [");
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
    
    wprintf(L"Резултат: [");
    for(i = 0; i < n; i++){
        if(i < n - 1){
            printf("%d, ", a[i]);
        }else{
            printf("%d", a[i]);
        }
    }
    printf("]\n");
    system("pause");
    free(a);
    return 0;
}
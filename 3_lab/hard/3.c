#include <stdio.h>

void main()
{
    long n = 0;
    printf("Введите число: ");
    scanf("%ld", &n);
    
    printf("Простые множители числа %ld: ", n);
    
    while(n % 2 == 0){
        n /= 2;
        printf("2 ");
    }
    
    for(long a = 3; a * a <= n; a += 2){
        if (n % a == 0){
            n /= a;
            printf("%ld ", a);
        }
    }
    
    if(n > 2){
        printf("%ld", n);
    }
    
}

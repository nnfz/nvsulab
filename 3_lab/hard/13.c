#include <stdio.h>

void main()
{
    int n = 0;
    printf("Введите двузначное число: ");
    scanf("%d", &n);
    
    printf("Четырехзначные числа начинающиеся на %d: ", n);
    
    for(int a = 0; a <= 99; a++){
        printf("%d%02d ", n, a);
    }
    printf("\n");
    
    printf("Четырехзначные числа заканчивающиеся на %d: ", n);
    for(int a = 10; a <= 99; a++){
        printf("%d%02d ", a, n);
    }
}

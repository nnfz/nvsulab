#include <stdio.h>

void main()
{
    float a, b;
    printf("Введите 2 числа: ");
    scanf("%f %f", &a, &b);
    if (a>b){
        printf("Первое число: %f", a);
    }else{
        printf("Оба числа: %f %f", a, b);
    }
}
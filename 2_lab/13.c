#include <stdio.h>
#include <stdlib.h>

void main()
{
    float a, b;
    printf("Введите 2 числа: ");
    scanf("%f %f", &a, &b);
    if (abs(a)>abs(b)){
        a /= 5;
        printf("Результат: a / 4 = %f b = %f", a, b);
    }else{
        printf("Результат: a = %f b = %f", a, b);
    }
}
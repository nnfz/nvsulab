#include <stdio.h>
#include <math.h>

void main()
{
    int a, b;
    long sum = 0;
    printf("Введите 2 целых числа: ");
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++){
        sum += i;
    }
    printf("Сумма всех чисел = %ld", sum);
}
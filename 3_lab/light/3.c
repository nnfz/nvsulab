#include <stdio.h>
#include <stdlib.h>

void main()
{
    float m, n;
    long sum = 0;
    printf("Введите 2 числа: ");
    scanf("%f %f", &m, &n);
    for (int i = m; i <= n; i++){
        if (i % 2 == 0){
            sum += i*i;
        }
    }
    printf("Сумма: %ld", sum);
}

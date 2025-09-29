#include <stdio.h>
#include <stdlib.h>

void main()
{
    float a, b, c;
    printf("Введите числа a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a > b && b > c){
        a *= 3;
        b *= 3;
        c *= 3;
    }else{
        a = abs(a);
        b = abs(b);
        c = abs(c);
    }
    printf("Числа: a = %f, b = %f, c = %f", a, b, c);
}
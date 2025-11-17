#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include "mymod.h"

int main(){
    setlocale(LC_ALL, "");
    int n;

    wprintf(L"Введите число: ");
    scanf("%d", &n);

    wprintf(L"Факториал числа %d!: %lld\n", n, fac(n));
    system("pause");
    return 0;
}

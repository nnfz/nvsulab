#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

long long fac(int n){
    int i;
    long long r = 1;

    for(i = 1; i <= n; i++){
        r = r * i;
    }

    return r;
}

int main(){
    setlocale(LC_ALL, "");
    int n;

    wprintf(L"Введите чсло: ");
    scanf("%d", &n);

    wprintf(L"Факториал числа %d!: %d\n", n, fac(n));
    system("pause");
    return 0;
}
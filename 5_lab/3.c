#include <stdio.h>

long long fac(int n){
    int i;
    long long r = 1;

    for(i = 1; i <= n; i++){
        r = r * i;
    }

    return r;
}

int main(){
    int n;

    printf("Введите чсло: ");
    scanf("%d", &n);

    printf("Факториал числа %d!: %d", n, fac(n));

    return 0;
}
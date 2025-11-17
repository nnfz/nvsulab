#include "mymod.h"
#include <wctype.h>   // для towlower

long long fac(int n){
    int i;
    long long r = 1;

    for(i = 1; i <= n; i++){
        r = r * i;
    }

    return r;
}

void ma(int *a, int p, int r) {
    for(int i = 0; i < p; i++) {
        a[i] *= r;
    }
}

int sogl(wchar_t c) {
    wchar_t lower_c = towlower(c);
    wchar_t v[] = L"аеёиоуыэюяaeyuio";
    
    for (int i = 0; v[i] != L'\0'; i++) {
        if (lower_c == v[i]) {
            return 0;  // гласная
        }
    }
    
    return 1;          // согласная
}

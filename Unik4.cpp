#include <iostream>

int main(){
    int n, k, m = 0, i = 0;
    scanf("%d",n);
    k = n;
    while(k > 0){
        m = m + k%10;
        i= i + 1;
        k = k / 10;
    }
    printf("%d", i, m);
    return 0;
}
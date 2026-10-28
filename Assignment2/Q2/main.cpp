#include <stdio.h>

int sumDivisors(int x) {
    int sum = 0;
    int i;
    for(i = 1; i <= x / 2; i++) {
        if(x % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    printf("Amicable pairs up to %d:\n", n);
    int pair_count = 0;
    int a, b;
    
    for(a = 1; a <= n; a++) {
        b = sumDivisors(a);
        if(b > a && b <= n) {
            if(sumDivisors(b) == a && a != b) {
                printf("(%d, %d)\n", a, b);
                pair_count++;
            }
        }
    }
    
    printf("Total pairs: %d\n", pair_count);
    return 0;
}




```[ci

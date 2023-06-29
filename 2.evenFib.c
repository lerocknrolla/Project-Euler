#include <stdio.h>

/* sum of the even terms of the Fibonacci sequence that do not exceed 4_000_000 */

int isEven(int number) {
    if (number%2) {
        return 0;
    } else {
        return 1;
    }
    
}

int limit = 4000000;

int main() {

    int a,b,memory,sum;
    a = 1;
    b = 2;

    for (sum = 0; b <= limit; memory = a+b, a = b, b = memory)
    {
        sum += isEven(b) * b;
    }
    
    printf("%i", sum);

    return 0;
}
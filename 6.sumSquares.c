#include <stdio.h>

/*
from https://projecteuler.net/problem=6

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is

3025 - 385 = 2640

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

/*
It is known that the sum of the first n natural numbers is n(n+1)/2. This is attributed, apocryphally, to Gauss.

As such, the square of the sum of the first n natural numbers is [n(n+1)/2]^2. We could compute that, and then the sum of the squares.

However, we can also observe that (1 + 2 + ... + n)^2 = (1 + 2 + ... + n)*[n(n+1)/2] = 1[n(n+1)/2] + 2[n(n+1)/2] + ... + n[n(n+1)/2].

This allows us to pair the constant [n(n+1)/2] with the numbers from 1 to n. (let's call this result A)

Then we observe that:
        (1 + 2 + ... + n)^2 - (1^2 + 2^2 + ... + n^2) =
    =   [ 1[n(n+1)/2] + 2[n(n+1)/2] + ... + n[n(n+1)/2] ] - (1^2 + 2^2 + ... + n^2) =
    
which can be redistributed as:

        (1[n(n+1)/2] - 1^2) + (2[n(n+1)/2] - 2^2) + ... + (n[n(n+1)/2] - n^2) =
    =   1([n(n+1)/2] - 1) + 2([n(n+1)/2] - 2) + ... + n([n(n+1)/2] - n) =
    =   i([n(n+1)/2] - i), for i going from 1 to n

which can be programmed as an iteration of one simple subtraction and one multiplication, being added to a result.
*/

int main() {
    unsigned long long int sum,result;
    result = 0;
    unsigned int n,i;

    printf("Give us a natural number n; we will return (1 + 2 + ... + n)^2 - (1^2 + 2^2 + ... + n^2).\n");
    scanf("%u",&n);

    sum = n * (n+1) / 2;

    for (i = 1; i <= n; i++) {
        result += i * (sum - i);
    }

    printf("The difference between the sum of the squares of the first %u natural numbers and the square of the sum is %llu.\n",n,result);

    return 0;
}
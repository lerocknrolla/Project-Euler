#include <stdio.h>

/*
from https://projecteuler.net/problem=5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

// isn't this just the least common multiple?

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b,a%b);
    }
}

unsigned long long int lcm(unsigned long long int a,unsigned long long int b) {
    return a * b / gcd(a,b);
}

int main() {

    printf("Please input a positive integer n; this program will return the smallest positive number that is evenly divisible by all the integers between 1 and n, inclusive.\n");
    unsigned int n;
    scanf("%u",&n);
    unsigned int a;
    unsigned long long int result = 1;

    for (a = 1; a < n; a++) {
        result = lcm(result,a+1);
    }

    printf("That number is %llu\n",result);


    return 0;
}
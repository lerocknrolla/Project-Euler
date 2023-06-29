#include <stdio.h>

/*
from https://projecteuler.net/problem=7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

/*
REASONING

I haven't come up with any way to do this without actually listing all the first 10 000 primes first, so here goes something.

I'll be trying to use the sieve of Eratosthenes (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) to generate primes.
*/

unsigned long nthPrime();

int main(unsigned int n) {
    const unsigned int limite = n;
    unsigned long primos[n] = {0};
    unsigned int number;
    unsigned long p;
    printf("Please give us a number n; we will return the n-th prime number\n");
    scanf("%u",&number);

    p = nthPrime(number);

    printf("The %u-th prime number is %lu.\n",number,p);

    return 0;
}

unsigned long nthPrime(unsigned int limite) {
    const unsigned int LIMITE = limite;
    unsigned long primos[LIMITE] = {0};
    unsigned long int primo = 2;
    unsigned int n = 0;

    primos[n] = primo;
    n++;

    for (unsigned long i = 3; n< limite; i+=2) {
        printf("%lu",i);
        for (unsigned int m = 1;;m++) {
            primo = primos[m];
            if (primo==0) {
                primos[m] = i;
                n++;
                break;
            } else if (i%primo) {
                continue;
            } else {
                break;
            }
        }

    }
    return primos[n-1];

}
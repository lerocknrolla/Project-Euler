#include <stdio.h>
#include <math.h>

// https://projecteuler.net/problem=3
// What is the largest prime factor of the number 600851475143 ?

// int testIfFactor(unsigned long long candidate, unsigned long long toEval) {

//     int isFactor = toEval % candidate == 0;

//     return isFactor;
// }


int main() {

    /*
    Sliding window: procura o divisor i mais pequeno de n, e divide n por i ate nao dar resto 0, armazenando o resultado
    procura o proximo que e possivel dividir
    quando i e o resultado armazenado sao iguais, esse numero e o maior divisor primo
    este resultado e garantido pelo facto de o menor divisor de um numero, depois do 1, e sempre primo
    */

    unsigned long long n,current, i;
    
    printf("Please write a positive integer\n");
    scanf("%llu",&n);

    i = 3;
    current = n;

    while (i != current)
    {
        while (current % 2 == 0) {
            current /= 2;
        }

        if (current % i) {
            i += 2;
        } else
        {
            current /= i;
        }
        

    }

    printf("The largest prime divisor of %llu is %llu\n", n, current);

    return 0;

}
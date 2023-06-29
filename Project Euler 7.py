# -*- coding: utf-8 -*-
"""
Created on Mon Mar 20 19:34:56 2023

@author: lerocknrolla
"""

def nthPrime(n=6):
    primes = [2]+[0]*(n-1)
    current = 3
    while not primes[-1]:
        for i,prime in enumerate(primes):
            if not prime:
                primes[i] = current
                break
            elif current %prime:
                continue
            else:
                break
        current += 2
        
    return primes[-1]

for n in range(1,101):
    print(f'The {n}th prime number is {nthPrime(n)}')
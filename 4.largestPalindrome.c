#include <stdio.h>
#include <math.h>

/*
from https://projecteuler.net/problem=4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

int countDigits(unsigned long long int n) {
    // returns how many digits a positive number n has

    unsigned int count = 0;

    while (n>0)
    {
        count += 1;
        n /= 10;
    }
    return count;    
}

int isPalindromeUnoDigits(unsigned long long int n) {

    return isPalindrome(n, countDigits(n));
}


int isPalindrome(unsigned long long int n, unsigned int digits) {
    //checks if a given positive integer is a palindrome
    
    unsigned int leftmost,rightmost;

    while (digits>1) {
        
        digits -= 2;
        leftmost = n / pow(10,(digits+1));
        rightmost = n%10;
        // printf("leftmost: %i, rightmost: %i\n", leftmost, rightmost);
        if (leftmost-rightmost) {
            return 0;
        }

        n -= (leftmost * pow(10,digits+1));
        n -= rightmost;
        n /= 10;

        // printf("new n: %i\n",n);
    }

    return 1;
}



int main () {
    // program checks pairs of <input>-digit numbers: after multiplying them together, checks if that number is larger than the current result (which starts at 0);
    // if yes, checks whether that number is a palindrome;
    // if it is, that's the new result; otherwise it is skipped;
    // in the end, the result is returned;

    // maybe it would be better to start with the largest numbers, decrease tem alternately, and return the first palindrome?

    unsigned long int limit;
    printf("Please input a positive integer. The program will look for the largest palindrome that can be made as a product of two numbers with the number of digits that you gave as input\n");
    scanf("%lu",&limit);
    printf("The largest possible palindrome that is the product of two %lu-digits numbers is ",limit);
    limit = pow(10,limit);
    
    
    // largest possible product of two three-digit numbers is 998001, so we need at least a long int to store the result

    unsigned long long int result,current;
    unsigned long int a,b;
    result = 0;

    for (a = limit/10; a < limit; a++) {
    // {   printf("a is %u",a);
        for (b = a; b < limit; b++) // if b<a, we've already checked that pair
        {
            current = a * b;
            if (current > result)
            {
                if (isPalindromeUnoDigits(current))
                {
                    result = current;
                }
            }
            
            
        }
        
    }
    

    printf("%llu\n",result);

    return 0;
}
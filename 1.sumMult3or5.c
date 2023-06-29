#include <stdio.h>

/* https://projecteuler.net/problem=1 */
/* calculate the sum of all positive multiples of 3 or 5 smaller than 1000 */

int main() {

    int number,limit, sum;

    limit = 1000;

    sum = 0;

    for (number = 1; number < limit; number++)
    {
        if (!(number % 3)) {
            //printf("The current number is %d\n",number);
            sum += number;
            continue;
        } else if (!(number % 5)) {
            //printf("The current number is %d\n",number);
            sum += number;
            continue;
        }
        
    }
    
    printf("%d",sum);

    return 0;
}
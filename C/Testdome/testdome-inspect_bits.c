/*
 * Implement the inspect_bits function that checks if given number contains 2 or more consecutive ones in its binary
 * representation. If it does, the function should return 1, otherwise, it should return 0.
 *
 * For example, inspect_bits(13) should return 1 as it contains 2 consecutive ones in its binary representation (1101).
 */
#include <stdlib.h>
#include <stdio.h>

int inspect_bits(unsigned int number)
{
    int count = 0;
    while(number) {
        number = (number & (number << 1));
        count++;
    }
    if (count > 1)
        return 1;
    else
        return 0;
}

#ifndef RunTests
int main ()
{
    printf("%d", inspect_bits(13));
}
#endif

#include<stdio.h>

/* This prgoram performs bit manipulation to achieve the following:
 * - Set a bit in a given number (using bitwise OR)
 * - Unset/Clear a bit at at given position in a given number (Using bitwise AND)
 * - Toggle a bit at a given position (Using XOR)
 * - Check if a bit at a given position is one or zero  
 *
 * Version 0.1; Author M. Ahsan (Last modification: 2020-10-23)
*/

// function prompts
int setBit(int num, int pos); // function for bit setting
int clearBit(int num, int pos); // function for clearing specific bit
int toggleBit(int num, int pos); // function to toggle(0->1, 1->0) specific bit
void isbitSet(int num, int pos); // function to check if a specific bit is set(1) or not set(0)

int setBit(int num, int pos){
        // first step is shift '1' left by pos
        // second step is bitwise OR
        num |= ( 1 << pos);
        return num;
}

int clearBit(int num, int pos) {
        // first step is shifting '1' left by pos
        // second step is taking one's complement to get all '1s' except the bit at 'pos'
        // last step is bitwise AND to clear the bit at 'pos'
        num &= (~(1 << pos));
        return num;
}

int toggleBit(int num, int pos){
        // first step is shift '1' left by pos
        // second step is bitwise XOR
        num ^= ( 1 << pos);
        return num;
}

void isbitSet(int num, int pos){
    num &= (1 << pos);
    if (num) {
        printf("Bit is one.\n");
    }
    else{
        printf("Bit is zero.\n");
    }
}

int main(){
    int number, bitposition, result;
    char choice;
    while (1) {
        // decimal number
        printf("Please enter the number: "); 
        scanf("%d", &number);
        // position at which we want to set the bit
        printf("Please enter the position of the bit to be manipulated: ");
        scanf("%d",&bitposition);
        // number of bits to set
        printf("Please make a choice from the following\n");
        printf(" - 1 to set bit in a given number\n");
        printf(" - 2 to unset/clear bit at a given position in a given number\n");
        printf(" - 3 to toggle bit at a given position\n");
        printf(" - 4 to check if bit at a given position is set or not\n");
        printf ("- 'q' or 'Q' to quit.\n");
        scanf(" %c", &choice);
        //printf("choice is %c", choice);
        if (choice == 'q' || choice == 'Q'){
            break;
        }
        switch (choice) {
            case '1':
                result = setBit(number, bitposition); 
                printf("Result is %d.\n", result);
                break;
            case '2':
                result = clearBit(number, bitposition);
                printf("Result is %d.\n", result);
                break;
            case '3':
                result = toggleBit(number, bitposition);
                printf("Result is %d.\n", result);
                break;
            case '4':
                isbitSet(number, bitposition);
                break;
            default:
                printf("Unknown choice!");
                break;
        }
    }
}




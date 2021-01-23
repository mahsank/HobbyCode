#include<stdio.h>
#define MAXDIGITS 32
/* This is a small program to convert a decimal number to binary
   Version 0.1; Author M. Ahsan (Last modification: 2020-10-23)
*/

// function prototype
void dec2Binary(int n);

int main(){
    int num;
    char choice;
    
    while(1)
    {
        printf("Please enter a decimal number\n");
        scanf("%d", &num);
        dec2Binary(num);
        printf("Want to convert another number (n/N to quit; any other single character to continue)?\n");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
            break;

    }
}

/* dec2Binay: convert a decimal numbr to binary */
void dec2Binary(int n){
    int binaryNum[MAXDIGITS];
    int i=0;
    while (n > 0){
        binaryNum[i] = n%2;
        n = n/2;
        i++;
    }
    for (int j=i-1; j >=0; j--)
        printf("%u",binaryNum[j]);    
    printf("\n");
}

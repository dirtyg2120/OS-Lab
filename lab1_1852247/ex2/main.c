#include <stdio.h>
#include "sum.h"
#include "sub.h"

int main()
{
    int a, b;
    printf("Input first integer: ");
    scanf("%d", &a);
    printf("Input second integer: ");
    scanf("%d", &b);
    
    printf("Sum of two numbers = %d\n", sum(a,b));
    printf("Sub of two numbers = %d\n", sub(a,b));
}

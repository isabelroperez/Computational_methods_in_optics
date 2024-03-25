#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
    int a, b, c, answer;
    printf("Enter three digits to compare: (In the format n,n,n)\n");
    scanf("%d, %d, %d", &a, &b, &c);
    answer = maximum(a, b, c);
    printf("The maximum is: %d", answer);
    return 0;
}


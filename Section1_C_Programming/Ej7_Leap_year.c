#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    printf("Tell me the year you want please\n");
    scanf("%d", &year);

    if (year % 4 != 0)
    { // Not divisible by 4
        printf("It's not a leap year");
    }
    else if (year % 100 != 0)
    {
        printf("It's not a leap year");
    }
    else if (year % 400 != 0)
    {
        printf("It's a leap year");
    }
    else
    {
        printf("It's not a leap year");
    }

    return 0;
}

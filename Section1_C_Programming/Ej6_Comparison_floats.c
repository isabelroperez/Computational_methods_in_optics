#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f = 5;
    int g = 2;
    int i = 5;
    printf("%d\n", f / g);
    printf("%d\n", g > f);
    printf("The initial value of i is %d\n", i);
    printf("The value of i++ is %d\n", i++);
    printf("Value of i: %d\n", i);
    printf("++i is equal to %d\n", ++i);
    printf("Final value of i: %d\n", i);

    float r = 1.234567;
    float t = 1.234566;
    t = t + 0.000001;
    printf("The result of comparing %.10f with %.10f is %d \n", r, t, r == t);
    return 0;
}


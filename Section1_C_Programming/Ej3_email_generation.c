#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int day, month, year;
    char name[256];
    char surname[256];
    printf("Enter the name:\n");
    scanf("%s", name);
    printf("Enter the surname:\n");
    scanf("%s", surname);
    printf("Enter the date of birth in the format dd/mm/yyyy:\n");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Email: %s.%s@usal.es\n", name, surname);
    printf("Password: %c%c%02d%02d%02d%\n", tolower(name[0]), tolower(surname[0]), day, month, year % 100);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    int data;
    float float1;
    char text1[256];
    file = fopen("data.txt", "w");
    fprintf(file, "1 1.1 string\n");
    fclose(file);

    file = fopen("data.txt", "r");
    fscanf(file, "%d %f %s\n", &data, &float1, text1);
    fclose(file);
    printf("Read data: %d %f %s\n", data, float1, text1);

    return 0;
}


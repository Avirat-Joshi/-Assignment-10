#include <stdio.h>
#include <string.h>
union storage
{
    int a[10];
    char b[10];
    float c[10];
} s1;
int main()
{
    for (int i = 0; i < 10; i++)
        s1.a[i] = i;
    printf("Integers- ");
    for (int i = 0; i < 10; i++)
        printf("%d ", s1.a[i]);
    printf("\n");
    for (int i = 0; i < 10; i++)
        s1.c[i] = i/10.0;
    printf("Float- ");
    for (int i = 0; i < 10; i++)
        printf("%f ", s1.c[i]);
    printf("\n");
    strcpy(s1.b,"014739\0");
    printf("characters- ");
    printf("%s",s1.b);
    return 0;
}
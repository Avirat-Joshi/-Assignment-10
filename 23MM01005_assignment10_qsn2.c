#include<stdio.h>
struct s
{
    int a;
    int b;
    char c;
}s1;
union u
{
    int a;
    int b;
    char c;
}u1;
int main()
{
    printf("Size of union: %lu\n",sizeof(u1));
    //union takes size corresponding to sizeof largest data type
    printf("Size of structure: %lu",sizeof(s1));
    //struct takes size according to padding technique(not necessarily sum of size of data types)
    return 0;
}
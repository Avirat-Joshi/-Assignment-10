#include <stdio.h>
#include <string.h>
enum PayType
{
    HOURLY = 1,
    SALARY = 2
};
union EmpDetails
{
    float hourly_wage;
    double fixed;
    enum PayType p2;
};
struct Employee
{
    int employee_id;
    char name[100];
    union EmpDetails emp1;
    enum PayType p1;
};
int main()
{
    struct Employee e1;
    e1.employee_id = 123;
    strcpy(e1.name, "Avirat Joshi\0");
    printf("1. Hourly Wage\n2.Fixed Salary\n");
    printf("Enter choice: ");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case HOURLY:
        e1.p1 = HOURLY;
        e1.emp1.p2=HOURLY;
        printf("Enter hourly wage: ");
        scanf("%f", &e1.emp1.hourly_wage);
        break;
    case SALARY:
        e1.p1 = SALARY;
        e1.emp1.p2=SALARY;
        printf("Enter fixed Salary: ");
        scanf("%lf", &e1.emp1.fixed);
        break;
    default:
        printf("Wrong choice");
        return 0;
    }
    if (e1.p1 == HOURLY)
    {
        printf("Employee ID: %d\n", e1.employee_id);
        printf("Employee name: %s\n", e1.name);
        printf("Employee hourly wage: %f", e1.emp1.hourly_wage);
    }
    if (e1.p1 == SALARY)
    {
        printf("Employee ID: %d\n", e1.employee_id);
        printf("Employee name: %s\n", e1.name);
        printf("Employee fixed salary: %lf", e1.emp1.fixed);
    }
    return 0;
}
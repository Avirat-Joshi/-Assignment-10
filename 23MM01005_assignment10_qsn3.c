#include <stdio.h>
#include <string.h>
union EmpDetails
{
    float hourly_wage;
    double fixed_salary;
};
struct Employee
{
    int employee_id;
    char name[100];
    union EmpDetails e1;
};
int main()
{
    struct Employee e1;
    e1.employee_id = 123;
    strcpy(e1.name, "Avirat Joshi\0");
    printf("1. Hourly Wage\n2.Fixed Salary\n");
    printf("Enter choice: ");
    int n;
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        printf("Enter hourly wage: ");
        scanf("%f",&e1.e1.hourly_wage);
        break;
    case 2:
        printf("Enter fixed Salary: ");
        scanf("%lf",&e1.e1.fixed_salary);
        break;
    default:
        printf("Wrong choice");
        return 0;    
    }
    if(n==1)
    {
        printf("Employee ID: %d\n",e1.employee_id);
        printf("Employee name: %s\n",e1.name);
        printf("Employee hourly wage: %f",e1.e1.hourly_wage);
    }
    if(n==2)
    {
        printf("Employee ID: %d\n",e1.employee_id);
        printf("Employee name: %s\n",e1.name);
        printf("Employee fixed salary: %lf",e1.e1.fixed_salary);    
    }
    // union within structures can be used for memory efficiency and when only one data type exists at a given time
    return 0;
}
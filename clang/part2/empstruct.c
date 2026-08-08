/* Fri Aug  7 03:32:46 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
typedef struct Employee Employee;
typedef struct Name Name;
typedef struct Address Address;
struct Address {
    char *street;
    char *city;
};
struct Name {
    char *first;
    char *last;
};
struct Employee {
    int id;
    char *title;
    Name name;
    Address address;
};
void details(Employee emp) {
    printf("id = %d\n", emp.id);
    printf("first name = %s\n", emp.name.first);
    printf("last name = %s\n", emp.name.last);
    printf("street = %s\n", emp.address.street);
    printf("city = %s\n", emp.address.city);
    printf("title = %s\n", emp.title);
}
void pdetails(Employee *emp) {
    printf("id = %d\n", emp->id);
    printf("first name = %s\n", emp->name.first);
    printf("last name = %s\n", emp->name.last);
    printf("street = %s\n", emp->address.street);
    printf("city = %s\n", emp->address.city);
    printf("title = %s\n", emp->title);
}
int main(int argc, char *argv[])
{
    Name name = {"victor", "nammour"};
    Address address = {"main street", "Jerusalem"};
    // Employee emp = {0, "programmer", name, address};
    Employee emp = {.id = 0, .title = "programmer", .name = name, .address = address};
    details(emp);
    printf("\n");
    pdetails(&emp);
}

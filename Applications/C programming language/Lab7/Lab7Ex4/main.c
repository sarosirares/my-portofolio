#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char first_name[50];
    char last_name[50];
    int number;
}Person;

void get_info(Person *ptr);
void make_info(Person *ptr);
void show_info(Person *ptr);

int main()
{
    Person name;

    get_info(&name);
    make_info(&name);
    show_info(&name);

    return 0;
}

void get_info(Person *ptr)
{
    printf("Enter your first name: ");
    scanf("%s", ptr -> first_name);
    printf("Enter your last name: ");
    scanf("%s", ptr -> last_name);
}

void make_info(Person *ptr)
{
    ptr -> number = strlen(ptr -> first_name) + strlen(ptr -> last_name);
}

void show_info(Person *ptr)
{
    printf("\nThe total number of letters of %s %s is: %d\n", ptr -> first_name, ptr -> last_name, ptr -> number);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char first_name[50];
    char last_name[50];
    int n;
} Name;

void get_info(Name *ptr);
void make_info(Name *ptr);
void show_info(Name *ptr);

int main()
{
    Name str;
    get_info(&str);
    make_info(&str);
    show_info(&str);
    return 0;
}

void get_info(Name *ptr)
{
    printf("Enter your first name: ");
    scanf("%s", ptr->first_name);
    printf("Enter your last name: ");
    scanf("%s", ptr->last_name);
}

void make_info(Name *ptr)
{
    ptr->n = strlen(ptr->first_name) + strlen(ptr->last_name);
}

void show_info(Name *ptr)
{
    printf("The total number of letters is: %d", ptr->n);
}

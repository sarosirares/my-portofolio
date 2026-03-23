#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int student_id;
    char first_name[30];
    char last_name[30];
    float grade;
}Student;

void insert_students(FILE *fp, int n, Student *st);
void display_students(FILE *fp, int n, Student *st);
float display_average(FILE *fp, int n, Student *st);
void display_passed(FILE *fp, int n, Student *st);
void display_alphabetical(FILE *fp, int n, Student *st);
int enter_choice();

int main()
{
    int n = 0, choice = 0;
    Student *st;
    FILE *fp, *fp1;

    printf("Enter the number of the students: ");
    scanf("%d", &n);

    st = (Student *)calloc(n, sizeof(Student));

    fp = fopen("students.bin", "wb");
    insert_students(fp, n, st);
    fclose(fp);

    fp1 = fopen("students.bin", "rb");
    while((choice = enter_choice()) != 5)
    {
        switch(choice)
        {
            case 1:
                display_students(fp1, n, st);
            break;
            case 2:
                printf("\nThe average is: %f\n",display_average(fp1, n ,st));
            break;
            case 3:
                display_passed(fp1, n, st);
            break;
            case 4:
                display_alphabetical(fp1, n, st);
            break;
            default: printf("Enter a valid choice!\n");
            break;
        }
    }
    fclose(fp1);

    free(st);

    return 0;
}

void insert_students(FILE *fp, int n, Student *st)
{
    for(int i = 0; i < n; i++)
    {
        st -> student_id = i + 1;
        printf("Enter the student's first name: ");
        scanf("%s", st->first_name);
        printf("Enter the student's last name: ");
        scanf("%s", st->last_name);
        printf("Enter the student's grade: ");
        scanf("%f", &st->grade);
        fwrite(st, sizeof(Student), 1, fp);
    }
}

int enter_choice()
{
    int menu_choice = 0;
    printf("\nEnter your choice:\n"
           "1 - Display the students information\n"
           "2 - Display the average of the students grades\n"
           "3 - Display students who passed the exam\n"
           "4 - Display students in alphabetical order after their last name\n"
           "5 - Exit\n");
    scanf("%d", &menu_choice);
    return menu_choice;
}

void display_students(FILE *fp, int n, Student *st)
{
    fread(st, sizeof(Student), n, fp);
    for(int i = 0; i < n; i++)
    {
        printf("The %d student's id: %d\n", i + 1, st[i].student_id);
        printf("The %d student's first name: %s\n", i + 1, (st + i)->first_name);
        printf("The %d student's last name: %s\n", i + 1, (st + i)->last_name);
        printf("The %d student's grade: %f\n", i + 1, (st + i)->grade);
    }
}

float display_average(FILE *fp, int n, Student *st)
{
    fread(st, sizeof(Student), n, fp);
    float s = 0.00;
    for(int i = 0; i < n; i++)
    {
        s += (st + i)->grade;
    }
    return s/n;
}

void display_passed(FILE *fp, int n, Student *st)
{
    fread(st, sizeof(Student), n, fp);
    for(int i = 0; i < n; i++)
    {
        if(((st + i)->grade) >= 5)
        {
            printf("The %d student's id: %d\n", i + 1, st[i].student_id);
            printf("The %d student's first name: %s\n", i + 1, (st + i)->first_name);
            printf("The %d student's last name: %s\n", i + 1, (st + i)->last_name);
            printf("The %d student's grade: %f\n", i + 1, (st + i)->grade);
        }
    }
}

void display_alphabetical(FILE *fp, int n, Student *st)
{
    Student aux;
    fread(st, sizeof(Student), n, fp);
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp((st + i)->last_name, (st + j)->last_name) > 0)
            {
                strcpy(aux.last_name, (st + i)->last_name);
                strcpy((st + i)->last_name, (st + j)->last_name);
                strcpy((st + j)->last_name, aux.last_name);
                strcpy(aux.first_name, (st + i)->first_name);
                strcpy((st + i)->first_name, (st + j)->first_name);
                strcpy((st + j)->first_name, aux.first_name);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("The %d student's id: %d\n", i + 1, st[i].student_id);
        printf("The %d student's first name: %s\n", i + 1, (st + i)->first_name);
        printf("The %d student's last name: %s\n", i + 1, (st + i)->last_name);
        printf("The %d student's grade: %f\n", i + 1, (st + i)->grade);
    }
}

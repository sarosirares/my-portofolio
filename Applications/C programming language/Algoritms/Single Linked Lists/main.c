#include <stdio.h>
#include <stdlib.h>

typedef struct tip_nod
{
    int key;
    struct tip_nod *next;
}T_NOD;

typedef struct a
{
    char name[10];
    int b_year;
    int age;
}A;

A stud[20];
int n;
T_NOD *p, *first, *last;

int main()
{
    first = 0;
    last = 0;
    int opt = -1;
    while(opt != 0)
    {
        printf("\n0. Exit\n1. Read\n2. Compute\n3. Display\n4. Create\n5. Insert\n6. Delete\n7. Display list\n\nOption: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: system("CLS"); read(); break;
            case 2: system("CLS"); compute(); break;
            case 3: system("CLS"); display(); break;
            case 4: system("CLS"); create(); break;
            case 5: system("CLS"); insert(); break;
            case 6: system("CLS"); deletek(); break;
            case 7: system("CLS"); display_list(); break;
            case 0: return 0;
            default: system("CLS"); printf("\nWrong option\n"); break;
        }
    }
    return 0;
}

void read()
{
    int i = 0;
    printf("\nIntroduce the number of students: ");
    scanf("%d", &n);
    for( i = 0; i < n ; i++)
    {
        printf("\nIntroduce your name: ");
        scanf("%s", stud[i].name);
        printf("\nIntroduce your birthday year: ");
        scanf("%d", &stud[i].b_year);
    }
    system("CLS");
    printf("\nStudents inserted!\n");
}

void compute()
{
    int i = 0;
    for( i = 0; i < n; i++)
    {
        stud[i].age = 2024 - stud[i].b_year;
    }
    system("CLS");
    printf("\nComputed!\n");
}

void display()
{
    int i = 0;
    printf("\n\tSTUDENTS TABLE\n\nNAME\tYEAR\tAGE\n");
    for( i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\n", stud[i].name, stud[i].b_year, stud[i].age);
    }
}

T_NOD* search_key()
{
    T_NOD *q, *q1;
    int k1;
    q = first;
    printf("\nThe key that you search for is: ");
    scanf("%d", &k1);
    while(q != NULL)
    {
        if(q->key == k1)
        {
            if(q == first)
                return q;
            return q1;
        }
        else
        {
            q1 = q;
            q = q->next;
        }
    }
    printf("\nDoesn't exist!\n");
    return NULL;
}

void create()
{
    p = (T_NOD*)malloc(sizeof (T_NOD));
    if(first != 0)
        printf("\nList already created!\n");
    else
    {
        printf("\nInsert the key: ");
        scanf("%d", &p->key);
        p->next = NULL;
        first = p;
        last = p;
    }
}

void insert()
{
    if(first == 0)
    {
        printf("\nList not created! Creating the list:\n\n");
        create();
    }
    else
    {
        T_NOD *q, *q1;
        int inopt = -1;
        while(inopt != 0)
        {
            system("CLS");
            printf("\n0. Exit\n1. Insert first\n2. Insert last\n3. Insert before a key\n4. Insert after a key\n\nInsert Option: ");
            scanf("%d", &inopt);
            switch (inopt)
            {
            case 1:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                printf("\nInsert the key: ");
                scanf("%d", &p->key);
                p->next = first;
                first = p;
                break;
            case 2:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                printf("\nInsert the key: ");
                scanf("%d", &p->key);
                p->next = NULL;
                last->next = p;
                last = p;
                break;
            case 3:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                printf("\nInsert the key: ");
                scanf("%d", &p->key);
                q1 = search_key();
                if(q1 != NULL)
                {
                    q = q1->next;
                    if(q == first)
                    {
                        p->next = first;
                        first = p;
                    }
                    else
                    {
                        p->next = q;
                        q1->next = p;
                    }
                }
                break;
            case 4:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                printf("\nInsert the key: ");
                scanf("%d", &p->key);
                q1 = search_key();
                if(q1 != NULL)
                {
                    q = q1->next;
                    p->next = q->next;
                    q->next = p;
                }
                break;
            case 0: break;
            default: system("CLS"); printf("\nWrong option\n"); break;
            }
        }
    }
}

void deletek()
{
    T_NOD *q, *q1;
    q1 = search_key();
    q = q1->next;
    if(q1 == first)
    {
        first = q1->next;
        free(q1);
    }
    else if(q == last)
    {
        q1->next = NULL;
        last = q1;
    }
    else
    {
        q1->next = q->next;
        free(q);
    }
}

void display_list()
{
    T_NOD *q;
    q = first;
    printf("\The list:\n\nKEY\n");
    while(q != NULL)
    {
        printf("%d\n", q->key);
        q = q->next;
    }
}

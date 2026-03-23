#include <stdio.h>
#include <stdlib.h>

typedef struct tip_nod
{
    int key;
    struct tip_nod *next;
    struct tip_nod *prev;
}T_NOD;

typedef struct a
{
    char name[10];
    int b_year;
    int age;
}A;

struct list_header
{
    T_NOD *first;
    T_NOD *last;
}L_HEAD;
A stud[20];
int n;
T_NOD *p;
struct list_header *L;

int main()
{
    L = (struct list_header*)malloc(sizeof (struct list_header));
    L->first = L->last = NULL;
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
    T_NOD *q;
    int k1;
    printf("\nThe key that you search for is: ");
    scanf("%d", &k1);
    for(q = L->first; q != NULL; q = q->next)
    {
        if(q->key == k1)
            return q;
    }
    printf("\nDoesn't exist!\n");
    return NULL;

}

void create()
{
    p = (T_NOD*)malloc(sizeof (T_NOD));
    if(L->first == NULL)
    {
        printf("\nInsert the key: ");
        scanf("%d", &p->key);
        L->first = L->last = p;
        p->next = p->prev = NULL;
    }
    else
    {
        printf("\nThe list already exists!\n");
    }
}

void insert()
{
    if(L->first == 0)
    {
        printf("\nList not created! Creating the list:\n\n");
        create();
    }
    else
    {
        T_NOD *q;
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
                p->next = L->first;
                p->prev = NULL;
                L->first->prev = p;
                L->first = p;
                break;
            case 2:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                printf("\nInsert the key: ");
                scanf("%d", &p->key);
                p->next = NULL;
                p->prev = L->last;
                L->last->next = p;
                L->last = p;
                break;
            case 3:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                printf("\nInsert the key: ");
                scanf("%d", &p->key);
                q = search_key();
                if(q == NULL)
                    break;
                p->next = q;
                p->prev = q->prev;
                if(q->prev != NULL)
                    q->prev->next = p;
                q->prev = p;
                if(L->first == q)
                    L->first = p;
                break;
            case 4:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                printf("\nInsert the key: ");
                scanf("%d", &p->key);
                q = search_key();
                if(q == NULL)
                    break;
                p->prev = q;
                p->next = q->next;
                if(q->next != NULL)
                    q->next->prev = p;
                q->next = p;
                if(L->last == q)
                    L->last = p;
            case 0: break;
            default: system("CLS"); printf("\nWrong option\n"); break;
            }
        }
    }
}

void deletek()
{
    if(L->first == 0)
    {
        printf("\nList not created! Creating the list:\n\n");
        create();
    }
    else
    {
        int inopt = -1;
        while(inopt != 0)
        {
            printf("\n0. Exit\n1. Delete first\n2. Delete last\n3. Delete a given node\n4. Delete the list\n\nInsert Option: ");
            scanf("%d", &inopt);
            switch (inopt)
            {
            case 1:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                p = L->first;
                L->first = L->first->next;
                free(p);
                if(L->first == NULL)
                    L->last = NULL;
                else
                    L->first->prev = NULL;
                break;
            case 2:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                p = L->last;
                L->last = L->last->prev;
                free(p);
                if(L->last == NULL)
                    L->first = NULL;
                else
                    L->last->next = NULL;
                break;
            case 3:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                p = search_key();
                if(L->first == p && L->last == p)
                {
                    L->first = NULL;
                    L->last = NULL;
                    free(p);
                }
                else
                if(p == L->first)
                {
                    L->first = L->first->next;
                    L->first->prev = NULL;
                    free(p);
                }
                else
                {
                    p->next->prev = p->prev;
                    p->prev->next = p->next;
                    free(p);
                }
                break;
            case 4:
                p = (T_NOD*)malloc(sizeof (T_NOD));
                while(L->first != NULL)
                {
                    p = L->first;
                    L->first = L->first->next;
                    free(p);
                }
                L->last = NULL;
                system("CLS");
                printf("\nThe list has been deleted!\n");
                break;
            case 0: break;
            default: system("CLS"); printf("\nWrong option\n"); break;
            }
        }
    }
}

void display_list()
{
    p = (T_NOD*)malloc(sizeof (T_NOD));
    printf("\The list:\n\nKEY\n");
    for(p = L->first; p != NULL; p = p->next)
    {
        printf("%d\n", p->key);
    }
}

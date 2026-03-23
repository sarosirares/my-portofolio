#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 2

typedef struct cell
{
    char *key;
    struct cell *next;
}NodeT;

int main()
{
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


int f(char *key)
{
    int i, sum;
    sum = 0;
    for(i = 0; i < strlen(key); i++)
        sum += key[i];
    return(sum % B);
}

NodeT *BucketTable[B];

void createHash()
{
    for(int i = 0; i < B; i++)
        BucketTable[i] = NULL;
}

NodeT *searchHash(char *key)
{
    int h;
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    h = f(key);
    p = BucketTable[h];

    while(p != NULL)
    {
        if(strcmp(key, p->key) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

void fillNode()
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    printf("Enter the key of the node you want to fill: ");
    scanf("%s", p->key);
    p->next = NULL;
}

void insertHash(char *key)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    NodeT *q;
    int h;
    fillNode(p);

    h = f(p->key);
    if(BucketTable[h] == NULL)
    {
        BucketTable[h] = p;
        p->next = NULL;
    }
    else
    {
        q = searchHash(p->key);
        if(q == 0)
        {
            p->next = BucketTable[h];
            BucketTable[h] = p;
        }
        else
            processRec(p, q);
    }
}

void displayHash()
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    for(int i = 0; i < B; i++)
        if(BucketTable[i] != NULL)
        {
            printf("Bucket for hash value %d\n", i);
            p = BucketTable[i];
            while(p != NULL)
            {
                printf("%d\n", p->key[i]);
                p = p->next;
            }
        }
}

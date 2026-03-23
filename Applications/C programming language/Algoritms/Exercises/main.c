#include <stdio.h>
#include <stdlib.h>

typedef struct tip_nod
{
    int key;
    struct tip_nod *next;
}T_NOD;

int main()
{
    printf("Hello world!\n");
    return 0;
}

T_NOD *first = 0, *last = 0; //declararea primului si ultimului element din lista

void create() //functia de creare a unei liste
{
    T_NOD *p; //declarare nod
    p = (T_NOD*)malloc(sizeof(T_NOD)); //alocare spatiu de memorie in heap

    //citire date in nodul de adresa p

    printf("\nInserati cheia nodului: ");
    scanf("%d", &p->key);

    //crearea legaturilor

    p->next = 0; //nodul este ultimul in lista
    if(last != 0) //daca lista nu este vida
        last->next = p;
    else //lista vida
        first = p; //p este primul introdus in lista
    last = p; //p este ultimul element din lista
}

T_NOD* search_node() //cauta un nod dupa cheia introdusa
{
    T_NOD *p; //declarare nod
    int k; //cheia pe care o cautam
    p = first; //p devinde primul element din lista
    printf("\nCheia pe care o cautati este: ");
    scanf("%d", &k);
    while(p != 0) //parcurgerea listei element cu element
    {
        if(p->key == k) //daca se gaseste cheia
            return p; //se returneaza nodul
        else
            p = p->next; //se trece la urmatorul nod
    }
    return 0; //daca nu s-a gasit cheia, se returneaza NULL
}

void insert_first() //inserarea unui nod inaintea primului nod
{
    T_NOD *p; //declarare nod
    p = (T_NOD*)malloc(sizeof(T_NOD)); //alocare spatiu de memorie in heap

    //citire date in nodul de adresa p

    printf("\nInserati cheia nodului: ");
    scanf("%d", &p->key);

    if(first == 0) //daca lista este vida
    {
        first = p;
        last = p;
        p->next = 0;
    }
    else //daca lista nu este vida
    {
        p->next = first; //fostul prim element devine al 2-lea
        first = p; //nodul p devine primul element
    }
}

void insert_last() //inserarea unui nod la finalul listei
{
    T_NOD *p; //declarare nod
    p = (T_NOD*)malloc(sizeof(T_NOD)); //alocare spatiu de memorie in heap

    //citire date in nodul de adresa p

    printf("\nInserati cheia nodului: ");
    scanf("%d", &p->key);

    if(last == 0) //daca lista este vida
    {
        first = p;
        last = p;
        p->next = 0;
    }
    else //daca lista nu este vida
    {
        p->next = 0; //ultimul nod este urmat de NULL (mereu)
        last->next = p; //fostul ultim nod este legat de nodul p
        last = p; //p devine ultimul element
    }
}

void insert_before() //insereaza nodul p inaintea nodului q cu cheia cautata
{
    T_NOD *p, *q, *q1; //declarare noduri
    int k; //cheia nodului inaintea caruia vrem sa inseram nodul p
    q1 = 0; //nodul din spatele lui q
    q = first; //nodul care parcurge lista
    p = (T_NOD*)malloc(sizeof(T_NOD)); //alocare spatiu de memorie in heap

    //citire date in nodul de adresa p

    printf("\nInserati cheia nodului: ");
    scanf("%d", &p->key);

    printf("\nCheia pe care o cautati este: ");
    scanf("%d", &k);

    while(q != 0) //parcurgerea listei
    {
        if(q->key == k) break; //daca se gaseste nodul cautat, se opreste cautarea, q avand valoarea nodului cautat
        q1 = q; //elementul din spatele lui q ia valoarea lui q (ramane mereu in urma cu un element)
        q = q->next; //q trece la urmatorul element
    }

    if(q != 0) //daca s-a gasit nodul cautat
    {
        if(q == first) //daca nodul cautat este chiar primul element
        {
            p->next = first; //p devine primul element
            first = p;
        }
        else
        {
            q1->next = p; //altfel p este inserat intre q1 si q (inaintea lui q)
            p->next = q;
        }
    }
}

void insert_after() //insereaza nodul p dupa nodul q cu cheia cautata
{
    T_NOD *p, *q; //declarare noduri
    int k; //cheia nodului inaintea caruia vrem sa inseram nodul p
    q = first; //nodul care parcurge lista
    p = (T_NOD*)malloc(sizeof(T_NOD)); //alocare spatiu de memorie in heap

    //citire date in nodul de adresa p

    printf("\nInserati cheia nodului: ");
    scanf("%d", &p->key);

    printf("\nCheia pe care o cautati este: ");
    scanf("%d", &k);

    while(q != 0) //parcurgerea listei
    {
        if(q->key == k) break; //daca se gaseste nodul cautat, se opreste cautarea, q avand valoarea nodului cautat
        q = q->next; //q trece la urmatorul element
    }

    if(q != 0) //daca s-a gasit nodul cautat
    {
        p->next = q->next; //urmatorul element dupa p este urmatorul element dupa cel cautat
        q->next = p; //urmatorul element dupa cel cautat devine p
        if(q == last) //daca nodul cautat este chiar ultimul
            last = p; //p devine ultimul element
    }
}

void delete_first() //stergerea primului nod din lista
{
    T_NOD *p; //declarare nod
    if(first != 0) //daca lista nu este vida
    {
        p = first;
        first = first->next; //al doilea element devine primul element
        free(p);
        if(first == 0) //daca lista a devenit vida
            last = 0;
    }
}

void delete_last() //stergerea ultimului nod din lista
{
    T_NOD *q, *q1; //declarare noduri
    q1 = 0; //nodul din spatele lui q
    q = first; //nodul care parcurge lista
    if(q != 0) //daca lista nu este vida
    {
        while(q != last) //q parcurge lista pana ajunge la ultimul element
        {
            q1 = q;
            q = q->next;
        }
        if(q == first) //daca lista are un singur nod
        {
            //lista devine vida
            first = 0;
            last = 0;
        }
        else
        {
            q1->next = 0; //penultimul element devine ultimul
            last = q1;
        }
        free(q); //se sterge ultimul nod
    }
}

void delete_node() //stergerea nodului cu cheia cautata
{
    T_NOD *q, *q1; //declarare noduri
    int k; //cheia nodului pe care dorim sa il stergem
    q1 = 0; //nodul din spatele lui q
    q = first; //nodul care parcurge lista

    printf("\nCheia pe care o cautati este: ");
    scanf("%d", &k);


    while(q != 0) //q parcurge lista pana gaseste nodul cautat
        {
            if(q->key == k) break; //daca se gaseste nodul cautat, se opreste cautarea, q avand valoarea nodului cautat
            q1 = q;
            q = q->next;
        }
    if(q != 0) //daca lista nu este vida
    {
        if(q == first) //daca nodul cautat este chiar primul element din lista
        {
            first = first->next; //primul element devine al 2-lea
            free(q); //se sterge nodul
            if(first == 0) //daca lista ramane goala
                last = 0; //devine lista vida
        }
        else
        {
            q1->next = q->next; //nodul din spatele nodului cautat este urmat de nodul din fata nodului cautat
            if(q == last) //daca nodul cautat este ultimul
                last = q1; //penultimul element devine ultimul
            free(q); //se sterge nodul
        }
    }
}

void delete_list()
{
    T_NOD *p; //declarare nod
    while(first != 0) //pana cand lista contine elemente
    {
        p = first; //p devine primul element din lista
        first = first->next; //primul element din lista devine urmatorul
        free(p); //se sterge element rand pe rand
    }
    last = 0; //la final lista devine vida
}

void display_list()
{
    T_NOD *p; //declarare nod
    p = (T_NOD*)malloc(sizeof (T_NOD));
    printf("\nThe list:\n\nKEY\n");
    for(p = first; p != NULL; p = p->next)
    {
        printf("%d\n", p->key);
    }
}

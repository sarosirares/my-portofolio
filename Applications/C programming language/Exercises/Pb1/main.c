#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nume[50];
    char compozitor[50];
    int an;
} Song;

Song *citire(Song *v, int n);
Song *sortare(Song *v, int n);
void afisare(Song *v, int n);

int main()
{
    int n = 0;
    Song *vector;

    printf("Introdu numarul de melodii: ");
    scanf("%d", &n);

    vector = (Song *) malloc(n * sizeof(Song *));

    citire(vector, n);
    sortare(vector, n);
    afisare(vector, n);


    return 0;
}

Song *citire(Song *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Introdu numele piesei cu numarul %d: ", i + 1);
        scanf("%s", (v + i)->nume);
        printf("Intordu numele compozitorului: ");
        scanf("%s", (v + i)->compozitor);
        printf("Introdu anul aparitiei: ");
        scanf("%d", &(v + i)->an);
    }
    return v;
}

Song *sortare(Song *v, int n)
{
    Song aux;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if((v + i)->an > (v + j)->an)
            {
                strcpy(aux.nume, (v + i)->nume);
                strcpy((v + i)->nume, (v + j)->nume);
                strcpy((v + j)->nume, aux.nume);
                strcpy(aux.compozitor, (v + i)->compozitor);
                strcpy((v + i)->compozitor, (v + j)->compozitor);
                strcpy((v + j)->compozitor, aux.compozitor);
                aux.an = (v + i)->an;
                (v + i)->an = (v + j)->an;
                (v + j)->an = aux.an;
            }
        }
    }
    return v;
}

void afisare(Song *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Numele piesei cu numarul %d: %s\tIntordu numele compozitorului: %s\tIntrodu anul aparitiei: %d\n", i + 1, (v + i)->nume, (v + i)->compozitor, (v + i)->an);
    }
}

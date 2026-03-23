#include <stdio.h>
#include <string.h>
void swap(char*, char*);
void permute(char*, int, int);

int main()
{
    char string[] = "ABC";
    permute(string, 0, strlen(string) - 1);
    return 0;
}

void swap(char *x, char *y)
{
    char temp = '\0';
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int current, int size)
{
    int i = 0;
    if(current == size) printf("%s\t", a);
    else
        for(i = current; i <= size; i++)
        {
            swap((a + current), (a + i));
            permute(a, current + 1, size);
            swap((a + current), (a + i));
        }
}

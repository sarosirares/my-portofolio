#include <stdio.h>
int main()
{
    char name[50] = "";
    char cp[100] = "";

    printf("What is your name?\n");
    gets(name);
    printf("----------------------\n");
    printf("Well, %s, what do you study?\n", name);
    gets(cp);
    printf("----------------------\n");
    puts("Let me see if I got it: ");
    puts(name);
    puts("studies");
    puts(cp);
    return 0;
}

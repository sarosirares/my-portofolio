#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[10];
    strncpy(s, "computer", 9);
    printf("%s\n", s);

    if(strchr(s, 'c'))
    {
        printf("\'%c\' was found in \"%s\".\n", 'c', s);
    }
    return 0;
}

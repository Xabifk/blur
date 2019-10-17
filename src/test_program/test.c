#include <stdio.h>

int main()
{
    int x, command;
    char s[100];

    printf("%llx\n", &s);

    while(1)
    {
        scanf("%d", &command);
        
        if(command == 0)
        {
            scanf("%s %d", s, &x);
        }
        else
        {
            printf("%s %d\n", s, x);
        }
    }
    return 0;
}
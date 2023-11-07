#include "shell.h"

void freearrayofstring(char **arr)
{
    int i;
    if (!arr)
        return;
        
    for (i = 0; command[i]; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }
    
    free(arr), arr = NULL;
}

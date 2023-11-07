#include "shell.h"

int _execute(char **command, char *argv)
{
    char *full_cmd;
    pid_t child;
    int status;

    full_cmd = _getpath(command[0]);
    if (!full_cmd)
    {
        printerror(argv[0], command[0], idx);
        freearrayofstring(command);
        return(127);
    }
    
    child = fork();
    if (child == 0)
    {
        if(execve(full_cmd, command, environ) == -1)
        {
            free(full_cmd), full_cmd = NULL;
            freearrayofstring(command);
        }
        freearrayofstring(command);
    }
    else
    {
        waitpid(child, &status, 0);
        freearrayofstring(command);
        free(full_cmd), full_cmd = NULL;
    }
    return(WEXITSTATUS(status))
}

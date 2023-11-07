#include "shell.h"

/**
 * main - entry point
 * @argc: count the arguments
 * @argv: main arguments
 * Return: status
*/

int main(int ac, char **argv, char **env)
{
  char *line = NULL, **command  = NULL;
  int status = 0, idx = 0;
  (void) ac;


  while (1)
  {
      line = get_line();
      if (line == NULL) /* Reach End Of File (Ctrl + D) */
      {
          if (isatty(STDIN_FILENO))
              write(STDOUT_FILENO, "\n", 1);
          return (status);
      }
      idx++;
      command = tokenizer(line);
      if (!command)
          continue;


      status = _execute(command, argv, idx);
  }

}

    

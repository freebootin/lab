#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
  char my_str[] = "Drink Coffee Then Derp";

  char *s;


  for (s = my_str; (s = strtok(s, " ")) != NULL; s = NULL) {
    printf("%s\n", s);
  }

  return 0;
}

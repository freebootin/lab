#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
  char my_str[] = "Drink Coffee Then Derp";

  char *s;


  /* char *strtok(char *s1, const char *s2)
   * s1 is the string you want to parse, s2 is the string of delimiters you want
   * to parse with. for whitespace you can use " \t\n". 
   *
   * After the first call to strtok, you need to change s1 to NULL if you want to
   * keep parsing the same string. When strtok returns NULL, the parsing is done.
   */
  for (s = my_str; (s = strtok(s, " ")) != NULL; s = NULL) {
    printf("%s\n", s);
  }

  return 0;
}

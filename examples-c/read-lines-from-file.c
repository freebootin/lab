/* How to read one line from a file using fgets */

#include <stdio.h> /* required for fopen, fclose, puts */
#include <stdlib.h> /* required for malloc() */

int main(int argc, char *argv[])
{
  FILE *fp;
  char *str;
  int buffer_size = 64;

  /* Try to open the file, checking to make sure it actually opened */
  fp = fopen("lines", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return(-1);
  }

  /* Gotta allocate memory for your buffer.  This could be done in the
   * declaration, but malloc is more flexible. Plus I'm gonna have to
   * learn to use malloc later anyway. Remember to typecast malloc's 
   * return value to the same type as your array. In this case (char *).
   */
  str = (char *)malloc(buffer_size * sizeof(char));

  /* fgets( char *str, int buffer_size, *fp)
   * Make sure *str is at least as large as buffer_size or you are going
   * to run into segmentation faults.  This is also why we have the call
   * to malloc earlier. 
   *
   * Test the return value of fgets against NULL. If nothing is read then
   * fgets returns NULL. Thats how you know its the end of the file.
   */
  while (fgets(str, buffer_size, fp) != NULL) {
    printf("%s", str);
  }

  /* Remember to close the file */
  fclose(fp);

  return 0;
}

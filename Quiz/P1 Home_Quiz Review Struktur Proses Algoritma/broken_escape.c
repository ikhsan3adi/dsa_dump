#include <stdio.h>

int main(int argc, char const *argv[])
{
  FILE *fp;
  fp = fopen("..\q\source.txt", "r"); //! seharusnya menggunakan double backslash '\\' atau slash '/'

  if (!fp)
  {
    printf("Unable to open file");
  }
  printf("%c", fgetc(fp));
  fclose(fp);
  return 0;
}

#include <stdio.h>

int main(void)
{
  int a = 0, b = 0, c = 0;
  FILE *fp;

  if ( (fp = fopen("input.txt", "r")) != NULL ) {
    while ( fscanf(fp, "%d%d%d", &a, &b, &c) != EOF ) {
      if ( a != b && b == c ) {
        printf("A\n");
      } else if ( b != a && a == c ) {
        printf("B\n");
      } else if ( c != a && a == b ) {
        printf("C\n");
      } else {
        printf("*\n");
      }
    }
    fclose(fp);
  }
  return 0;
}

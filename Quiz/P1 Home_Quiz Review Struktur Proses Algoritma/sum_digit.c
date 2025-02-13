#include <stdio.h>
#include <stdlib.h>

int sumdig(int);

int main(int argc, char const *argv[])
{
  int a, b;
  a = sumdig(1234);
  b = sumdig(123);
  printf("%d, %d", a, b);
  return 0;
}

int sumdig(int n)
{
  int s, d;
  if (n != 0)
  {
    d = n % 10;
    n = n / 10;
    s = d + sumdig(n);
  }
  else
  {
    return 0;
  }
  return s;
}
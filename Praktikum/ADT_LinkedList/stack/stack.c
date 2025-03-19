#include <stdio.h>
#include "stack.h"

infotype pop(address *p)
{
  return delete_awal(p);
}

void push(address *p, infotype nilai)
{
  insert_awal(p, nilai);
}

void tampil_stack(address *s)
{
  while (*s != Nil)
  {
    printf("%d ", pop(s));
  }
}
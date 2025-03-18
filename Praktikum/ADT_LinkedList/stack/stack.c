#include "stack.h"

void pop(address *p)
{
  delete_awal(p);
}

void push(address *p, infotype nilai)
{
  insert_awal(p, nilai);
}

#include "stack.h"

infotype pop(address *p)
{
  return delete_awal(p);
}

void push(address *p, infotype nilai)
{
  insert_awal(p, nilai);
}

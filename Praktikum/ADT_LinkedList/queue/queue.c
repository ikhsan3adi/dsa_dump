#include "queue.h"

void enqueue(address *p, infotype nilai)
{
  insert_akhir(p, nilai);
}

void dequeue(address *p)
{
  delete_awal(p);
}

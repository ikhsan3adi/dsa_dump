#include <stdio.h>
#include "queue.h"

void enqueue(address *p, infotype nilai)
{
  insert_akhir(p, nilai);
}

void dequeue(address *p)
{
  delete_awal(p);
}

void tampil_queue(address q)
{
  if (q != Nil)
  {
    printf("%d", info(q));

    if (q->next != Nil)
    {
      printf(" <- ");
    }

    tampil_queue(next(q));
  }
}
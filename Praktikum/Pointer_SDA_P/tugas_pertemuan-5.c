#include <stdlib.h>
#include <stdio.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL
#define true 1
#define false 0

typedef int bool;

typedef char infotype;

typedef struct tElmtlist *address;

typedef struct tElmtlist
{
  infotype info;
  address next;
} ElmtList;

void tampil_list(address p);
void delete_akhir(address p);
bool cari_node(address p, infotype nilai);

int main(int argc, char const *argv[])
{
  /// kamus data
  address First, P, Q;
  infotype search;

  /// program
  // buat node
  First = malloc(sizeof(ElmtList));
  First->info = 'J';
  First->next = Nil;

  P = malloc(sizeof(ElmtList));
  P->info = 'T';
  P->next = Nil;

  Q = malloc(sizeof(ElmtList));
  Q->info = 'K';
  Q->next = Nil;

  // susun node
  First->next = P;
  P->next = Q;

  tampil_list(First);

  // hapus node akhir
  delete_akhir(First);

  printf("Setelah hapus node akhir: \n");
  tampil_list(First);

  // cari
  printf("Cari node: ");
  scanf("%c", &search);

  bool ketemu = cari_node(First, search);

  printf("Cari %c. ketemu: %s\n", search, ketemu ? "True" : "False");

  return 0;
}

void delete_akhir(address p)
{
  if (p == Nil)
  {
    printf("Linked list kosong!\n");
    return;
  }

  address prev_cursor = p;
  address next_cursor = p;

  while (true)
  {
    if (next(next_cursor) == Nil)
    {
      free(next_cursor);
      next(prev_cursor) = Nil;
      break;
    }

    prev_cursor = next_cursor;
    next_cursor = next(next_cursor);
  }
}

bool cari_node(address p, infotype nilai)
{
  address cursor = p;

  while (cursor != Nil)
  {
    if (cursor->info == nilai)
    {
      return true;
    }

    cursor = cursor->next;
  }

  return false;
}

void tampil_list(address p)
{
  if (p != Nil)
  {
    printf("%c -> ", info(p));
    tampil_list(next(p));
  }
  else
  {
    printf("Nil\n");
  }
}
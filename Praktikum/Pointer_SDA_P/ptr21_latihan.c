#include <stdio.h>
#include <stdlib.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef char infotype;

typedef struct tElmtlist *address;

typedef struct tElmtlist
{
  infotype info;
  address next;
} ElmtList;

void tampil_list(address p);

void insert_awal(address *p, infotype nilai);
void insert_akhir(address p, infotype nilai);
void insert_tengah(address p, infotype nilai);

void update_awal(address p, infotype nilai);
void update_akhir(address p, infotype nilai);
void update_tengah(address p, infotype nilai);

void delete_awal(address *p);
void delete_akhir(address p);
void delete_tengah(address p);

int main()
{
  /// kamus data
  address First;

  /// program
  First = Nil;

  printf("Initial\n");

  insert_awal(&First, 'A');
  insert_tengah(First, 'A');
  insert_akhir(First, 'A');

  tampil_list(First);

  printf("\nUpdate tengah\n");
  update_tengah(First, 'T');
  tampil_list(First);

  printf("\nUpdate awal\n");
  update_awal(First, 'J');
  tampil_list(First);

  printf("\nUpdate akhir\n");
  update_akhir(First, 'K');
  tampil_list(First);

  printf("\nDelete tengah\n");
  delete_tengah(First);
  tampil_list(First);

  printf("\nDelete akhir\n");
  delete_akhir(First);
  tampil_list(First);

  printf("\nDelete awal\n");
  delete_awal(&First);
  tampil_list(First);

  return 0;
}

void tampil_list(address p)
{
  if (p != NULL)
  {
    printf("%c -> ", info(p));
    tampil_list(next(p));
  }
  else
  {
    printf("Nil\n");
  }
}

void insert_awal(address *p, infotype nilai)
{
  // buat / alokasi
  address new_element;
  new_element = malloc(sizeof(ElmtList));

  // beri nilai
  info(new_element) = nilai;

  // posisikan
  next(new_element) = *p;
  *p = new_element;
}

void insert_akhir(address p, infotype nilai)
{
  if (p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }

  // buat / alokasi
  address new_element;
  new_element = malloc(sizeof(ElmtList));

  // beri nilai
  info(new_element) = nilai;

  // posisikan
  next(next(p)) = new_element;
}

void insert_tengah(address p, infotype nilai)
{
  if (p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }

  // buat / alokasi
  address new_element;
  new_element = malloc(sizeof(ElmtList));

  // beri nilai
  info(new_element) = nilai;

  // posisikan
  next(p) = new_element;
}

void update_awal(address p, infotype nilai)
{
  info(p) = nilai;
}

void update_akhir(address p, infotype nilai)
{
  info(next(next(p))) = nilai;
}

void update_tengah(address p, infotype nilai)
{
  info(next(p)) = nilai;
}

void delete_awal(address *p)
{
  if (p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }

  // simpan first ke temp
  address temp = *p;

  // assign p dengan p->next
  (*p) = (*p)->next;

  // hapus
  free(temp);
}

void delete_akhir(address p)
{
  if (p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }

  address prev_cursor = p;
  address next_cursor = p;
  while (1)
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

void delete_tengah(address p)
{
  // simpan elemen tengah ke temp
  address temp = next(p);

  next(p) = next(temp);

  // hapus / dealokasi
  free(temp);
}

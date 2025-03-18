#include "single_linked_list.h"

#include <stdio.h>

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

void insert_akhir(address *p, infotype nilai)
{
  address new_element = malloc(sizeof(ElmtList));
  if (new_element == Nil)
  {
    printf("Gagal mengalokasikan memori!\n");
    return;
  }
  info(new_element) = nilai;
  next(new_element) = Nil;

  if (*p == Nil)
  {
    *p = new_element;
    return;
  }

  address temp = *p;
  while (next(temp) != Nil)
  {
    temp = next(temp);
  }
  next(temp) = new_element;
}

void insert_tengah(address *p, infotype nilai, int posisi)
{
  if (posisi <= 1)
  {
    insert_awal(p, nilai);
    return;
  }

  address new_element = malloc(sizeof(ElmtList));
  if (new_element == Nil)
  {
    printf("Gagal mengalokasikan memori!\n");
    return;
  }
  info(new_element) = nilai;

  address temp = *p;
  int count = 1;
  while (temp != Nil && count < posisi - 1)
  {
    temp = next(temp);
    count++;
  }

  if (temp == Nil)
  {
    printf("Posisi tidak valid!\n");
    free(new_element);
    return;
  }

  next(new_element) = next(temp);
  next(temp) = new_element;
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

void update_awal(address p, infotype nilai)
{
  info(p) = nilai;
}

void update_akhir(address p, infotype nilai)
{
  if (p == Nil)
  {
    printf("Linked list kosong!\n");
    return;
  }

  // Mencari elemen terakhir
  while (next(p) != Nil)
  {
    p = next(p);
  }

  // Memperbarui nilai elemen terakhir
  info(p) = nilai;
}

void update_tengah(address p, infotype nilai, int posisi)
{
  int count = 1;
  while (p != Nil && count < posisi)
  {
    p = next(p);
    count++;
  }
  if (p != Nil)
  {
    info(p) = nilai;
  }
  else
  {
    printf("Posisi tidak valid!\n");
  }
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

void delete_akhir(address *p)
{
  if (*p == Nil)
    return;
  if (next(*p) == Nil)
  {
    free(*p);
    *p = Nil;
    return;
  }
  address prev = Nil, temp = *p;
  while (next(temp) != Nil)
  {
    prev = temp;
    temp = next(temp);
  }
  next(prev) = Nil;
  free(temp);
}

void delete_tengah(address *p, int posisi)
{
  if (*p == Nil || posisi <= 1)
  {
    delete_awal(p);
    return;
  }

  address prev = Nil, temp = *p;
  int count = 1;
  while (temp != Nil && count < posisi)
  {
    prev = temp;
    temp = next(temp);
    count++;
  }

  if (temp == Nil)
  {
    printf("Posisi tidak valid!\n");
    return;
  }

  next(prev) = next(temp);
  free(temp);
}
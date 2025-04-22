#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "kota_penduduk.h"

void insert_kota(address_kota *head, infotype data)
{
  address_kota new = malloc(sizeof(Kota));

  if (new == NULL)
    return;

  strcpy(new->info, data);
  new->next_kota = NULL;
  new->next_penduduk = NULL;

  new->next_kota = (*head);
  (*head) = new;
}

void insert_penduduk(address_kota *head, infotype kota, infotype data)
{
  if ((*head) == NULL)
    return;

  address_kota pKota = cari_kota((*head), kota);

  if (pKota == NULL)
    return;

  address_penduduk new = malloc(sizeof(Penduduk));

  if (new == NULL)
    return;

  strcpy(new->info, data);
  new->next = NULL;

  new->next = pKota->next_penduduk;
  pKota->next_penduduk = new;
}

void delete_kota(address_kota *head, infotype kota)
{
  if ((*head) == NULL)
    return;

  bool is_first = true;
  address_kota *prev = head;
  address_kota curr = (*head);

  while (curr != NULL)
  {
    if (curr != NULL && strcmp(curr->info, kota) == 0)
    {
      if (is_first)
        (*head) = curr->next_kota;

      (*prev)->next_kota == curr->next_kota;

      curr->next_kota = NULL;
      free(curr);

      return;
    }

    prev = &curr;
    curr = curr->next_kota;
    is_first = false;
  }

  // tidak ada yang dihapus (kota tidak ditemukan)
}

void delete_penduduk(address_kota *head, infotype kota, infotype penduduk)
{
  if ((*head) == NULL)
    return;

  // cari kota
  address_kota pKota = cari_kota((*head), kota);

  bool is_first = true;
  address_penduduk prev = pKota->next_penduduk;
  address_penduduk curr = pKota->next_penduduk;

  while (curr != NULL)
  {
    if (curr != NULL && strcmp(curr->info, penduduk) == 0)
    {
      if (is_first)
        pKota->next_penduduk = curr->next;

      prev->next == curr->next;

      curr->next = NULL;
      free(curr);

      return;
    }

    prev = curr;
    curr = curr->next;
    is_first = false;
  }

  // tidak ada yang dihapus (penduduk tidak ditemukan)
}

// pakai rekursif
void tampil_kota(address_kota head)
{
  if (head == NULL)
    return;

  printf("%s\n", head->info);
  tampil_kota(head->next_kota);
}

// pakai looping
void tampil_penduduk(address_kota head, infotype kota)
{
  // cari kota
  address_kota pKota = cari_kota(head, kota);

  if (pKota == NULL)
  {
    printf("Kota tidak ditemukan!\n");
    return;
  }
  address_penduduk cursorP = pKota->next_penduduk;

  while (cursorP != NULL)
  {
    printf("%s\n", cursorP->info);

    cursorP = cursorP->next;
  }
}

address_kota cari_kota(address_kota head, infotype kota)
{
  address_kota prev = head;
  address_kota curr = head;

  while (curr != NULL)
  {
    if (curr != NULL && strcmp(curr->info, kota) == 0)
      return curr;

    prev = curr;
    curr = curr->next_kota;
  }
}

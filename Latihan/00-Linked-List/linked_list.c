#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "linked_list.h"

void Create_Node(address *p)
{
  *p = malloc(sizeof(Node));
}

void Isi_Node(infotype nilai, address *p)
{
  (*p)->info = nilai;
}

void Tampil_List(address p)
{
  if (p != NULL)
  {
    printf("%d -> ", p->info);
    Tampil_List(p->next);
  }
  else
  {
    printf("NULL");
  }
}

void Add_Awal(address *p, int nilai)
{
  address new_node;
  Create_Node(&new_node);
  Isi_Node(nilai, &new_node);

  new_node->next = *p;
  *p = new_node;
}

void Add_Akhir(address *p, int nilai)
{
  if (*p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }
  address new_node;
  Create_Node(&new_node);
  Isi_Node(nilai, &new_node);

  address cursor = *p;
  while (true)
  {
    if (cursor->next == NULL)
    {
      cursor->next = new_node;
      break;
    }

    cursor = cursor->next;
  }
}

void Add_Tengah(address *p, int nilai, int posisi)
{
  if (*p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }
  address cursor = *p;
  int i = 1;
  while (i < posisi)
  {
    if (cursor->next == NULL)
    {
      printf("Posisi %d tidak ditemukan", posisi);
      break;
    }

    if (i == posisi - 1)
    {
      address new_node;
      Create_Node(&new_node);
      Isi_Node(nilai, &new_node);

      new_node->next = cursor->next;
      cursor->next = new_node;
      break;
    }

    cursor = cursor->next;
    i++;
  }
}

address cari_Node(address p, infotype nilai)
{
  if (p == NULL)
  {
    printf("Linked list kosong!\n");
    return NULL;
  }
  address cursor = p;
  while (true)
  {
    if (cursor->info == nilai)
      return cursor;

    cursor = cursor->next;
  }
  return NULL;
}

void hapus_NodeAwal(address *p)
{
  if (*p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }
  address temp = *p;
  (*p) = (*p)->next;
  free(temp);
}
void hapus_NodeAkhir(address *p)
{
  if (*p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }
  address cursor = *p;
  while (true)
  {
    if (cursor->next->next == NULL)
    {
      free(cursor->next);
      cursor->next = NULL;
      break;
    }

    cursor = cursor->next;
  }
}
void hapus_Node(address *p, int posisi)
{
  if (*p == NULL)
  {
    printf("Linked list kosong!\n");
    return;
  }
  address cursor = *p;
  int i = 1;
  while (i < posisi)
  {
    if (cursor->next == NULL)
    {
      printf("Posisi %d tidak ditemukan", posisi);
      break;
    }

    if (i == posisi - 1)
    {
      free(cursor->next);
      cursor->next = cursor->next->next;
      break;
    }

    cursor = cursor->next;
    i++;
  }
}

int sum_Node(address p)
{
  int sum = 0;
  address cursor = p;
  while (cursor != NULL)
  {
    sum = sum + cursor->info;
    cursor = cursor->next;
  }
  return sum;
}

int jum_Node(address p)
{
  int count = 0;
  address cursor = p;
  while (cursor != NULL)
  {
    count++;
    cursor = cursor->next;
  }
  return count;
}
int node_Max(address p)
{
  int max = INT_MIN;
  address cursor = p;
  while (cursor != NULL)
  {
    if (cursor->info > max)
    {
      max = cursor->info;
    }
    cursor = cursor->next;
  }
  return max;
}
float rata2_Node(address p)
{
  int sum_node = sum_Node(p);
  int jumlah_node = jum_Node(p);

  return (float)sum_node / (float)jumlah_node;
}

void tukar_Node(address *p)
{
}
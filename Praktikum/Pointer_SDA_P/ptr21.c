/*----------------------------------------------------------------------------*/
/* File : ptr21.c */
/* Deskripsi : contoh deklarasi list dan pemakaian makro */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

/*Definisi akses komponen type, standard kuliah Algoritma dan pemrograman*/
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

/* Definisi TYPE global (sebenarnya untuk soal ini tidak perlu global) */
/* Element list linier */
typedef int infotype;

typedef struct tElmtlist *address;

typedef struct tElmtlist
{
  infotype info;
  address next;
} ElmtList;

void print_all_node(address);

/* Program Utama */
int main()
{
  /* kamus */
  address First;
  address P, Q, X;

  /* program */
  /* Create list kosong */
  First = Nil;

  /* Alokasi, insert as first elemen */
  P = (address)malloc(sizeof(ElmtList));
  info(P) = 10;
  next(P) = Nil;
  First = P;

  /* Alokasi, insert as first elemen */
  Q = (address)malloc(sizeof(ElmtList));
  info(Q) = 20;
  next(Q) = Nil;
  next(Q) = First;
  First = Q;

  /* Alokasi, insert as first elemen */
  P = (address)malloc(sizeof(ElmtList));
  info(P) = 30;
  next(P) = Nil;
  next(P) = First;
  First = P;

  /* Alokasi, insert as first elemen */
  X = (address)malloc(sizeof(ElmtList));
  info(X) = 40;
  next(X) = Nil;
  next(X) = First;
  First = X;

  /* Alokasi, insert as last elemen */
  X = (address)malloc(sizeof(ElmtList));
  info(X) = 0;
  next(X) = Nil;
  next(next(next(next(First)))) = X;

  // masukkan 25 diantara 30 dan 20
  /* Alokasi, insert ditengah */
  X = (address)malloc(sizeof(ElmtList));
  info(X) = 25;
  next(X) = Nil;
  next(X) = Q;
  next(P) = X;

  print_all_node(First); // cetak semua info

  return 0;
}

// Cetak semua info elemen menggunakan rekursif
void print_all_node(address C)
{
  if (C->next != Nil)
  {
    printf("Info: %d\n", C->info);
    print_all_node(C->next);
  }
}
/* -------------------------------------------------------------------------------- */
/* File Program : ptr8a.c */
/* (Pointer dan String bagian ke-2) */
/* Deskripsi : menukar isi dua buah string TANPA pemakaian pointer */
/* ------------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>

#define PANJANG 20

int main()
{
  /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
  char nama1[PANJANG] = "DEWI SARTIKA";
  char nama2[PANJANG] = "SULTAN HASANUDDIN";
  char namaX[PANJANG];
  puts("Nama semula : ");
  printf("Nama 1 --> %s\n", nama1);
  printf("Nama 2 --> %s\n", nama2);

  /* Pertukaran string */
  strcpy(namaX, nama1); // menyalin string nama1 ke namaX
  strcpy(nama1, nama2); // menyalin nama2 ke nama1
  strcpy(nama2, namaX); // menyalin namaX ke nama2
  puts("Nama sekarang : ");
  printf("Nama 1 --> %s\n", nama1);
  printf("Nama 2 --> %s\n", nama2);

  return 0;
}
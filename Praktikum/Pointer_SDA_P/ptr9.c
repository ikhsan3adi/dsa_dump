/* -------------------------------------------------- */
/* File Program : ptr9.c */
/* Deskripsi : pointer yang menunjuk pointer */
/* -------------------------------------------------- */
#include <stdio.h>
int main()
{
  /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
  int var_x = 273;
  int *ptr1;  /* ptr1 adl pointer yang menunjuk ke objek bertipe integer */
              /* (Boleh disebut pointer integer saja) */
  int **ptr2; /* ptr2 adl pointer yang menunjuk ke pointer yang menunjuk */
              /* ke objek bertipe integer (Boleh disebut : pointer menunjuk ke pointer integer saja) */

  ptr1 = &var_x;
  ptr2 = &ptr1;

  /* Mengakses nilai var_x melalui ptr1 dan ptr2 */
  printf("Nilai var_x = %d\n", *ptr1);
  printf("Nilai var_x = %d\n", **ptr2);

  return 0;
}

/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini dan */
/* komentari setiap baris programnya (mulai dari baris ptr1= &var_x; ) */
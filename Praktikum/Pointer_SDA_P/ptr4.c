/* --------------------------------------------------------- */
/* File Program : ptr4.c  */
/* Contoh pemakaian pointer */
/* --------------------------------------------------------- */

#include <stdio.h>

int main()
{
  // kamus data
  int z, s, *pz, *ps;

  // assignment ke z dan s
  z = 20;
  s = 30;

  pz = &z;         // assign pz dengan alamat dari z
  ps = &s;         // assign ps dengan alamat dari s
  *pz = *pz + *ps; // assign nilai yang ditunjuk pz dengan nilai yang ditunjuk pz ditambah nilai yang ditunjuk ps

  printf("z = %d, s = %d\n", z, s);

  return 0;

  /* STUDI KASUS : */
  /* - Eksekusi file program tersebut dan pahami maksud program ini */
  /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
  /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}
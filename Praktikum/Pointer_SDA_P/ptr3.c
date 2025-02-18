/* --------------------------------------------------------- */
/* File Program : ptr3.c */
/* Contoh pengubahan isi suatu variabel melalui pointer */
/* Tujuan : Menggunakan type data pointer dan manipulasinya */
/* --------------------------------------------------------- */

#include <stdio.h>

int main()
{
  // kamus data
  float d, *pd;
  d = 54.5;

  printf("Isi d semula = %g\n", d);

  pd = &d;        // assign alamat `d` ke `pd`
  *pd = *pd + 10; // assign ke variabel yang ditunjuk `pd` dengan nilai yang ditunjuk `pd` ditambah 10

  printf("Isi d kini = %g\n", d);

  return 0;

  /* STUDI KASUS : */
  /* - Eksekusi file program tersebut dan pahami maksud program ini */
  /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
  /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}
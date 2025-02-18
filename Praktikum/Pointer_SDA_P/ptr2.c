/* --------------------------------------------------------- */
/* File Program : ptr2.c */
/* Contoh pemakaian pointer yang salah */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */

#include <stdio.h>

int main()
{
  float *pu;    // deklarasi variabel pointer
  float nu;     // deklarasi variabel float
  int u = 1234; // inisialisasi variabel integer u
  pu = &u;      //! assignment gagal karena tipe data `u` (integer) berbeda dengan tipe yang ditunjuk `pu` (float)
  nu = *pu;
  printf("u = %d\n", u);
  printf("nu = %f\n", nu);

  return 0;

  /* STUDI KASUS : */
  /* - Eksekusi file program tersebut dan pahami maksud program ini */
  /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
  /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}
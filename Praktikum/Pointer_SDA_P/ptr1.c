/* --------------------------------------------------------- */
/* File Program : ptr1.c */
/* Contoh pemakaian pointer */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */

#include <stdio.h>

int main()
{
  // Kamus data
  int x, y; // deklarasi variabel x,y
  int *px;  // deklarasi variabel bertipe pointer

  x = 87; // beri nilai x

  px = &x; // beri nilai px dengan alamat dari variabel x

  // beri nilai y dengan nilai dari variabel yang ditunjuk oleh px, yaitu x
  y = *px; // tanda * di belakang adalah dereference, untuk mengambil nilai dari alamat yang ditunjuk

  printf("Alamat x = %p\n", &x);
  printf("Isi px = %d\n", x);
  printf("Nilai yang ditunjuk oleh px = %d\n", *px);
  printf("Nilai y = %d\n", y);

  return 0;

  /* STUDI KASUS : */
  /* - Eksekusi file program tersebut dan pahami maksud program ini */
  /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
  /* - Tambahkan pernyataan untuk menampilkan Alamat varabel y, eksekusi, dan perhatikan hasilnya */
  /* - Bila pernyataan px = &x; diganti dengan y = *px; ,apa yang terjadi? */
  /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}

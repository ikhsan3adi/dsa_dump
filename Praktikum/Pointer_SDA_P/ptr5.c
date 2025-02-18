/* --------------------------------------------------------------------------------------------- */
/* File Program : ptr5.c */
/* Deskripsi : pointer ke type dasar, mendeklarasikan & alokasi variabel dinamik */
/* --------------------------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

int main()
{
  /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
  int i = 5, j;
  char c = 'X';
  int *Ptri = (int *)malloc(4);               // memory allocation sebesar 4 bytes dan
                                              // di casting ke pointer integer (int *)
  int *Ptrj = (int *)malloc(sizeof(int));     // alokasi memori sebesar ukuran tipe integer (4 bytes)
  float *fx = (float *)malloc(sizeof(float)); // alokasi memori sebesar ukuran tipe float
  int A[5];
  float f = 7.23;

  /* program */
  *Ptri = 8; // assign value dari nilai yang ditunjuk Ptri
  *Ptrj = 0; // assign value dari nilai yang ditunjuk Ptrj
  *fx = 3;   // assign value dari nilai yang ditunjuk fx

  printf("Alamat i = %x \n", &i);
  printf("Nilai i = %d \n", i);
  printf("Ukuran int = %d byte\n\n", sizeof(int));
  printf("Alamat j = %x \n", &j);
  printf("Nilai j = %d \n", j);
  printf("Alamat c = %x \n", &c);
  printf("Nilai c = %c \n", c);
  printf("Ukuran char = %d byte\n\n", sizeof(char));
  printf("Alamat Ptri = %x \n", &Ptri);
  printf("Isi var Ptri = %x \n", Ptri);
  printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri);
  printf("Ukuran pointer int = %d byte\n\n", sizeof(int *));
  printf("Alamat Ptrj = %X \n", &Ptrj);
  printf("Isi var Ptrj = %x \n", Ptrj);
  printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj);

  Ptrj = Ptri; // assign variabel Ptrj dengan Ptri

  printf("Isi var Ptrj sekarang = %x \n", Ptrj);
  printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj);
  printf("Alamat A = %x \n", &A);
  printf("Isi var A = %x \n", A[0]);
  printf("Ukuran array A = %d byte\n\n", sizeof(A));
  printf("Alamat f = %x \n", &f);
  printf("Nilai f = %f \n", f);
  printf("Ukuran float = %d byte\n\n", sizeof(float));

  return 0;
}
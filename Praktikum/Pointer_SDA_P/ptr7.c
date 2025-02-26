/* ----------------------------------------------------------- */
/* File Program : ptr7.c */
/* (Pointer dan String bagian ke-1) */
/* Deskripsi : pointer yang menunjuk ke data string */
/* ---------------------------------------------------------- */
#include <stdio.h>

int main()
{
  /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
  // char *pkota = "BANDUNG";
  char pkota[] = "BANDUNG";

  /// Perbedaan `char *pkota = "BANDUNG";` dengan `char pkota[] = "BANDUNG";` yaitu
  /// array akan bersifat dinamis jika menggunakan pointer,
  /// sedangkan jika menggunakan [] array akan bersifat statis

  puts(pkota);
  return 0;
}

/* STUDI KASUS : */
/* Apa perbedaan deklarasi variabel char *pkota='BANDUNG'; dengan char kota[]='BANDUNG' ? */
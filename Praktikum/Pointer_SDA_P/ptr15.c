/* ---------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR15.CPP */
/* Deskripsi : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya */
/* ---------------------------------------------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>

int main()
{
  /* kamus */
  /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
  static char *s[3] = {"the", "time", "is"}; // buat array bertipe char pointer (string) yang bersifat statik

  /* Definisi array yang elemennya string, dinamik */
  char *(*TabStr); /* Deklarasi array of string */

  int i;

  /* program */
  for (i = 0; i < 3; i++)
  { // cetak isi s
    printf("%s\n", s[i]);
  }

  /* Alokasi TabStr sebanyak 3 */
  TabStr = (char **)malloc(3 * sizeof(char *));

  for (i = 0; i < 3; i++)
  {
    /* Alokasi string yang merupakan elemen tabel */
    *(TabStr + i) = (char *)malloc(5 * sizeof(char)); // alokasi sebanyak 5 karakter

    printf("\nInput Str[%d], maksimum 5 karakter : ", i);

    // isi array TabStr denan input pengguna
    scanf("%5s", *(TabStr + i)); /* Mengisi nilai string */

    printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i));
  }

  return 0;
}
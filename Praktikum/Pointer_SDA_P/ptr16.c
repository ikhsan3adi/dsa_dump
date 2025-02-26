/* ---------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR16CPP */
/* Deskripsi : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya */
/* Jelaskan perbedaannya dengan program PTR15.cpp! */
/* ---------------------------------------------------------------------------------------------------------------- */
#include <stdlib.h>

#define STRING char *

int main()
{
  /* kamus */
  /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
  static STRING s[3] = {"the", "time", "is"};
  /* Definisi array yang elemennya string, dinamik */
  STRING(*TabStr); /* Deklarasi array of string */

  int i;
  /* program */
  for (i = 0; i < 3; i++)
  { /* Print isi s */
    printf("%s\n", s[i]);
  }

  /* Alokasi TabStr sebanyak 3 */
  TabStr = (STRING *)malloc(3 * sizeof(STRING));
  for (i = 0; i < 3; i++)
  {
    /* Alokasi string yang merupakan elemen tabel */
    *(TabStr + i) = (STRING)malloc(5 * sizeof(char));
    printf("\nInput Str[%d], maksimum 5 karakter : ", i);
    scanf("%5s", *(TabStr + i)); /* Mengisi nilai string */
    printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i));
  }
  return 0;
}

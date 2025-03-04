/*---------------------------------------------------------------------------*/
/* File : ptr20.c */
/* Deskripsi : contoh pendefinisian struct dan pointer ke struct */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
  /* kamus */

  /* cara 3 : INI yang membuat TYPE baru */
  typedef struct
  {
    float x;
    float y;
  } Point;                                    /* nama type */
  Point *P2;                                  /* deklarasi pointer ke struct */
  Point *P3 = (Point *)malloc(sizeof(Point)); /* deklarasi alokasi */

  /* program */
  /* Cara 1 : mengacu elemen pointer ke struct */
  printf("Titik P2, dengan P2->x dan P2->y : \n");

  P2 = (Point *)malloc(sizeof(Point)); /* Alokasi */

  /* Isi nilai komponen */
  P2->x = 9.12;
  P2->y = 2.567;

  printf("P2.x = %f \nP2.y = %f \n", P2->x, P2->y);

  /* Cara 2 : Perhatikanlah tanda kurung, lihat prioritas () dibuku TC */
  /* Mendefinisikan isi */
  (*P3).x = 0.5;
  (*P3).y = 10.5;

  printf("P3.x = %f \nP3.y = %f \n", (*P3).x, (*P3).y);

  return 0;
}
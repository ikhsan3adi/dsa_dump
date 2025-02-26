/* --------------------------------------------------------------------------------------------------------- */
/* File Program : PTR19.CPP */
/* Deskripsi : Maksud program sama dengan PTR18.cpp. Cari perbedaannnya! */
/* --------------------------------------------------------------------------------------------------------- */
#include <stdlib.h>

/* Definisi tabel integer */
typedef struct
{
  int *tab; /* array integernya */
  int N;    /* Ukuran efektif */
} tabint;

/* Prototype */
void incTab(tabint *T);  /* Increment setiap elemen tabel */
void printTab(tabint T); /* Print tabel */

int main()
{ /* kamus */
  tabint T;
  int i;

  /* program */
  T.tab = (int *)malloc(3 * sizeof(int));
  T.N = 3;

  printf("Isi dan print tabel untuk indeks 1..3 \n");

  for (i = 0; i < T.N; i++)
  { /* isi dari pembacaan */
    printf("Input tabel ke -[%d] = ", i);
    scanf("%d", &(T.tab[i]));
  };

  printTab(T); /* Print : perhatikan passing parameter by value */
  incTab(&T);  /* Increment : perhatikan passing parameter by reference */
  printTab(T);

  return 0;
}

/* Body prototype */
void incTab(tabint *T) /* Increment setiap elemen tabel */
{
  /* Kamus lokal */
  int i;

  /* Program */
  for (i = 0; i < (*T).N; i++)
  {
    (*T).tab[i] = (*T).tab[i] + 1;
  }
}

void printTab(tabint T) /* Print setiap elemen tabel */
{                       /* Kamus lokal */
  int i;

  /* Program untuk traversal print */
  for (i = 0; i < T.N; i++)
  {
    printf("T[%d] = %d \n", i, T.tab[i]);
  }
}
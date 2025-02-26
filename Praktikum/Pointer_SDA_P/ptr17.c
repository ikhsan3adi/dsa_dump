/* --------------------------------------------------------------------------------------------------------- */
/* File Program : PTR17.CPP */
/* Deskripsi : Array dengan def type:mengisi dg assignment, menulis */
/* --------------------------------------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>

int main()
{
  /* kamus */
  /* Definisi tabel integer */
  typedef struct // Definisi struktur/record bernama `tabint`
  {
    int *T; /* array integernya */
    int N;  /* Ukuran efektif */
  } tabint;

  tabint MyTab; // deklarasi variabel bertipe tabint MyTab

  int i;

  /* program */
  printf("Tentukan ukuran tabel, maks 10 = "); //
  scanf("%d%", &(MyTab.N));                    // Assign nilai MyTab.N dengan input pengguna

  MyTab.T = (int *)malloc(MyTab.N * sizeof(int)); // alokasi memori sebanyak MyTab.N dikali ukuran integer

  /* isi dengan assignment */
  for (i = 0; i < MyTab.N; i++)
  {
    // isi setiap nilai elemen array MyTab dengan nilai i
    *(MyTab.T + i) = i;

    printf("i = %d MyTab.T = %d \n", i, *(MyTab.T + i)); // cetak nilai i dan elemen array Mytab
  }

  return 0; // exit
}
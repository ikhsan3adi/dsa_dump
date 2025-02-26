/* ---------------------------------------------------------------------------------------------- */
/* File Program : PTR14.CPP */
/* Deskripsi : Array dinamis, dimana ukuran array ditentukan dari read keyboard */
/* ---------------------------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>

int main()
{
  /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
  int *tab; /* deklarasi array, perhatikan belum tampak bedanya dg deklarasi pointer biasa */

  int N, i;

  /* program */
  printf("Contoh mengisi array dinamis berukuran 0..N : \n");
  printf("N = ");

  scanf("%d", &N); // menerima input dari pengguna

  printf("Alokasi setelah mengetahui ukuran array \n");

  tab = (int *)malloc((N + 1) * sizeof(int)); // Alokasi sebesar N + 1 (karena index dimulai dari 0)
                                              // dikali ukuran integer (4 bytes)

  if (tab != NULL)
  {
    for (i = 0; i <= N; i++)
    {
      // cetak setiap nilai elemen tab
      printf("i=%d tab[i]=%d \n", i, *(tab + i));
    };

    printf("Akhir program \n");

    /* dealloc */
    free(tab); /* me-release/melepaskan memori  */
    return 0;
  }
  else // jika tab bernilai NULL, berarti gagal alokasi
  {
    printf("Alokasi gagal ... \n");
    return 1; // program selesai dengan error/kesalahan
  }
  return 0;
}

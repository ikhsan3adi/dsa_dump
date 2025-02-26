/* ----------------------------------------------------- */
/* File Program : ptr6.c */
/* Deskripsi : pointer yang menunjuk ke array */
/* ---------------------------------------------------- */
#include <stdio.h>

int main()
{
  /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
  static int tgl_lahir[] = {18, 6, 1989};
  int *ptgl;
  ptgl = tgl_lahir;

  // printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
  // printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]);

  for (int i = 0; i < 3; i++)
  {
    // cetak nilai elemen tgl_lahir
    printf("Nilai dari tgl_lahir[%d] = %d\n", i, tgl_lahir[i]);
  }

  for (int i = 0; i < 3; i++)
  {
    // cetak nilai yang ditunjuk oleh ptgl
    printf("Nilai dari ptgl dgn alamat %p = %d\n", ptgl, *(ptgl));

    ptgl++; // increment nilai ptgl supaya ia menunjuk
            // elemen selanjutnya dari tgl_lahir[]
  }

  return 0;
}

/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */
/* Modifikasi program tersebut agar bisa menampilkan seluruh elemen array tgl_lahir !*/
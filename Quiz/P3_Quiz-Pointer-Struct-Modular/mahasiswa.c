#include <stdio.h>
#include <stdlib.h>

// deklarasi tipe data Mahasiswa
typedef struct
{
  char **Nama;
  int *Nilai;
  int N;
} Mahasiswa;

// Prototype
void input_mhs(Mahasiswa *);
void print_mhs(Mahasiswa);

int main()
{
  Mahasiswa mhs;

  printf("Masukkan jumlah mahasiswa (maksimal 31) : ");
  scanf("%d", &mhs.N);

  if (mhs.N < 1 || mhs.N > 31)
  {
    printf("Jumlah mahasiswa tidak valid");
    return 1;
  }

  mhs.Nama = (char **)malloc(mhs.N * sizeof(char *));
  mhs.Nilai = (int *)malloc(mhs.N * sizeof(int));

  input_mhs(&mhs); // input data mahasiswa ke mhs, passing variabel by address

  print_mhs(mhs); // cetak semua mahasiswa ke layar

  return 0;
}

/* Body prototype */

void input_mhs(Mahasiswa *mhs)
{
  // Kamus data
  int i;

  // Program untuk traversal input
  for (i = 0; i < (*mhs).N; i++)
  {
    *(mhs->Nama + i) = (char *)malloc(16 * sizeof(char)); // alokasi sebanyak 16 karakter

    printf("\nInput mahasiswa ke-%d", i + 1);
    printf("\nNama mahasiswa, maksimum 16 karakter : ");

    // isi subvar Nama dengan input pengguna
    scanf("%16s", *((*mhs).Nama + i)); // Mengisi nilai string ke Nama

    printf("Nilai mahasiswa : ");
    scanf("%d", (*mhs).Nilai + i); // Mengisi nilai integer ke nilai
  }
}

void print_mhs(Mahasiswa mhs)
{
  // Kamus lokal
  int i;

  // Program untuk traversal print
  for (i = 0; i < mhs.N; i++)
  {
    printf("\nMahasiswa ke-%d\n", i + 1);
    printf("Nama : %s\n", mhs.Nama[i]);
    printf("Nilai : %d\n", mhs.Nilai[i]);
  }
}
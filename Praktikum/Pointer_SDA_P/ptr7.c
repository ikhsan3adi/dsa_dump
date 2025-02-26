#include <stdio.h>

int main()
{
  // Pointer
  char *pkota = "BANDOENG";     // Menyimpan alamat string literal "BANDOENG" ke pointer pkota
  printf("pkota: %s\n", pkota); // Menampilkan nilai string yang ditunjuk oleh pointer pkota

  //! pkota[0] = 'C';                          //! Tidak valid karena disimpan di memori statis (read-only).
  pkota = "JAKARTA";                           // pkota menunjuk ke string lain
  printf("pkota setelah diubah: %s\n", pkota); // Menampilkan nilai string yang ditunjuk oleh pointer pkota

  // Array
  char kota[] = "BANDUNG";    // Menyimpan salinan string "BANDUNG" ke dalam array karakter kota
  printf("kota: %s\n", kota); // Menampilkan nilai string yang disalin ke array kota

  // Mengubah nilai pada array
  kota[0] = 'X';                             // Mengubah karakter pertama dari array kota (B menjadi X)
  printf("kota setelah diubah: %s\n", kota); // Menampilkan string kota setelah karakter pertama diubah menjadi 'X'

  return 0; // Mengembalikan nilai 0, menandakan program selesai
}
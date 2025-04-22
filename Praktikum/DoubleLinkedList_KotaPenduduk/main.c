#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kota_penduduk/kota_penduduk.h"

// Function to consume the rest of the input line, useful after scanf %d
void consume_newline();

// Function to read a string including spaces using fgets and remove newline
void read_string(infotype buffer, int size);

int main(int argc, char const *argv[])
{
  address_kota head = NULL; // Inisialisasi daftar kota

  int choice;

  infotype nama_kota;
  infotype nama_penduduk;
  infotype target_kota;
  infotype target_penduduk;

  while (1)
  {
    system("clear");

    printf("\n===== Sistem Informasi Kota dan Penduduk =====\n");
    printf("1. Entry Kota\n");
    printf("2. Entry Penduduk By Kota\n");
    printf("3. Tampil Daftar Kota\n");
    printf("4. Tampil Daftar Penduduk Berdasarkan Kota\n");
    printf("5. Delete Kota\n");
    printf("6. Delete Penduduk berdasarkan Kota\n");
    printf("7. Keluar\n"); // Added an exit option for practicality
    printf("==============================================\n");
    printf("Masukkan pilihan Anda: ");

    if (scanf("%d", &choice) != 1)
    {
      printf("Input tidak valid. Masukkan angka.\n");
      consume_newline();
      continue;
    }
    consume_newline();

    switch (choice)
    {
    case 1:
      printf("\n--- Entry Kota ---\n");
      printf("Masukkan nama kota: ");
      read_string(nama_kota, sizeof(nama_kota));
      insert_kota(&head, nama_kota);
      printf("Kota berhasil ditambahkan.\n");
      break;

    case 2:
      printf("\n--- Entry Penduduk By Kota ---\n");
      printf("Masukkan nama kota tempat penduduk tinggal: ");
      read_string(target_kota, sizeof(target_kota));
      printf("Masukkan nama penduduk: ");
      read_string(nama_penduduk, sizeof(nama_penduduk));
      insert_penduduk(&head, target_kota, nama_penduduk);
      printf("Penduduk berhasil ditambahkan.\n");
      break;

    case 3:
      printf("\n--- Tampil Daftar Kota ---\n");
      tampil_kota(head);
      printf("\nDaftar kota ditampilkan.\n");
      break;

    case 4:
      printf("\n--- Tampil Daftar Penduduk Berdasarkan Kota ---\n");
      printf("Masukkan nama kota: ");
      read_string(target_kota, sizeof(target_kota));
      tampil_penduduk(head, target_kota);
      printf("\nDaftar penduduk ditampilkan.\n");
      break;

    case 5:
      printf("\n--- Delete Kota ---\n");
      printf("Masukkan nama kota yang akan dihapus: ");
      read_string(target_kota, sizeof(target_kota));
      delete_kota(&head, target_kota);
      printf("Kota berhasil dihapus.\n");
      break;

    case 6:
      printf("\n--- Delete Penduduk berdasarkan Kota ---\n");
      printf("Masukkan nama kota tempat penduduk tinggal: ");
      read_string(target_kota, sizeof(target_kota));
      printf("Masukkan nama penduduk yang akan dihapus: ");
      read_string(target_penduduk, sizeof(target_penduduk));
      delete_penduduk(&head, target_kota, target_penduduk);
      printf("Penduduk berhasil dihapus.\n");
      break;

    case 7:
      printf("Keluar dari program.\n");
      return 0;

    default:
      printf("Pilihan tidak valid. Silakan masukkan angka 1-7.\n");
    }

    printf("\nTekan ENTER untuk melanjutkan...");
    // consume_newline();
    getchar();
  }

  return 0;
}

void consume_newline()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void read_string(infotype buffer, int size)
{
  fgets(buffer, size, stdin);
  // Remove the newline character if it exists
  buffer[strcspn(buffer, "\n")] = 0;
}
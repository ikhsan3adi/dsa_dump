#include <stdio.h>
#include <stdlib.h>

#include "kota_penduduk/kota_penduduk.h"

int main(int argc, char const *argv[])
{
  address_kota head = NULL;

  insert_kota(&head, "Bandung");
  insert_kota(&head, "Jakarta");

  printf("Daftar Kota\n");
  tampil_kota(head);

  printf("\nDaftar Penduduk Kota Bandung\n");
  tampil_penduduk(head, "Bandung");

  printf("\nDaftar Penduduk Kota Jakarta\n");
  tampil_penduduk(head, "Jakarta");

  printf("\nDaftar Penduduk Kota Bandung Setelah Insert\n");
  insert_penduduk(&head, "Bandung", "Ikhsan");
  insert_penduduk(&head, "Bandung", "Syahid");
  tampil_penduduk(head, "Bandung");

  printf("\nDaftar Penduduk Kota Jakarta Setelah Insert\n");
  insert_penduduk(&head, "Jakarta", "Yazid");
  insert_penduduk(&head, "Jakarta", "Rizky");
  insert_penduduk(&head, "Jakarta", "Fulan");
  tampil_penduduk(head, "Jakarta");

  printf("\nDaftar Penduduk Kota Jakarta Setelah Hapus\n");
  delete_penduduk(&head, "Jakarta", "Fulan");
  delete_penduduk(&head, "Jakarta", "Rizky");
  tampil_penduduk(head, "Jakarta");

  printf("\nDaftar Penduduk Kota Cimahi\n");
  tampil_penduduk(head, "Cimahi");

  printf("\nDaftar Kota Setelah Hapus Jakarta\n");
  delete_kota(&head, "Jakarta");
  tampil_kota(head);

  return 0;
}
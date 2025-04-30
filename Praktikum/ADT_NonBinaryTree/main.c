#include <stdio.h>
#include <stdlib.h>

#include "nbtree/nbtree.h"

int main()
{
  Isi_Tree T;
  int pilihan, jmlNode;
  infotype cariInfo, info1, info2;
  bool found;
  int result;

  // Inisialisasi tree
  for (int i = 0; i <= jml_maks; i++)
  {
    T[i].info = '\0';
    T[i].ps_fs = nil;
    T[i].ps_nb = nil;
    T[i].ps_pr = nil;
  }

  // Pembuatan Tree Awal
  printf("=== Pembuatan N-ary Tree ===\n");
  printf("Masukkan jumlah node yang ingin dibuat (maks %d): ", jml_maks);
  scanf("%d", &jmlNode);

  if (jmlNode <= 0 || jmlNode > jml_maks)
  {
    printf("Jumlah node tidak valid.\n");
    return 1;
  }

  Create_tree(T, jmlNode);
  printf("\nTree berhasil dibuat!\n");
  printf("Tekan Enter untuk melanjutkan...");
  getchar();
  getchar();

  // Menu Utama
  do
  {
    system("clear");

    printf("\n=== MENU N-ARY TREE ===\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree (Info Max)\n");
    printf("11. Exit\n");
    printf("Pilih Menu: ");
    scanf("%d", &pilihan);
    getchar();

    if (IsEmpty(T) && pilihan != 11)
    {
      printf("\nTree kosong, tidak ada operasi yang bisa dilakukan selain Exit.\n");
      printf("Tekan Enter untuk melanjutkan...");
      getchar();
      continue;
    }

    switch (pilihan)
    {
    case 1:
      printf("\n--- Traversal PreOrder ---\n");
      PreOrder(T);
      break;
    case 2:
      printf("\n--- Traversal InOrder ---\n");
      InOrder(T);
      break;
    case 3:
      printf("\n--- Traversal PostOrder ---\n");
      PostOrder(T);
      break;
    case 4:
      printf("\n--- Traversal Level Order ---\n");
      Level_order(T, jml_maks);
      break;
    case 5:
      printf("\n--- Print Tree ---\n");
      PrintTree(T);
      break;
    case 6:
      printf("\n--- Search Node Tree ---\n");
      printf("Masukkan info node yang dicari: ");
      scanf(" %c", &cariInfo);
      found = Search(T, cariInfo);
      if (found)
      {
        printf("Node '%c' ditemukan dalam tree.\n", cariInfo);
      }
      else
      {
        printf("Node '%c' tidak ditemukan dalam tree.\n", cariInfo);
      }
      break;
    case 7:
      printf("\n--- Jumlah Daun/Leaf ---\n");
      result = nbDaun(T);
      printf("Jumlah daun dalam tree: %d\n", result);
      break;
    case 8:
      printf("\n--- Mencari Level Node Tree ---\n");
      printf("Masukkan info node yang ingin dicari levelnya: ");
      scanf(" %c", &cariInfo);
      result = Level(T, cariInfo);
      if (result != -1)
      {
        printf("Node '%c' berada pada level: %d (root level 0)\n", cariInfo, result);
      }
      else
      {
        printf("Node '%c' tidak ditemukan dalam tree.\n", cariInfo);
      }
      break;
    case 9:
      printf("\n--- Kedalaman Tree ---\n");
      result = Depth(T);
      if (result > 0)
      {
        printf("Kedalaman (maks level + 1) tree: %d\n", result);
        printf("Tinggi/Height (jarak terjauh dari root ke daun) tree: %d\n", result - 1);
      }
      else
      {
        printf("Tree kosong atau hanya terdiri dari root.\n");
      }
      break;
    case 10:
      printf("\n--- Membandingkan Info 2 Node (Mencari Max) ---\n");
      printf("Masukkan info node pertama: ");
      scanf(" %c", &info1);
      printf("Masukkan info node kedua: ");
      scanf(" %c", &info2); // Fungsi Max hanya membandingkan nilai ASCII karakternya
      printf("Nilai info maksimum antara '%c' dan '%c' adalah: '%c'\n", info1, info2, Max(info1, info2));
      break;
    case 11:
      printf("\nTerima kasih! Keluar dari program...\n");
      break;
    default:
      printf("\nPilihan tidak valid!\n");
      break;
    }

    if (pilihan != 11)
    {
      printf("\nTekan Enter untuk kembali ke menu...");
      getchar();
    }

  } while (pilihan != 11);

  return 0;
}
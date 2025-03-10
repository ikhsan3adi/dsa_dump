#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
  address head = NULL;

  // Menambahkan node di awal
  printf("Tambah satu node awal dengan nilai 10: \n");
  Add_Awal(&head, 10);
  Tampil_List(head);
  printf("\n\n");

  printf("Menambahkan node 20 dan 30 di awal... \n");
  Add_Awal(&head, 20);
  Add_Awal(&head, 30);
  printf("List setelah menambahkan node 20 dan 30 di awal: \n");
  Tampil_List(head);
  printf("\n\n");

  // Menambahkan node di akhir
  printf("Menambahkan node dengan nilai 7 di akhir... \n");
  Add_Akhir(&head, 7);
  printf("List setelah menambahkan node di akhir: \n");
  Tampil_List(head);
  printf("\n\n");

  // Menambahkan node di tengah
  printf("Menambahkan node dengan nilai 25 di posisi 2... \n");
  Add_Tengah(&head, 25, 2);
  printf("List setelah menambahkan node 25 di posisi 2: \n");
  Tampil_List(head);
  printf("\n\n");

  printf("Menambahkan node dengan nilai 35 di posisi 4... \n");
  Add_Tengah(&head, 35, 4);
  printf("List setelah menambahkan node 35 di posisi 4: \n");
  Tampil_List(head);
  printf("\n\n");

  // Mencari node dengan nilai tertentu
  printf("Mencari node dengan nilai 25... \n");
  address found_node = cari_Node(head, 25);
  if (found_node != NULL)
  {
    printf("Node ditemukan = %d\n", found_node->info);
  }
  else
  {
    printf("Node dengan nilai 25 tidak ditemukan.\n");
  }
  printf("\n");

  // Menghapus node di awal
  printf("Menghapus node di awal... \n");
  hapus_NodeAwal(&head);
  printf("List setelah menghapus node di awal: \n");
  Tampil_List(head);
  printf("\n\n");

  // Menghapus node di akhir
  printf("Menghapus node di akhir... \n");
  hapus_NodeAkhir(&head);
  printf("List setelah menghapus node di akhir: \n");
  Tampil_List(head);
  printf("\n\n");

  // Menghapus node di tengah
  printf("Menghapus node di posisi 2... \n");
  hapus_Node(&head, 2);
  printf("List setelah menghapus node di posisi 2: \n");
  Tampil_List(head);
  printf("\n\n\n");

  printf("Menghitung jumlah node... \n");
  int jumlah_node = jum_Node(head);
  printf("Jumlah node: %d", jumlah_node);
  printf("\n\n");

  printf("Menghitung total nilai node... \n");
  int total_nilai = sum_Node(head);
  printf("Total nilai node: %d", total_nilai);
  printf("\n\n");

  printf("Mencari nilai maksimum node... \n");
  int max_nilai = node_Max(head);
  printf("Nilai maksimum node: %d", max_nilai);
  printf("\n\n");

  printf("Menghitung rata-rata nilai node... \n");
  float rata_rata = rata2_Node(head);
  printf("Rata-rata nilai node: %.2f", rata_rata);

  return 0;
}
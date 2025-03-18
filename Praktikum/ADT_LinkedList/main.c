#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list/single_linked_list.h"
#include "stack/stack.h"
#include "queue/queue.h"

void driver_single_linked_list()
{
  address First = Nil;
  char cari_info;
  bool hasil;
  char lanjut;

  printf("Menguji fungsi insert_awal:\n");
  insert_awal(&First, 'J');
  tampil_list(First);

  printf("\nMenguji fungsi insert_akhir:\n");
  insert_akhir(&First, 'T');
  insert_akhir(&First, 'K');
  tampil_list(First);

  printf("\nMenguji fungsi delete_awal:\n");
  delete_awal(&First);
  tampil_list(First);

  printf("\nMenguji fungsi delete_akhir:\n");
  delete_akhir(&First);
  tampil_list(First);

  printf("\ninsert_awal 2 kali:\n");
  insert_awal(&First, 'B');
  insert_awal(&First, 'A');
  tampil_list(First);

  printf("\nMenguji fungsi update_awal:\n");
  update_awal(First, 'X');
  tampil_list(First);

  printf("\nMenguji fungsi update_akhir:\n");
  update_akhir(First, 'Z');
  tampil_list(First);

  printf("\nMenguji fungsi cari_node:\n");
  do
  {
    printf("Masukkan karakter yang ingin dicari: ");
    scanf(" %c", &cari_info);
    hasil = cari_node(First, cari_info);
    printf(hasil ? "Ditemukan\n" : "Tidak ditemukan\n");
    printf("Cari lagi? (Y/N): ");
    scanf(" %c", &lanjut);
  } while (lanjut == 'Y' || lanjut == 'y');
}

void driver_stack()
{
  address Stack = Nil;

  printf("\nMenguji Stack (LIFO):\n");
  printf("\nPush Stack A:\n");
  push(&Stack, 'A');
  tampil_list(Stack);
  printf("\nPush Stack B:\n");
  push(&Stack, 'B');
  tampil_list(Stack);
  printf("\nPush Stack C:\n");
  push(&Stack, 'C');
  tampil_list(Stack);

  printf("\nPop dari Stack:\n");
  pop(&Stack);
  tampil_list(Stack);

  printf("\nPop dari Stack lagi:\n");
  pop(&Stack);
  tampil_list(Stack);
}

void driver_queue()
{
  address Queue = Nil;

  printf("\nMenguji Queue (FIFO):\n");
  printf("\nEnqueue X ke Queue:\n");
  enqueue(&Queue, 'X');
  tampil_list(Queue);
  printf("\nEnqueue Y ke Queue:\n");
  enqueue(&Queue, 'Y');
  tampil_list(Queue);
  printf("\nEnqueue Z ke Queue:\n");
  enqueue(&Queue, 'Z');
  tampil_list(Queue);

  printf("\nDequeue dari Queue:\n");
  dequeue(&Queue);
  tampil_list(Queue);

  printf("\nDequeue dari Queue lagi:\n");
  dequeue(&Queue);
  tampil_list(Queue);
}

int main()
{
  int pilihan;

  printf("Pilih: 1 = Single Linked List | 2 = Stack | 3 = Queue : ");

  scanf("%d", &pilihan);

  switch (pilihan)
  {
  case 1:
    driver_single_linked_list();
    break;
  case 2:
    driver_stack();
    break;
  case 3:
    driver_queue();
    break;
  default:
    break;
  }

  return 0;
}

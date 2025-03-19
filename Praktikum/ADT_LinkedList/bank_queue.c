#include <stdio.h>
#include "queue/queue.h"

void ambil_antrian(address *queue, infotype *nilai);
void proses_antrian(address *queue);
void cetak_antrian(address queue);

int main(int argc, char const *argv[])
{
  /// kamus
  int pilihan;
  infotype nomor_antrian = 1;
  address queue = Nil;

  // program
  do
  {
    printf("\nPilihan menu\n");
    printf("1 = Ambil antrian | ");
    printf("2 = Proses antrian | ");
    printf("3 = Cetak antrian | ");
    printf("4 = Keluar | ");

    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
      ambil_antrian(&queue, &nomor_antrian);
      break;
    case 2:
      proses_antrian(&queue);
      break;
    case 3:
      cetak_antrian(queue);
      break;
    }
  } while (pilihan != 4);

  return 0;
}

void ambil_antrian(address *queue, infotype *nilai)
{
  enqueue(queue, *nilai);
  (*nilai)++; // increment antrian
  cetak_antrian(*queue);
}

void proses_antrian(address *queue)
{
  if (*queue == Nil)
  {
    printf("Antrian kosong!!!\n");
    return;
  }

  // proses dan ambil nomor antrian dengan `dequeue`
  infotype nomor_antrian = dequeue(queue);

  printf("\nProses antrian nomor: %d", nomor_antrian);

  cetak_antrian(*queue);
}

void cetak_antrian(address queue)
{
  printf("\nAntrian saat ini\n");
  tampil_queue(queue);

  if (queue == Nil)
    printf("Antrian kosong");

  printf("\n");
}
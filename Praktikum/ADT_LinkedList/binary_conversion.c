#include <stdio.h>
#include "stack/stack.h"

int main()
{
  int desimal;
  address First = Nil;

  printf("\nMasukkan bilangan desimal: ");
  scanf("%d", &desimal);

  if (desimal == 0)
  {
    push(&First, 0);
  }

  while (desimal > 0)
  {
    push(&First, desimal % 2); // Simpan sisa hasil bagi
    desimal = desimal / 2;     // Bagi bilangan dengan 2
  }

  printf("Hasil konversi ke biner: ");

  tampil_stack(&First);

  printf("\n");

  return 0;
}

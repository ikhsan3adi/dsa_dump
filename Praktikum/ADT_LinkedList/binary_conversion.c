#include <stdio.h>
#include "stack/stack.h"

void desimal_ke_biner(int desimal)
{
  address First = Nil;

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
}

int main()
{
  int desimal;

  printf("Masukkan bilangan desimal: ");
  scanf("%d", &desimal);

  desimal_ke_biner(desimal);

  return 0;
}

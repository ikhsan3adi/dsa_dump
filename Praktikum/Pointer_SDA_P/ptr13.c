/* ------------------------------------------------------------------------------------------------------------------ */
/* File : ptr13.c */
/* Deskripsi : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>

/* Kamus Global */
int N; /* ukuran efektif */
enum MyType
{
  bulat,
  karakter
};

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succI(int *i);  /* suksessor, berupa procedure by ref */
void predI(int *i);  /* predesessor */
void succC(char *c); /* suksessor, berupa procedure by ref */
void predC(char *c); /* predesessor */
/* print tabel yang belum ketahuan typenya */
void printtab(void *T, enum MyType Ty);
/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, void (*f)(void *));

/* Program Utama */
int main()
{
  /* kamus lokal */
  void *MyTabInt;
  void *MyTabC;
  int i;

  /* program */
  N = 10;
  MyTabInt = (int *)malloc(N * sizeof(int));
  MyTabC = (char *)malloc(N * sizeof(char));

  *MyTabInt = 1;
  for (i = 0; i < N; i++)
  {
    *(MyTabInt + i) = i;
    *(MyTabC + i) = 'Z';
  }

  printf("Isi tabel dalam main sebelum pemanggilan : \n");
  printf(" Tabel integer \n");
  printtab((int *)MyTabInt, 0);
  printf(" Tabel charakter \n");
  printtab((char *)MyTabC, 1);
  printf("\n");

  /* Pakai geser dengan parameter succ */
  printf("Geser dengan succ \n");
  geser((int *)MyTabInt, (int *)succI);
  geser((char *)MyTabC, (char *)succC);
  printf(" dalam main \n");
  printf(" Tabel integer \n");
  printtab((int *)MyTabInt, 0);
  printf(" Tabel charakter \n");
  printtab((char *)MyTabC, 1);
  printf("\n");

  /* Pakai geser dengan parameter pred */
  printf("Geser dengan pred \n");
  geser((int *)MyTabInt, (int *)predI);
  geser((char *)MyTabC, (char *)predC);
  printf(" dalam main \n");
  printf(" Tabel integer \n");
  printtab((int *)MyTabInt, 0);
  printf(" Tabel charakter \n");
  printtab((char *)MyTabC, 1);
  printf("\n");

  return 0;
}

/* Body Function */
void succI(int *i)
{
  *i = *i + 1;
}

void predI(int *i)
{
  *i = *i - 1;
}

void succC(char *c)
{
  *c = *c + 1;
}

void predC(char *c)
{
  *c = *c - 1;
}

void geser(int *TT, void (*f)(void *))
{
  int i;
  printf(" dalam geser \n");
  for (i = 0; i < N; i++)
  {
    f(&TT[i]);
    printf(" %d ", TT[i]);
  }
  printf("\n");
}

void printtab(void *T, enum MyType Ty)
{
  int i;
  for (i = 0; i < N; i++)
  {
    switch (Ty)
    {
    case bulat:
      printf("%d ", (int *)*(T + i));
      break;
    case karakter:
      printf("%c ", (char *)*(T + i));
      break;
    }
  }
}
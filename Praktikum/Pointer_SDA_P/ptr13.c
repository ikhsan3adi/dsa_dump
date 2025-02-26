/* ------------------------------------------------------------------------------------------------------------------ */
/* File        : PTR13.cpp          */
/* Deskripsi   : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
/*       Melakukan offset terhadap tabel tergantung fungsi f     */
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
void succI(void i);
/**/ suksessor, berupa procedure by ref * /
                    void predI(void i);
/ predesessor * /
    void succC(void c);
/ suksessor, berupa procedure by ref * /
                 void predC(void c);
/ predesessor * /

    /* print tabel yang belum ketahuan typenya */
    void printtab(void *T, enum MyType Ty);

/* Prosedur dengan parameter sebuah fungsi */
void geser(void *TT, enum MyType Tty, void (*f)(void *));

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
  *(int *)MyTabInt = 1;
  int *tabInt = (int *)MyTabInt;
  char *tabC = (char *)MyTabC;
  for (i = 0; i < N; i++)
  {
    tabInt[i] = i;
    tabC[i] = 'Z';
  }
  printf("Isi tabel dalam main sebelum pemanggilan : \n");

  printf("    Tabel integer \n");
  printtab(MyTabInt, 0);
  printf("    Tabel charakter \n");
  printtab(MyTabC, 1);

  printf("\n");

  /* Pakai geser dengan parameter succ */
  printf("Geser dengan succ \n");
  geser(MyTabInt, 0, succI);
  geser(MyTabC, 1, succC);
  printf(" dalam main \n");
  printf("    Tabel integer \n");
  printtab(MyTabInt, 0);
  printf("    Tabel charakter \n");
  printtab(MyTabC, 1);
  printf("\n");

  /* Pakai geser dengan parameter pred */
  printf("Geser dengan pred \n");
  geser(MyTabInt, 0, predI);
  geser(MyTabC, 1, predC);
  printf(" dalam main \n");
  printf("    Tabel integer \n");
  printtab(MyTabInt, 0);
  printf("    Tabel charakter \n");
  printtab(MyTabC, 1);
  printf("\n");

  free(MyTabInt);
  free(MyTabC);
  return 0;
}

/* Body Function */
void succI(void *i)
{
  int *ip = (int *)i;
  *ip = *ip + 1;
}

void predI(void *i)
{
  int *ip = (int *)i;
  *ip = *ip - 1;
}

void succC(void *c)
{
  char *cp = (char *)c;
  *cp = *cp + 1;
}

void predC(void *c)
{
  char *cp = (char *)c;
  *cp = *cp - 1;
}

void geser(void *TT, enum MyType Tty, void (*f)(void *))
{
  int i;

  printf(" dalam geser \n");
  for (i = 0; i < N; i++)
  {
    if (Tty == bulat)
    {
      int *elem = (int *)TT + i;
      f(elem);
      printf(" %d ", *elem);
    }
    else if (Tty == karakter)
    {
      char *elem = (char *)TT + i;
      f(elem);
      printf(" %c ", *elem);
    }
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
      printf("%d ", ((int *)T)[i]);
      break;
    case karakter:
      printf("%c ", ((char *)T)[i]);
      break;
    }
  }
  printf("\n");
}

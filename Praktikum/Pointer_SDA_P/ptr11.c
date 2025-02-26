/* ----------------------------------------------------------------------------- */
/* File : ptr11.c */
/* Deskripsi : Pointer ke function (Function sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ----------------------------------------------------------------------------- */

/* Kamus Global */
int N; /* ukuran efektif */

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
int succ(int i); /* succ -> singkatan dari suksessor */
int pred(int i); /* pred -> singkatan dari predesessor */

/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, int (*f)(int));

/* Program Utama */
int main()
{
  /* kamus lokal */
  int MyTab[10];
  int i;

  /* program */
  N = 10;
  for (i = 0; i < N; i++)
  {
    MyTab[i] = i;
  }

  printf("Isi tabel dalam main sebelum pemanggilan : \n");

  for (i = 0; i < N; i++)
  {
    printf(" %d ", MyTab[i]);
  }
  printf("\n");

  /* Pakai geser dengan parameter succ */
  printf("Geser dengan succ \n");
  geser(MyTab, succ);
  printf(" dalam main \n");

  for (i = 0; i < N; i++)
  {
    printf(" %d ", MyTab[i]);
  }
  printf("\n");

  /* Pakai geser dengan parameter pred */
  printf("Geser dengan pred \n");
  geser(MyTab, pred);
  printf(" dalam main setelah aplikasi pred \n");

  for (i = 0; i < N; i++)
  {
    printf(" %d ", MyTab[i]);
  }
  printf("\n");

  return 0;
}

/* Body Function */
int succ(int i)
{
  return (i + 1);
}

int pred(int i)
{
  return (i - 1);
}

void geser(int *TT, int (*f)(int))
{
  int i;
  printf(" dalam geser \n");
  for (i = 0; i < N; i++)
  {
    TT[i] = f(TT[i]);
    printf(" %d ", TT[i]);
  }
  printf("\n");
}
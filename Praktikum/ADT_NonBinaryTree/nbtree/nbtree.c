#include "nbtree.h"
#include <stdio.h>
#include <stdlib.h>

void Create_tree(Isi_Tree X, int Jml_Node)
{
  for (int i = 1; i <= Jml_Node; i++)
  {
    printf("Enter info for node %d: ", i);
    scanf(" %c", &X[i].info);

    printf("Enter first son (fs) address for node %d (0 if none): ", i);
    scanf("%d", &X[i].ps_fs);

    printf("Enter next brother (nb) address for node %d (0 if none): ", i);
    scanf("%d", &X[i].ps_nb);

    printf("Enter parent (pr) address for node %d: ", i);
    scanf("%d", &X[i].ps_pr);
  }
}

bool IsEmpty(Isi_Tree P)
{
  return (P[1].info == '\0');
}

/***** Traversal *****/

void PreOrder_recursive(Isi_Tree P, address root)
{
  if (root == nil)
    return;

  printf("%c ", P[root].info); // Kunjungi parent dahulu

  // Traverse first son
  PreOrder_recursive(P, P[root].ps_fs);

  // Traverse next brothers
  PreOrder_recursive(P, P[root].ps_nb);
}

void PreOrder(Isi_Tree P)
{
  PreOrder_recursive(P, 1); // asumsi root ada di index 1
  printf("\n");
}

void InOrder_recursive(Isi_Tree P, address root)
{
  if (root == nil)
    return;

  // Traverse first son first
  InOrder_recursive(P, P[root].ps_fs);

  // Kunjungi parent
  printf("%c ", P[root].info);

  // Traverse next brothers
  address current = P[root].ps_nb;
  while (current != nil)
  {
    InOrder_recursive(P, current);
    current = P[current].ps_nb;
  }
}

void InOrder(Isi_Tree P)
{
  InOrder_recursive(P, 1);
  printf("\n");
}

void PostOrder_recursive(Isi_Tree P, address root)
{
  if (root == nil)
    return;

  // Traverse first son
  PostOrder_recursive(P, P[root].ps_fs);

  // Traverse next brothers
  PostOrder_recursive(P, P[root].ps_nb);

  printf("%c ", P[root].info);
}

void PostOrder(Isi_Tree P)
{
  PostOrder_recursive(P, 1);
  printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node)
{
  if (IsEmpty(X))
  {
    return;
  }

  // Buat queue untuk level order traversal
  address queue[jml_maks];
  int front = 0, rear = 0;

  queue[rear++] = 1;

  while (front < rear)
  {
    address current = queue[front++];
    printf("%c ", X[current].info);

    // Enqueue semua children (first son & all brothers)
    address child = X[current].ps_fs;
    while (child != nil)
    {
      queue[rear++] = child;
      child = X[child].ps_nb;
    }
  }
  printf("\n");
}

void PrintTree(Isi_Tree P)
{
  printf("Tree Contents:\n");
  printf("Index\tInfo\tFS\tNB\tPR\n");
  for (int i = 1; i <= jml_maks; i++)
  {
    if (P[i].info != '\0') // hanya cetak node yang tidak kosong
    {
      printf("%d\t%c\t%d\t%d\t%d\n",
             i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
    }
  }
}

/***** Search *****/

// pre-order
bool Search_recursive(Isi_Tree P, address root, infotype X)
{
  if (root == nil)
  {
    return false;
  }

  if (P[root].info == X)
  {
    return true;
  }

  // Search in first son subtree
  if (Search_recursive(P, P[root].ps_fs, X))
  {
    return true;
  }

  // Search in next brothers
  return Search_recursive(P, P[root].ps_nb, X);
}

bool Search(Isi_Tree P, infotype X)
{
  return Search_recursive(P, 1, X);
}

/***** Fungsi Lain *****/

int nbElmt_recursive(Isi_Tree P, address root)
{
  if (root == nil)
  {
    return 0;
  }

  int jumlah = 0;

  // Hitung jumlah node di first son subtree
  jumlah += nbElmt_recursive(P, P[root].ps_fs);

  // Hitung jumlah node di next brothers
  jumlah += nbElmt_recursive(P, P[root].ps_nb);

  return jumlah;
}

int nbElmt(Isi_Tree P)
{
  return nbElmt_recursive(P, 1);
}

int nbDaun_recursive(Isi_Tree P, address root)
{
  if (root == nil)
  {
    return 0;
  }

  if (P[root].ps_fs == nil)
  {
    return 1;
  }

  int jumlah = 0;

  // cek first son
  jumlah += nbDaun_recursive(P, P[root].ps_fs);

  // cek next brothers
  address current = P[root].ps_nb;
  while (current != nil)
  {
    jumlah += nbDaun_recursive(P, current);
    current = P[current].ps_nb;
  }

  return jumlah;
}

int nbDaun(Isi_Tree P)
{
  return nbDaun_recursive(P, 1); // Start from root
}

int Level_recursive(Isi_Tree P, address root, infotype X, int current_level)
{
  if (root == nil)
  {
    return -1;
  }

  if (P[root].info == X)
  {
    return current_level;
  }

  // Search in first son subtree (level increases)
  int level = Level_recursive(P, P[root].ps_fs, X, current_level + 1);
  if (level != -1)
  {
    return level;
  }

  // Search in next brothers (same level)
  return Level_recursive(P, P[root].ps_nb, X, current_level);
}

int Level(Isi_Tree P, infotype X)
{
  return Level_recursive(P, 1, X, 0); // Start from root at level 0
}

int Depth_recursive(Isi_Tree P, address root)
{
  if (root == nil)
  {
    return 0;
  }

  int max_depth = 0;
  address child = P[root].ps_fs;

  while (child != nil)
  {
    int current_depth = Depth_recursive(P, child);
    if (current_depth > max_depth)
    {
      max_depth = current_depth;
    }
    child = P[child].ps_nb;
  }

  return max_depth + 1;
}

int Depth(Isi_Tree P)
{
  return Depth_recursive(P, 1);
}

int Max(infotype Data1, infotype Data2)
{
  if (Data1 > Data2)
  {
    return Data1;
  }
  else
  {
    return Data2;
  }
}
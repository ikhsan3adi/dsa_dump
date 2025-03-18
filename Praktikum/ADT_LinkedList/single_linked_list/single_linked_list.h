#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next

typedef char infotype;

typedef struct tElmtList *address;

typedef struct tElmtList
{
  infotype info;
  address next;
} ElmtList;

// create
void insert_awal(address *p, infotype nilai);
void insert_akhir(address *p, infotype nilai);
void insert_tengah(address *p, infotype nilai, int posisi);

// read
void tampil_list(address p);
bool cari_node(address p, infotype nilai);

// update
void update_awal(address p, infotype nilai);
void update_akhir(address p, infotype nilai);
void update_tengah(address p, infotype nilai, int posisi);

// delete
void delete_awal(address *p);
void delete_akhir(address *p);
void delete_tengah(address *p, int posisi);

#endif
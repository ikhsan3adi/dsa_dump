#ifndef QUEUE_H
#define QUEUE_H

#include "../single_linked_list/single_linked_list.h"

// masukkan ke antrian
void enqueue(address *p, infotype nilai);

// keluarkan dari antrian
infotype dequeue(address *p);

void tampil_queue(address q);

#endif
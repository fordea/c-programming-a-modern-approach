#ifndef INVENTORY_H
#define INVENTORY_H

#define NAME_LEN 25
#define MAX_PARTS 100

extern struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[];

#endif

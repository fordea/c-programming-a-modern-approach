/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* inventory.c (Chapter 16, page 391) */
/* Maintains a parts database (array version) */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
} *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void erase(void);
void print(void);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert();
                break;
      case 's': search();
                break;
      case 'u': update();
                break;
      case 'e': erase();
                break;
      case 'p': print();
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            linked list. Returns the struct part        *
 *            matching the number if it exists. If not    *
 *            found, returns NULL.                        *
 **********************************************************/
struct part *find_part(int number)
{
  int i;
  struct part *entry;

  for (entry = inventory; entry; entry = entry->next)
      if (entry->number == number)
          return entry;
  return NULL;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         database. Prints an error message and returns  *
 *         prematurely if the part already exists or the  *
 *         database is full.                              *
 **********************************************************/
void insert(void)
{
  int part_number;

  printf("Enter part number: ");
  scanf("%d", &part_number);
  if (find_part(part_number)) {
    printf("Part already exists.\n");
    return;
  }

  struct part *new_part;
  if ((new_part = malloc(sizeof(struct part))) == NULL) {
      printf("Error, malloc failed");
  }
  new_part->number = part_number;
  printf("Enter part name: ");
  read_line(new_part->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &(new_part->on_hand));

  /* Inserts the new part in the inventory, ordered by part number */
  struct part **pp = &inventory;
  /* struct part *entry = *pp; */
  while (*pp) {
      if ((*pp)->number > part_number) {
          break;
      }
      pp = &(*pp)->next;
      /* entry = entry->next; */
  }
  new_part->next = *pp;
  *pp = new_part;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  struct part *entry = find_part(number);
  if (entry) {
    printf("Part name: %s\n", entry->name);
    printf("Quantity on hand: %d\n", entry->on_hand);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  struct part *entry = find_part(number);
  if (entry) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    entry->on_hand += change;
  } else
    printf("Part not found.\n");
}

/* Erases a part from the inventory */
void erase(void)
{
    int part_number;
    printf("Enter part number: ");
    scanf("%d", &part_number);

    struct part **pp = &inventory;
    struct part *temp;
    while (*pp) {
        if ((*pp)->number == part_number) {
            temp = *pp;
            *pp = (*pp)->next;
            free(temp);
            continue;
        }
        pp = &(*pp)->next;
    }
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Parts are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
void print(void)
{
  int i;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  struct part *entry;
  for (entry = inventory; entry; entry = entry->next)
    printf("%7d       %-25s%11d\n", entry->number,
           entry->name, entry->on_hand);
}

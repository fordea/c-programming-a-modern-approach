/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* qsort.c (Chapter 9, page 207) */
/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>
#include "quicksort.h"

#define N 10

int split(struct part a[], int low, int high);

void quicksort(struct part a[], int low, int high)
{
  int middle;

  if (low >= high) return;
  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(struct part a[], int low, int high)
{
  struct part part_element = a[low];

  for (;;) {
    while (low < high && part_element.number <= a[high].number)
      high--;
    if (low >= high) break;
    a[low++] = a[high];

    while (low < high && a[low].number <= part_element.number)
      low++;
    if (low >= high) break;
    a[high--] = a[low];
  }
  a[high] = part_element;
  return high;
}

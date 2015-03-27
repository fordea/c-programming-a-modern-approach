/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* remind2.c (Chapter 17, page 418) */
/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

struct vstring {
    int len;
    char chars[];
};

int read_line(char str[], int n);

int main(void)
{
  struct vstring *reminders[MAX_REMIND];
  char day_str[3], msg_str[MSG_LEN+1];
  int day, i, j, num_remind = 0;

  for (;;) {
    printf("num remind: %d\n", num_remind);
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]->chars) < 0)
        break;
    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j-1];

    struct vstring *new_vstring  = malloc(sizeof(struct vstring) + 3 + strlen(msg_str));
    new_vstring->len = 3 + strlen(msg_str);
    reminders[i] = new_vstring;
    if (reminders[i] == NULL) {
      printf("-- No space left --\n");
      break;
    }

    new_vstring->chars[0] = day_str[0];
    new_vstring->chars[1] = day_str[1];
    new_vstring->chars[2] = ' ';

    for (i = 0; i < new_vstring->len; i++)
        new_vstring->chars[i + 3] = msg_str[i];

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++) {
      for (j = 0; j < reminders[i]->len; j++)
        printf("%c", reminders[i]->chars[j]);
      printf("\n");
  }

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

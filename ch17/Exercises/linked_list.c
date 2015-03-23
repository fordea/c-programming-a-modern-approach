#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
}; 

struct node *add_to_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);

struct node *head = NULL;
int size = 0;

int main(void)
{
    printf("size of list: %d\n", size);
    head = add_to_list(head, 25);
    printf("size of list: %d\n", size);
    head = add_to_list(head, 13);
    printf("size of list: %d\n", size);

    printf("%s\n", search_list(head, 12) ? "Found Node." : "Node not found.");
    printf("%s\n", search_list(head, 25) ? "Found Node." : "Node not found.");

    head = delete_from_list(head, 25);
    printf("size of list: %d\n", size);

    return 0;
}

struct node *add_to_list(struct node *head, int n)
{
    struct node *new_node;

    if ((new_node = malloc(sizeof(struct node))) == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = head;
    size++;
    return new_node;
}

struct node *delete_from_list(struct node *head, int n)
{
    struct node *cur, *prev;

    for (cur = head, prev = NULL;
         cur != NULL && cur->value != n; 
         prev = cur, cur = cur->next)
        ;

    if (cur == NULL) {
        return head;                /* n is not in list */
    }
    else if (prev == NULL) {
        head = head->next;          /* n is first item in list */
        size--;
    }
    else {
        prev->next = cur->next;     /* n is some other item in list */
        size--;
    }

    free(cur);    
    return head;
}

struct node *search_list(struct node *head, int n)
{
    struct node *node = head;

    while (node != NULL && node->value != n)
        node = node->next;
    return node;
}

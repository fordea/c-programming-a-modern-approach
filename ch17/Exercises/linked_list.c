#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
}; 

void *add_to_list(struct node **pp, int n);
void *delete_from_list(struct node **pp, int n);
struct node *search_list(struct node *p, int n);
int list_size(struct node *p);
void clear_list(struct node **pp);


int main(void)
{
    struct node *head = NULL;

    add_to_list(&head, 25);
    add_to_list(&head, 13);
    add_to_list(&head, 38);
    add_to_list(&head, 23);
    add_to_list(&head, 30);
    printf("Number of nodes in list: %d\n", list_size(head));

    printf("%s\n", search_list(head, 12) ? "Found Node." : "Node not found.");
    printf("%s\n", search_list(head, 25) ? "Found Node." : "Node not found.");

    delete_from_list(&head, 38);
    printf("Number of nodes in list: %d\n", list_size(head));

    clear_list(&head);
    printf("Number of nodes in list: %d\n", list_size(head));

    return 0;
}

/* Adds a node to the linked list, Argument pp is a pointer to a pointer
 * to the first node in the list, n is the value of the node to add */
void *add_to_list(struct node **pp, int n)
{
    struct node *new_node;

    if ((new_node = malloc(sizeof(struct node))) == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = *pp;
    *pp = new_node;
}

/* Delete a node from the linked list. Argument pp is a pointer to a pointer
 * to the first node in the list, n is the value of the node(s) to delete */
void *delete_from_list(struct node **pp, int n)
{
    struct node *entry = *pp;

    while (entry) {
        if (entry->value == n) {
            *pp = entry->next;
            free(entry);
        }
        pp = &entry->next;
        entry = entry->next;
    }
}

/* Search for a node in the linked list. Argument p is a pointer to the 
 * first node in the list, int n is the value of the node to find 
 * Returns the first node with the matching value that it finds */
struct node *search_list(struct node *p, int n)
{
    struct node *node = p;

    while (node != NULL && node->value != n)
        node = node->next;
    return node;
}

/* Returns the number of nodes in the linked list. Argument p is
 * a pointer to the first node in the list */
int list_size(struct node *p)
{
    int count = 0;
    while (p != NULL) {
        count ++;
        if (p->next == NULL)
            return count;
        p = p->next;
    }
    return count;
}
void clear_list(struct node **pp)
{
    struct node *next_node;

    while (*pp != NULL) {
        next_node = (*pp)->next;
        free(*pp);
        *pp = next_node;
    }
}

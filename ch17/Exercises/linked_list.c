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
void *insert_into_ordered_list(struct node **pp, int value);
void print_node_values(struct node *p);


int main(void)
{
    struct node *head = NULL;

    add_to_list(&head, 1);
    add_to_list(&head, 2);
    add_to_list(&head, 3);
    add_to_list(&head, 4);
    add_to_list(&head, 5);
    print_node_values(head);
    clear_list(&head);
    printf("\n");

    insert_into_ordered_list(&head, 1);
    insert_into_ordered_list(&head, 2);
    insert_into_ordered_list(&head, 3);
    insert_into_ordered_list(&head, 4);
    insert_into_ordered_list(&head, 5);
    print_node_values(head);
    delete_from_list(&head, 4);
    printf("\n");
    print_node_values(head);
    printf("\n");

    printf("%s\n", search_list(head, 2) ? "Found Node." : "Node not found.");
    printf("%s\n", search_list(head, 4) ? "Found Node." : "Node not found.");

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

/* Removes all nodes in the linked list */
void clear_list(struct node **pp)
{
    struct node *temp;

    while (*pp) {
        temp = (*pp)->next;
        *pp = (*pp)->next;
        free(temp);
    }
}

/* Inserts a node into list in numerical order by value */
void *insert_into_ordered_list(struct node **pp, int value)
{
    struct node *entry = *pp;
    struct node *new_node;

    while (entry) {
        if (entry->value >= value) {
            break;
        }
        pp = &entry->next;
        entry = entry->next;
    }

    if ((new_node = malloc(sizeof(struct node))) == NULL) {
        printf("Error, malloc in insert_into_ordered_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->next = entry; 
    new_node->value = value;
    *pp = new_node;
}

/* Prints all the nodes and their values in the list */
void print_node_values(struct node *p)
{
    int count = 0;
    while (p) {
        count++;
        printf("Node %d: %d\n", count, p->value);
        p = p->next;
    }
}

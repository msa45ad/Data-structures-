#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void sort(struct node *head);
struct node *add(struct node *h, int val);
void display(struct node *head);

int main() {
    struct node *head, *ptr;
    head = (struct node *)malloc(sizeof(struct node));
    int val, num;

    printf("Enter the number of nodes required:\n");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid number of nodes.\n");
        return 0;
    }

    printf("Enter the data:\n");
    scanf("%d", &val);
    head->data = val;
    head->link = NULL;
    ptr = head;

    for (int i = 1; i < num; i++) {
        printf("Enter the data:\n");
        scanf("%d", &val);
        ptr = add(ptr, val);
    }

    printf("Original list:\n");
    display(head);

    sort(head);

    printf("Sorted list:\n");
    display(head);

    return 0;
}

struct node *add(struct node *h, int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->link = NULL;
    h->link = newNode;
    return newNode;
}

void display(struct node *head) {
    printf("Elements in the linked list:\n");
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->link;
    }
}

void sort(struct node *head) {
    struct node *p, *ptr;
    int temp;

    if (head == NULL) return;

    for (p = head; p != NULL; p = p->link) {
        for (ptr = head; ptr->link != NULL; ptr = ptr->link) {
            if (ptr->data > ptr->link->data) {
                temp = ptr->data;
                ptr->data = ptr->link->data;
                ptr->link->data = temp;
            }
        }
    }
}



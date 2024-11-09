#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *InsertFront(struct node *, int);
struct node *InsertPos(struct node *, int, int);
struct node *InsertRear(struct node *, int);
void display(struct node *);

int main() {
    struct node *head = NULL;
    int pref, val, pos;

    printf("Select 1 to InsertFront()\n");
    printf("Select 2 to InsertRear()\n");
    printf("Select 3 to InsertPos()\n");
    printf("Select 4 to Display()\n");
    printf("Select 5 to Exit\n");

    while (true) {
        printf("Enter your choice:\n");
        scanf("%d", &pref);

        if (pref == 1) {
            printf("Enter the value:\n");
            scanf("%d", &val);
            head = InsertFront(head, val);
        } else if (pref == 2) {
            printf("Enter the value:\n");
            scanf("%d", &val);
            head = InsertRear(head, val);
        } else if (pref == 3) {
            printf("Enter the value:\n");
            scanf("%d", &val);
            printf("Enter the position to insert:\n");
            scanf("%d", &pos);
            head = InsertPos(head, pos, val);
        } else if (pref == 4) {
            display(head);
        } else if (pref == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

struct node *InsertFront(struct node *head, int val) {
    struct node *h = (struct node *)malloc(sizeof(struct node));
    h->prev = NULL;
    h->data = val;
    h->next = head;

    if (head != NULL) {
        head->prev = h;
    }
    return h;
}

struct node *InsertRear(struct node *head, int val) {
    struct node *h = (struct node *)malloc(sizeof(struct node));
    h->prev = NULL;
    h->data = val;
    h->next = NULL;

    if (head == NULL) {
        return h;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = h;
    h->prev = temp;
    return head;
}

struct node *InsertPos(struct node *head, int pos, int val) {
    if (pos <= 1) {
        return InsertFront(head, val);
    }

    struct node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL && count != pos - 1) {
        printf("Position out of bounds.\n");
        return head;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

void display(struct node *head) {
    printf("Elements in the doubly linked list are:\n");
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

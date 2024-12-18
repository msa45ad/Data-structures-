#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int val) {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = val;
    head->next = NULL;
    return head;
}

void insertAtFirst(struct node **head, int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertAtPosition(struct node *head, int val, int pos) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    newNode->data = val;

    int i = 1;
    while (ptr != NULL && i < pos - 1) {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertAtEnd(struct node *head, int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    newNode->data = val;
    newNode->next = NULL;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
}

void display(struct node *head) {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Contents of the linked list are:\n");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int val, pref, pos;

    printf("Enter the first node value to create the linked list: ");
    scanf("%d", &val);
    head = createList(val);

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Insert at first position\n");
        printf("2. Insert at a specific position\n");
        printf("3. Insert at the end\n");
        printf("4. Display the linked list\n");
        printf("5. Exit\n");

        printf("Enter your preference: ");
        scanf("%d", &pref);

        if (pref == 1) {
            printf("Enter value to insert at the first position: ");
            scanf("%d", &val);
            insertAtFirst(&head, val);
        } else if (pref == 2) {
            printf("Enter position and value to insert at that position: ");
            scanf("%d %d", &pos, &val);
            insertAtPosition(head, val, pos);
        } else if (pref == 3) {
            printf("Enter value to insert at the end: ");
            scanf("%d", &val);
            insertAtEnd(head, val);
        } else if (pref == 4) {
            display(head);
        } else if (pref == 5) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

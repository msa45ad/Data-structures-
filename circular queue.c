#include <stdio.h>
#include <stdbool.h>
#define MAX 5

int insert(int *front, int *rear, int que_arr[], int val);
int del(int *front, int *rear, int que_arr[]);
void display(int *front, int *rear, int que_arr[]);

int main() {
    int front = -1;
    int rear = -1;
    int que_arr[MAX];
    int pref, v;

    printf("Select 1 to insert()\n");
    printf("Select 2 to delete()\n");
    printf("Select 3 to display()\n");
    printf("Select 4 to exit\n");

    while (true) {
        printf("Enter your preference: ");
        scanf("%d", &pref);

        switch (pref) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &v);
                if (insert(&front, &rear, que_arr, v) == -1) {
                    printf("Queue is full (Overflow)\n");
                }
                break;

            case 2:
                v = del(&front, &rear, que_arr);
                if (v != -1) {
                    printf("Value deleted is %d\n", v);
                } else {
                    printf("Queue is empty (Underflow)\n");
                }
                break;

            case 3:
                display(&front, &rear, que_arr);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid preference\n");
        }
    }
}

int insert(int *front, int *rear, int que_arr[], int val) {
    if ((*rear + 1) % MAX == *front) {
        return -1;
    }
    if (*front == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % MAX;
    que_arr[*rear] = val;
    return 0;
}

int del(int *front, int *rear, int que_arr[]) {
    if (*front == -1) {
        return -1;
    }
    int val = que_arr[*front];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % MAX;
    }
    return val;
}

void display(int *front, int *rear, int que_arr[]) {
    if (*front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    int i = *front;
    while (true) {
        printf("%d ", que_arr[i]);
        if (i == *rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

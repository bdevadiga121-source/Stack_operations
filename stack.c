
#include <stdio.h>
#define MAX 5

struct Stack {
    int items[MAX];
    int top;
};

void push(struct Stack *s) {
    int value;

    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value to push: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return;
    }

    s->items[++s->top] = value;
    printf("%d pushed into stack.\n", value);
}

void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Popped element: %d\n", s->items[s->top--]);
}

void peek(const struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", s->items[s->top]);
}

void display(const struct Stack *s) {
    int i;

    if (s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");

    for (i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

int main(void) {
    struct Stack s;
    int choice;

    s.top = -1;

    do {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                push(&s);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                peek(&s);
                break;

            case 4:
                display(&s);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

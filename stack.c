#include <stdio.h>
#define size 10

int top = -1, stack[size];

int isfull() {
  if (top == size - 1) {
    printf("Stack Overflow\n");
    return 1; 
  } else {
    return 0; 
  }
}

int isempty() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return 1;  
  } else {
    return 0;  
  }
}

void push() {
  if (!isfull()) {
    top++;
    printf("Enter the element: ");
    scanf("%d", &stack[top]);
  }
}

void pop() {
  if (!isempty()) {
    top--;
  }
}

void peak() {
  if (!isempty()) {
    printf("%d\n", stack[top]);
  }
}

void display() {
  for (int i = top; i > -1; i--) {
    printf("%d\n", stack[i]);
  }
}

int main() {
  int num;

  while (1) {
    printf("1 for push\n2 for pop\n3 for peak\n4 for display\n5 for is empty\n6 for is full\n");
    scanf("%d", &num);

    switch (num) {
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        peak();
        break;
      case 4:
        display();
        break;
      case 5:
        isempty();
        break;
      case 6:
        isfull();
        break;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}


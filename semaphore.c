#include<stdio.h>

int main() {
    int buffer[10], bufsize = 5, in = 0, out = 0, pro, cons, choice;

    do {
        printf("\n1 --- Produce\n2 --- Consume\n3 --- Exit\n");
        printf("Choice? [1/2/3]: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if ((in + 1) % bufsize == out) {
                    printf("Buffer is full.\n");
                } else {
                    printf("Enter production value: ");
                    scanf("%d", &pro);
                    buffer[in] = pro;
                    in = (in + 1) % bufsize;
                }
                break;
            case 2:
                if (in == out) {
                    printf("Buffer is empty.\n");
                } else {
                    cons = buffer[out];
                    printf("Consumed Product: %d\n", cons);
                    out = (out + 1) % bufsize;
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    } while (choice != 3);

    return 0;
}


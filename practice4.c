#include <stdio.h>

int distance(); 
char cartype();
int basefare(int distance, char type);
int discount(int distance, int basefare);
int totalfare(int basefare, int discount);

int distance() {
    int d;
    printf("Enter distance to travel: ");
    scanf("%d", &d);
    printf("Distance: %d\n", d);
    return d;
}

char cartype() {
    char t;
    printf("Enter car type 'E' for Economy, 'S' for Standard or 'L' for Luxury: ");
    scanf(" %c", &t);
    printf("Car type: %c\n", t);
    return t;
}

int basefare(int distance, char type) {
    int bf = 0;
    if (type == 'E') {
        bf = distance * 10;
    } else if (type == 'S') {
        bf = distance * 15;
    } else if (type == 'L') {
        bf = distance * 25;
    } else {
        printf("Invalid car type input.\n");
    }
    printf("Base fare: %d\n", bf);
    return bf;
}

int discount(int distance, int basefare) {
    int d = 0;
    if (distance > 200) {
        d = basefare * 0.15;
    } else if (distance >= 100 && distance <= 200) {
        d = basefare * 0.10;
    } else if (distance < 100) {
        d = 0;
        printf("NO DISCOUNT.\n");
    } else {
        printf("Invalid distance input.\n");
    }
    if (d > 0)
        printf("Discount: %d\n", d);
    return d;
}

int totalfare(int basefare, int discount) {
    return basefare - discount;
}

int main() {
    int choice;
    do {
        printf("_______WELCOME TO RENT A CAR_______\n");
        printf("1. Rent a car and calculate fare.\n");
        printf("2. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char type = cartype();
                int dist = distance();
                int bf = basefare(dist, type);
                int disc = discount(dist, bf);
                int total = totalfare(bf, disc);
                printf("Total Fare: %d\n\n", total);
                break;
            }

            case 2:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid input.\n");
        }
    } while (choice != 2);

    return 0;
}

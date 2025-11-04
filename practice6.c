#include <stdio.h>

void comparetemperatures(int cityA[], int cityB[], int n);

void comparetemperatures(int cityA[], int cityB[], int n) {
    int cool = 0;
    int warm = 0;
    int same = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (cityA[i] == cityB[i]) {
            same++;
        } if (cityA[i] < cityB[i]) {
            cool++;
        } if (cityA[i] > cityB[i]) {
            warm++;
        }
    }

    printf("The temperature was equal in both cities for %d days.\n", same);
    printf("The temperature was cooler in City A for %d days.\n", cool);
    printf("The temperature was warmer in City A for %d days.\n", warm);
}

int main() {
    int n = 7;
    int i;
    int cityA[n];
    int cityB[n];

    for (i = 0; i < n; i++) {
        printf("Enter temperature of day %d for City A: ", i + 1);
        scanf("%d", &cityA[i]);
    }

    printf("Temperatures of City A: ");
    for (i = 0; i < n; i++) {
        printf("%d ", cityA[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Enter temperature of day %d for City B: ", i + 1);
        scanf("%d", &cityB[i]);
    }

    printf("Temperatures of City B: ");
    for (i = 0; i < n; i++) {
        printf("%d ", cityB[i]);
    }
    printf("\n\nComparison of Temperatures:\n");

    comparetemperatures(cityA, cityB, n);

    return 0;
}

#include <stdio.h>

int main() {
    int n, p, i, j;
    printf("Enter number of inspectors: ");
    scanf("%d", &n);
    printf("Enter number of products: ");
    scanf("%d", &p);

    char result[n][p];

    for (i = 0; i < n; i++) {
        printf("Inspector %d:\n", i + 1);
        for (j = 0; j < p; j++) {
            while (1) {
                printf("Enter vote for Product %d (P/F): ", j + 1);
                scanf(" %c", &result[i][j]);
                if (result[i][j] == 'P' || result[i][j] == 'F')
                    break;
                else
                    printf("Invalid input. Enter again.\n");
            }
        }
    }

    printf("\nTHE VOTES GIVEN ARE:\n");
    for (i = 0; i < n; i++) {
        printf("Inspector %d: ", i + 1);
        for (j = 0; j < p; j++)
            printf("%c ", result[i][j]);
        printf("\n");
    }

    int productPass[p];
    for (j = 0; j < p; j++) {
        int pass = 0;
        for (i = 0; i < n; i++)
            if (result[i][j] == 'P') pass++;
        productPass[j] = pass;
    }

    for (j = 0; j < p; j++) {
        if (productPass[j] == n)
            printf("Product %d passed all inspections.\n", j + 1);
        else if (productPass[j] == 0)
            printf("Product %d failed all inspections.\n", j + 1);
    }

    int inspectorApprovals[n];
    for (i = 0; i < n; i++) {
        int approvals = 0;
        for (j = 0; j < p; j++)
            if (result[i][j] == 'P') approvals++;
        inspectorApprovals[i] = approvals;
        printf("Inspector %d gave %d approvals.\n", i + 1, approvals);
    }

    int max = inspectorApprovals[0], best = 0;
    for (i = 1; i < n; i++)
        if (inspectorApprovals[i] > max) {
            max = inspectorApprovals[i];
            best = i;
        }

    printf("Inspector %d has the highest approval rate (%d approvals).\n", best + 1, max);
    return 0;
}

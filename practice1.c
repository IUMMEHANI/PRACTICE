#include <stdio.h>
int main() {
    char hy[25];
    int i, temp;
    int length = 0;
    printf("Enter a string: ");
    fgets(hy, sizeof(hy), stdin);
    while (hy[length] != '\0') {
        length++;
    }
    for (i = 0; i < length / 2; i++) {
        temp = hy[i];
        hy[i] = hy[length - i - 2];  
        hy[length - i - 2] = temp;
    }
    printf("Reversed string: %s\n", hy);
    return 0;
}

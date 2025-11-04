#include <stdio.h>
int main () {
	int x;
	printf("Enter lab status number(0-255): ");
	scanf("%d" , &x);
	if (x >= 0 && x <= 255) {
		if ((x & (1 << 7)) == 0) {
			printf("NO POWER.\n");
		}
		else {
			printf("Power supply is on.\n");
		}
		if ((x & (1 << 6)) == 0 && (x & (1 << 7)) != 0) {
			printf("Server Disconnected!\n");
		}
		else {
			printf("Connected Server.\n");
		}
		if ((x & (1 << 0)) != 0 && (x & (1 << 1)) != 0 && (x & (1 << 2)) != 0 && (x & (1 << 3)) != 0 && (x & (1 << 4)) != 0 && (x & (1 << 5)) != 0) {
			printf("Equipment Running.\n");
		}
		else {
			printf("Equipments are off.\n");
		}
		if ((x & (1 << 0)) == 0 && (x & (1 << 1)) == 0 && (x & (1 << 2)) == 0 && (x & (1 << 3)) == 0 && (x & (1 << 4)) == 0 && (x & (1 << 5)) == 0 && (x & (1 << 6)) == 0) {
			printf("Lab is OFF.\n");
		}
		else {
			printf("Lab is ON.\n");
		}
	}
	else {
		printf("Invalid Input.\n");
	}
	return 0;
}

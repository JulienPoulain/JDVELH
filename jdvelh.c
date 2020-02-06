#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int entry = 0;
	int location = 0;
	
	printf("Quel chemin ?\n");
	printf("(1) Gauche (2) Droite\n");
	do {
		scanf("%1d", &entry);
	} while (entry != 1 && entry != 2);
	location = entry;
	switch (location) {
		case 1:
			printf("Vous prenez la porte de gauche.\n");
			break;
		case 2:
			printf("Vous prenez la porte de droite.\n");
			break;
	}
	
	printf("%d", entry);
}
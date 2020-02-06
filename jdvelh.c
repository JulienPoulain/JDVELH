#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_ARRAY_DESTINATIONS 5

typedef struct Chapter Chapter;
struct Chapter {
	char description[128];
	int goldGain;
	int healthGain;
	int destinations[SIZE_ARRAY_DESTINATIONS];
	int nbDestinations;
};

void deplacement(Chapter*, int, int);

int main() {
	int entry = 0;
	int location = 0;
	
	Chapter start = {
		.description = "Départ",
		.goldGain = 0,
		.healthGain = 0,
		.destinations = {1, 2},
		.nbDestinations = 2
	};
	
	Chapter chapter1 = {
		.description = "Chapitre 1",
		.goldGain = 0,
		.healthGain = 0,
		.destinations = {2, 3},
		.nbDestinations = 2
	};
	
	Chapter chapter2 = {
		.description = "Chapitre 2",
		.goldGain = 0,
		.healthGain = 0,
		.destinations = {3},
		.nbDestinations = 1
	};
	
	Chapter chapter3 = {
		.description = "Chapitre 3",
		.goldGain = 0,
		.healthGain = 0,
		.destinations = {},
		.nbDestinations = 0
	};
	
	Chapter chapters[4] = {start, chapter1, chapter2, chapter3};
	
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
	
	deplacement(chapters, 0, 0);
	deplacement(chapters, 0, 1);
}

void deplacement(Chapter* chapters, int from, int to) {
	int nbDestinations = chapters[from].nbDestinations;
	for (int i = 0; i<nbDestinations; i++) {
		if (chapters[from].destinations[i] == to) {
			printf("%s\n", chapters[to].description);
			return;
		}
	}
	printf("Choix impossible.\n");
}
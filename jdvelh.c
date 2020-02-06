#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_ARRAY_DESTINATIONS 5

typedef struct Chapter Chapter;
struct Chapter {
	char description[128];
	int gold_gain;
	int health_gain;
	int destinations[SIZE_ARRAY_DESTINATIONS];
	int nbDestinations;
};

typedef struct Ressources Ressources;
struct Ressources {
	int health;
	int health_max;
	int gold;
	int gold_min;
};

int deplacement(Ressources*, Chapter*, int*, int, int);

int main() {
	int entry = 0;
	int location = 0;
	
	Chapter start = {
		.description = "Départ",
		.gold_gain = 0,
		.health_gain = 0,
		.destinations = {1, 2},
		.nbDestinations = 2
	};
	
	Chapter chapter1 = {
		.description = "Chapitre 1",
		.gold_gain = 10,
		.health_gain = -50,
		.destinations = {2, 3},
		.nbDestinations = 2
	};
	
	Chapter chapter2 = {
		.description = "Chapitre 2",
		.gold_gain = -5,
		.health_gain = -20,
		.destinations = {3},
		.nbDestinations = 1
	};
	
	Chapter chapter3 = {
		.description = "Chapitre 3",
		.gold_gain = -5,
		.health_gain = -50,
		.destinations = {},
		.nbDestinations = 0
	};
	
	Chapter chapters[4] = {start, chapter1, chapter2, chapter3};
	
	Ressources ressources = {
		.health = 100,
		.health_max = 100,
		.gold = 10,
		.gold_min = 0
	};
	
	// (TEST) Scénario déterminé
	deplacement(&ressources, chapters, &location, location, 0);
	deplacement(&ressources, chapters, &location, location, 1);
	deplacement(&ressources, chapters, &location, location, 3);
}

// 0 : Echec du déplacement
// 1 : Réussite du déplacement
// 2 : Réussite du déplacement mais mort du personnage
int deplacement(Ressources* ressources, Chapter* chapters, int* location, int from, int to) {
	int nbDestinations = chapters[from].nbDestinations;
	for (int i = 0; i<nbDestinations; i++) {
		if (chapters[from].destinations[i] == to) {
			*location = to;
			printf("%s\n", chapters[to].description);
			// Modification de la vie
			printf("Vie : %d => ", (*ressources).health);
			(*ressources).health += chapters[to].health_gain;
			if ((*ressources).health > (*ressources).health_max)
				(*ressources).health = (*ressources).health_max;
			printf("%d\n", (*ressources).health);
			// Modification de l'or
			printf("Or : %d => ", (*ressources).gold);
			(*ressources).gold += chapters[to].gold_gain;
			if ((*ressources).gold < (*ressources).gold_min)
				(*ressources).gold = (*ressources).gold_min;
			printf("%d\n", (*ressources).gold);
			if ((*ressources).health <= 0) {
				printf("Vous etes mort !");
				return 2;
			} else {
				return 1;
			}
		}
	}
	printf("Choix impossible.\n");
	return 0;
}
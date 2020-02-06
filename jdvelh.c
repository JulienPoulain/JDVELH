#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Chapter Chapter;
struct Chapter {
	char description[128];
	int goldGain;
	int healthGain;
	char* nextChapters[2];
};

void deplacement(Chapter);

int main() {
	int entry = 0;
	int location = 0;
	
	Chapter chapter1 = {
		.description = "chapter1",
		.goldGain = 0,
		.healthGain = 0,
		.nextChapters = {"chapter2", "chapter3"}
	};
	
	Chapter chapter2 = {
		.description = "chapter2",
		.goldGain = 0,
		.healthGain = 0,
		.nextChapters = {"chapter3"}
	};
	
	Chapter chapter3 = {
		.description = "chapter3",
		.goldGain = 0,
		.healthGain = 0,
		.nextChapters = {}
	};
	
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
	
	deplacement(chapter1);
	deplacement(chapter2);
	deplacement(chapter3);
}

void deplacement(Chapter chapter) {
	printf("%s\n", chapter.description);
}
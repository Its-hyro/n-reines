#include <err.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "queens.h"
#include "rdtsc.h"

static void print_board(const int n, const int queen_row[n]) {
  for(int i = 0; i < n; i++) {
  }
  printf("\n");
}

#ifndef CMOCKA_H

int main(int argc, char *argv[]) {
   // Appelle parse_args pour récupérer la taille du plateau (n)
    int n = parse_args(argc, argv);
    if (n == -1) {
        // Si l'argument est incorrect, affiche une erreur d'utilisation
        printf("Usage: %s <n>\n", argv[0]);
        return -1;
    }
    // Tableau pour stocker les positions des reines
    int queen_row[n];
    // Variables pour stocker les cycles 
    unsigned long long start, end;
    // Mesure des cycles avant l'exécution de l'algorithme
    start = rdtsc();
    if (find_solution(n, queen_row)) {
      // Mesure des cycles après l'exécution et affichage du résultat
        end = rdtsc();
        printf("Algorithm executed in %llu cycles\n", end - start);
    } else {
      // Si aucune solution n'est trouvée, affiche quand meme le temps d'exécution 
        end = rdtsc();
        printf("No solution found. Algorithm executed in %llu cycles\n", end - start);
    }

    return 0;
}
#endif


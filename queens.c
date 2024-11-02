#include "queens.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Vérifie si deux reines sont sur la même diagonale
bool check_same_diagonal(const int c0, const int r0,
                                const int c1, const int r1) {
// Deux reines sont sur la même diagonale si la différence de colonnes est égale à la différence de lignes
  return abs(c0 - c1) == abs(r0 - r1);
}

// Vérifie si une colonne donnée est valide pour placer une reine
bool check_column_ok(const int c, const int r, const int queen_row[]) {
    // Boucle sur toutes les colonnes déjà placées (à gauche de la colonne c)
    for (int i = 0; i < c; i++) {
        // Vérifie si une reine est déjà placée sur la même ligne ou diagonale
        if (queen_row[i] == r) {
            return false;
        }
        if (abs(i - c) == abs(queen_row[i] - r)) {
            return false; 
            // Vérifie si une reine est déjà placée sur la même ligne ou diagonale
        }
    }
    return true;
}

// Trouve une ligne disponible pour placer une reine dans une colonne
int find_available(const int min, const int n, const bool available[]) {
// Parcourt les lignes à partir de "min" pour trouver une ligne disponible  
  for (int i = min; i < n; i++) {
        if (available[i]) {
            return i;
        }
    }
    return -1;
    // Retourne -1 si aucune ligne n'est disponible 
}

// Fonction récursive de résolution du problème des N-Reines 
bool _find_solution(const int n, const int c, int queen_row[], bool available[], int *solution_count) {
    if (c == n) {
        // Si toutes les reines sont placées, une solution a été trouvée
        (*solution_count)++;
        printf("Solution %d:\n", *solution_count);
        print_chessboard(n, queen_row);
        return false; 
        // Continue à chercher d'autres solutions
    }
 // Boucle pour essayer toutes les lignes disponibles
    for (int r = find_available(0, n, available); r != -1; r = find_available(r + 1, n, available)) {
        if (check_column_ok(c, r, queen_row)) {
            // Place la reine sur la ligne r de la colonne c
            queen_row[c] = r;
            available[r] = false;
            // Appel récursif pour placer les reines dans les colonnes suivantes
            _find_solution(n, c + 1, queen_row, available, solution_count);
            // Libére la ligne pour d'autres solutions
            available[r] = true;
        }
    }
    return false;
}

// Fonction principale pour trouver une solution aux N-Reines
bool find_solution(const int n, int queen_row[]) {
    // Tableau pour garder trace des lignes disponibles
    bool available[n]; 
    for (int i = 0; i < n; i++) {
        // Initialisation
        available[i] = true;
    }
     // Compteur de solutions trouvées
    int solution_count = 0;
    // Appel de la fonction
    _find_solution(n, 0, queen_row, available, &solution_count);

    return solution_count > 0;
    // Retourne vrai si au moins une solution est trouvée
}

// Fonction pour afficher l'échiquier avec les reines placées
void print_chessboard(int n, const int queen_row[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (queen_row[j] == i) {
                printf(" Q ");  
            } else {
                printf(" . "); 
            }
        }
        printf("\n");  
    }
    printf("\n");
    // Affiche les positions des reines
    for (int i = 0; i < n; i++) {
        printf("%d ", queen_row[i]);
    }
    printf("\n\n");
}

// Fonction pour analyser les arguments du programme
int parse_args(int argc, char *argv[]) {
    if (argc != 2) {
        return -1;
        // Retourne -1 si le nombre d'arguments est incorrect
    }
    char *endptr;
    long val = strtol(argv[1], &endptr, 10);  
    if (*endptr != '\0' || val <= 0 || val > INT_MAX) {
        return -1;
    }
    return (int)val; 
}

#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 *
 * Return: 1 upon success, or 0 upon failure
 */

int slide_left(int *line, size_t size) {
    size_t i, j = 0;

    // Déplacer tous les éléments non nuls vers la gauche
    for (i = 0; i < size; i++) {
        if (line[i] != 0) {
            line[j++] = line[i];
        }
    }

    // Remplir le reste avec des zéros
    for (; j < size; j++) {
        line[j] = 0;
    }

    // Fusionner les éléments identiques
    for (i = 0; i < size - 1; i++) {
        if (line[i] == line[i + 1] && line[i] != 0) {
            line[i] *= 2;
            line[i + 1] = 0;
            i++; // Pour passer à l'élément suivant
        }
    }

    // Déplacer tous les éléments non nuls vers la gauche
    j = 0;
    for (i = 0; i < size; i++) {
        if (line[i] != 0) {
            line[j++] = line[i];
        }
    }
    for (; j < size; j++) {
        line[j] = 0;
    }

    return 1;
}

int slide_right(int *line, size_t size) {
    size_t i, j = size - 1;

    // Déplacer tous les éléments non nuls vers la droite
    for (i = size - 1; i < size; i--) {  // Condition de boucle corrigée
        if (line[i] != 0) {
            line[j--] = line[i];
        }
    }

    // Remplir le reste avec des zéros
    for (; j < size; j++) {  // Condition de boucle corrigée
        line[j] = 0;
    }

    // Fusionner les éléments identiques
    for (i = size - 1; i > 0; i--) {
        if (line[i] == line[i - 1] && line[i] != 0) {
            line[i] *= 2;
            line[i - 1] = 0;
            i--; // Pour passer à l'élément suivant après fusion
        }
    }

    // Déplacer tous les éléments non nuls vers la droite
    j = size - 1;
    for (i = size - 1; i < size; i--) {  // Condition de boucle corrigée
        if (line[i] != 0) {
            line[j--] = line[i];
        }
    }
    for (; j < size; j++) {  // Condition de boucle corrigée
        line[j] = 0;
    }

    return 1;
}

int slide_line(int *line, size_t size, int direction) {
    if (direction == SLIDE_LEFT) {
        return slide_left(line, size);
    } else if (direction == SLIDE_RIGHT) {
        return slide_right(line, size);
    }
    return 0;  // Direction invalide
}

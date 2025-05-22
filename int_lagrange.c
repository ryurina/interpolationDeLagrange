#include <stdio.h>
#include <stdlib.h>

// Structure pour representer un point (x, f(x)=y)
typedef struct {
    double x;
    double y;
} Point;

// Fonction pour afficher le polynome interpolateur
void afficher_polynome(Point points[3]) {
    printf("Points d'interpolation:\n");
    for (int i = 0; i < 3; i++) {
        printf("P%d: (%.2f, %.2f)\n", i+1, points[i].x, points[i].y);
    }
    
    printf("\nPolynome de Lagrange de degre 2:\n");
    printf("P(x) = %.2f * L0(x) + %.2f * L1(x) + %.2f * L2(x)\n", 
           points[0].y, points[1].y, points[2].y);
    
    printf("\nOu:\n");
    printf("L0(x) = (x - %.2f)(x - %.2f) / ((%.2f - %.2f)(%.2f - %.2f))\n",
           points[1].x, points[2].x, points[0].x, points[1].x, 
           points[0].x, points[2].x);
    printf("L1(x) = (x - %.2f)(x - %.2f) / ((%.2f - %.2f)(%.2f - %.2f))\n",
           points[0].x, points[2].x, points[1].x, points[0].x, 
           points[1].x, points[2].x);
    printf("L2(x) = (x - %.2f)(x - %.2f) / ((%.2f - %.2f)(%.2f - %.2f))\n",
           points[0].x, points[1].x, points[2].x, points[0].x, 
           points[2].x, points[1].x);
}

// Fonction pour saisir les points
void saisir_points(Point points[3]) {
    printf("Saisie des 3 points pour l'interpolation de Lagrange:\n");
    for (int i = 0; i < 3; i++) {
        printf("Point %d - x_%d: ", i, i);
        scanf("%lf", &points[i].x);
        printf("Point %d - f(x_%d) = y_%d: ", i, i, i);
        scanf("%lf", &points[i].y);
    }
}

int main() {
    Point points[3];
    
    printf("INTERPOLATION DE LAGRANGE - DEGRE 2\n\n");
    
    saisir_points(points);
    printf("\n");

    afficher_polynome(points);
    
    return 0;
}

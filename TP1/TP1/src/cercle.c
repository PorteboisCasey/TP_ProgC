#include <stdio.h>
#include <math.h>

int main() {
    double rayon = 5.0;  // On définit un rayon de 5 unités
    const double pi = M_PI;
    
    double aire = pi * rayon * rayon;
    double perimetre = 2 * pi * rayon;
    
    printf("Pour un cercle de rayon %.2f:\n", rayon);
    printf("L'aire est: %.2f\n", aire);
    printf("Le périmètre est: %.2f\n", perimetre);
    
    return 0;
}


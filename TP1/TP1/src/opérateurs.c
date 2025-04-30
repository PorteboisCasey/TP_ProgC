#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;
    
    printf("Opérations avec a = %d et b = %d\n\n", a, b);
    
    // Opérations arithmétiques
    printf("Addition: %d + %d = %d\n", a, b, a + b);
    printf("Soustraction: %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    printf("Division: %d / %d = %d\n", a, b, a / b);
    printf("Modulo: %d %% %d = %d\n", a, b, a % b);
    
    // Opérations de comparaison (résultats booléens)
    printf("\nComparaisons (1 = vrai, 0 = faux):\n");
    printf("Est-ce que %d est égal à %d ? %d\n", a, b, a == b);
    printf("Est-ce que %d est supérieur à %d ? %d\n", a, b, a > b);
    printf("Est-ce que %d est inférieur à %d ? %d\n", a, b, a < b);
    printf("Est-ce que %d est supérieur ou égal à %d ? %d\n", a, b, a >= b);
    printf("Est-ce que %d est inférieur ou égal à %d ? %d\n", a, b, a <= b);
    printf("Est-ce que %d est différent de %d ? %d\n", a, b, a != b);
    
    return 0;
}


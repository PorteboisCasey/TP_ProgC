#include <stdio.h>

int main() {
    int i, j;
    
    printf("Tables de multiplication de 1 a 10:\n\n");
    
    printf("  | ");
    for (i = 1; i <= 10; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    
    printf("--+-");
    for (i = 1; i <= 10; i++) {
        printf("----");
    }
    printf("\n");
    
    for (i = 1; i <= 10; i++) {
        printf("%2d| ", i);
        
        for (j = 1; j <= 10; j++) {
            printf("%3d ", i * j);
        }
        printf("\n");
    }
    
    return 0;
}


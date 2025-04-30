#include <stdio.h>

int main() {
    // On utilise un nombre qui a les 4ème et 20ème bits à 1
    // En binaire: 00000000 00100000 00000000 00001000
    unsigned int d = 0x00100008;
    
    // Masques pour vérifier les bits
    // 4ème bit de gauche: 00000000 00000000 00000000 00001000
    // 20ème bit de gauche: 00000000 00100000 00000000 00000000
    unsigned int masque_bit4 = 0x00000008;
    unsigned int masque_bit20 = 0x00100000;
    
    // Vérifie si les deux bits sont à 1
    int resultat = ((d & masque_bit4) == masque_bit4) && 
                   ((d & masque_bit20) == masque_bit20);
    
    printf("%d\n", resultat);
    
    return 0;
}


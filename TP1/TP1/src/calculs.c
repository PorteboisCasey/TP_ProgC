#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 3;
    char op = '*';  // Opérateur à tester
    
    printf("Opération: %d %c %d\n", num1, op, num2);
    printf("Résultat: ");
    
    switch(op) {
        case '+':
            printf("%d\n", num1 + num2);
            break;
        case '-':
            printf("%d\n", num1 - num2);
            break;
        case '*':
            printf("%d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("%d\n", num1 / num2);
            } else {
                printf("Division par zéro impossible\n");
            }
            break;
        case '%':
            if (num2 != 0) {
                printf("%d\n", num1 % num2);
            } else {
                printf("Modulo par zéro impossible\n");
            }
            break;
        case '&':
            printf("%d\n", num1 & num2);
            break;
        case '|':
            printf("%d\n", num1 | num2);
            break;
        case '~':
            printf("~%d = %d\n", num1, ~num1);
            printf("~%d = %d\n", num2, ~num2);
            break;
        default:
            printf("Opérateur non reconnu\n");
    }
    
    return 0;
}


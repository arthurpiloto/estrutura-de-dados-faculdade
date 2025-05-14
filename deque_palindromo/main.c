#include <stdio.h>
#include "deque.h"

int main() {
    Deque *palin = criaDeque();
    insereFim(palin, 'o');
    insereFim(palin, 'v');
    insereFim(palin, 'o');
    Deque *naoPalin = criaDeque();
    insereFim(naoPalin, 'e');
    insereFim(naoPalin, 'v');
    insereFim(naoPalin, 'a');
    imprime(palin);
    if (verificaPalindromo(palin)) printf("É palindromo!\n");
    else printf("Não é palindromo!\n");
    imprime(naoPalin);
    if (verificaPalindromo(naoPalin)) printf("É palindromo!\n");
    else printf("Não é palindromo!\n");
    destroiDeque(palin);
    destroiDeque(naoPalin);
    return 0;
}
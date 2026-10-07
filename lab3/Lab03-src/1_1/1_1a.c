#include <stdlib.h>
#include <stdio.h>
// só pra teste
int V[] = {1, 3, 5, 8, 9, 6, 2};
int findMaxUniM_otimizado(int *V, int N) {
    int esq = 0;
    int dir = N - 1;
    int meio;

    // enquanto houver mais de 1 elemento
    while (esq < dir) {
        meio = (esq + dir) / 2; 
        
        // compara com o da frente pra ver se ta a subir
        if (V[meio] < V[meio + 1]) {
            // ainda sobe, maximo ta pra direita
            esq = meio + 1;
        } else {
            // ta a descer, maximo ta na esquerda ou e este
            dir = meio;
        }
    }
    
    // no fim o esq e dir ficam no mesmo sitio (pico)
    return V[esq];
}

int main() {
    // calcula o tamanho do array N
    int N = sizeof(V) / sizeof(V[0]);
    
    // chama a funcao e guarda o resultado
    int maximo = findMaxUniM_otimizado(V, N);
    
    // imprime o resultado pa ver se funcionou
    printf("o valor maximo e: %d\n", maximo);
    
    return 0;
}

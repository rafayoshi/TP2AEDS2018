#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dinamica.h"

int main() {
    int D, n, i, distLeven, j;
    size_t cont;
    scanf("%d %d", &D, &n);
    char *consulta = (char *) malloc(6000); // As palavras não tem tamanho definido
    char *palavraD = (char *) malloc(6000);
    scanf("%s", consulta);
    Dicionario *dic = criaDicionario(D); // Aloca memória para uma struct Dicionário
    for(i = 0; i < D; i++){
        scanf("%s", palavraD); // Lê as palavras do dicionário
        if(strcmp(consulta, palavraD) == 0){ // Imprime a palavra imediatamente se ela for igual a palavra de consulta
            printf("%s\n", palavraD);
        }
        else {
            distLeven = levenshtein(consulta, palavraD); // Calcula a disância de Levenshtein para cada palavra
            if(distLeven <= n){
                insereDicionario(dic, palavraD, distLeven); // Insere palavras cuja distLeven seja <= n
            }
        }
    }
    free(consulta);
    free(palavraD);
    qsort(&dic->palavras[0], dic->tamanhoDic, sizeof(Palavra), comparaLeven); // Ordena o dicionário de acordo com distLeven
    for(i = 0; i < dic->tamanhoDic; i++){
        cont = 0; // Contador para verificar quantas palavras possuem a mesma distLeven
        j = i + 1;
        while(j < dic->tamanhoDic) {
            if ((j > i) && (dic->palavras[i].distLeven == dic->palavras[j].distLeven)) { // Calculo do tamanho do vetor de distLeven's iguais
                cont++;
                j++;
            }
            else {
                break; // Sai do loop caso encontre um distLEven diferente
            }
        }
        if(cont != 0){ // Se há mais de um elemento com determinada distLeven
            cont++;
            qsort(&dic->palavras[i], cont, sizeof(Palavra), cstring_cmp); // Ordena o vetor dos elementos com a mesma distLeven
        }
        else{
            if(j >= dic->tamanhoDic){
                break;
            }
        }
        i = j - 1;
    }
    for(i = 0; i < dic->tamanhoDic; i++){
        printf("%s\n", dic->palavras[i].string); // Imprime o dicionário
        free(dic->palavras[i].string);
    }
    free(dic->palavras);
    free(dic);
    return 0;
}
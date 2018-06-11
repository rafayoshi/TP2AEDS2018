#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dinamica.h"

int main() {
    int D, n, i, distLeven, j;
    size_t cont;
    scanf("%d %d", &D, &n);
    char *consulta = (char *) malloc(6000);
    char *palavraD = (char *) malloc(6000);
    scanf("%s", consulta);
    Dicionario *dic = criaDicionario(D);
    for(i = 0; i < D; i++){
        scanf("%s", palavraD);
        if(strcmp(consulta, palavraD) == 0){
            printf("%s\n", palavraD);
        }
        else {
            distLeven = levenshtein(consulta, palavraD);
            if(distLeven <= n){
                insereDicionario(dic, palavraD, distLeven);
            }
        }
    }
    qsort(&dic->palavras[0], dic->tamanhoDic, sizeof(Palavra), comparaLeven);
    for(i = 0; i < dic->tamanhoDic; i++){
        cont = 0;
        j = i + 1;
        while(j < dic->tamanhoDic) {
            if ((j > i) && (dic->palavras[i].distLeven == dic->palavras[j].distLeven)) {
                cont++;
                j++;
            }
            else {
                break;
            }
        }
        if(cont != 0){
            cont++;
            qsort(&dic->palavras[i], cont, sizeof(Palavra), cstring_cmp);
        }
        else{
            if(j >= dic->tamanhoDic){
                break;
            }
        }
        i = j - 1;
    }
    for(i = 0; i < dic->tamanhoDic; i++){
        printf("%s\n", dic->palavras[i].string);
    }
    return 0;
}
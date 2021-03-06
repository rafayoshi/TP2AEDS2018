#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dinamica.h"

int valorMin3(int a, int b, int c){ // Calcula o mínimo de 3 elementos
    if(a < b){
        if(a < c){
            return a;
        }
        else{
            return c;
        }
    }
    else{
        if(b < c){
            return b;
        }
        else{
            return c;
        }
    }
}

int levenshtein(char *consulta, char *palavraD) { //Calcula distância de Levenshtein
    unsigned int x, y, consLen, dicLen, status = 0;
    consLen = strlen(consulta);
    dicLen = strlen(palavraD);
    int mat[dicLen+1][consLen+1];
    mat[0][0] = 0;
    for (x = 1; x <= dicLen; x++){
        mat[x][0] = mat[x-1][0] + 1;
    }
    for (y = 1; y <= consLen; y++){
        mat[0][y] = mat[0][y-1] + 1;
    }
    for (x = 1; x <= dicLen; x++){
        for (y = 1; y <= consLen; y++) {
            if(consulta[y - 1] == palavraD[x - 1]){
                status = 0;
            }
            else{
                status = 1;
            }
            mat[x][y] = valorMin3(mat[x - 1][y] + 1, mat[x][y - 1] + 1, mat[x - 1][y - 1] + status);
        }
    }
    return(mat[dicLen][consLen]);
}

Dicionario *criaDicionario(int tamanho){ //Aloca um dicionário
    Dicionario *dic;
    dic = (Dicionario *) malloc(sizeof(Dicionario));
    dic->palavras = (Palavra *) malloc(tamanho * sizeof(Palavra));
    dic->tamanhoDic = 0;
    return dic;
}

void insereDicionario(Dicionario *dic, char *palavra, int distLeven){ //Insere uma palavra no dicionário
    dic->tamanhoDic++;
    dic->palavras[dic->tamanhoDic - 1].string = (char *) malloc(6000);
    strcpy(dic->palavras[dic->tamanhoDic - 1].string, palavra);
    dic->palavras[dic->tamanhoDic - 1].distLeven = distLeven;
}

int comparaLeven(const void *p, const void *q) //Compara dois ints para usar na função qsort()
{
    int a = ((Palavra *)p)->distLeven;
    int b = ((Palavra *)q)->distLeven;
    return (a - b);
}

int cstring_cmp(const void *a, const void *b) //Compara duas strings para usar na função qsort()
{
    const char *pa = ((Palavra *)a)->string;
    const char *pb = ((Palavra *)b)->string;
    return strcmp(pa,pb);
}
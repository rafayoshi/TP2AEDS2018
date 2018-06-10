typedef struct Palavra{
    char *string;
    int distLeven;
}Palavra;
typedef struct Dicionario{
    size_t tamanhoDic;
    Palavra *palavras;
}Dicionario;


int valorMin3(int, int, int);
int levenshtein(char *, char *);
Dicionario *criaDicionario();
void insereDicionario(Dicionario *, char *, int);
int comparaLeven(const void *, const void *);
int cstring_cmp(const void *, const void *);

#ifndef TP2AEDS3_DINAMICA_H
#define TP2AEDS3_DINAMICA_H

#endif //TP2AEDS3_DINAMICA_H

#ifndef COM112_FILE_H

struct vet {
    //tamanho do vetor
    int tam;
    //vetor em si
    int *vetor;
    //numero de comparacoes
    int comp;
    //numero de movimentos
    int  mov;
    //inicio do vetor
    int ini;
    //fim do vetor
    int fim;
    //tempo de execução
    double time;
};

typedef struct vet vet;

void escreverArq();

vet *cria_vetor();

void saida();

void relatorio();

int tamanho(int *v);

void escreveRelatorio(vet *vt);

void lerVetor(vet *vt);

void auxrelatorio(vet *vt, FILE *rel);
#endif /* COM112_FILE_H */


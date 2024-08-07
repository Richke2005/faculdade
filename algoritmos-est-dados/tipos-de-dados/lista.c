#include <stdio.h>
#include <stdlib.h>

//Estrutura da lista ligada
typedef struct {
    int* pv;        // vetor com elementos
    int tam;        //qtd elementos validos da lista
    int capacidade; //capacidade da lista
} lista;

//Cria uma nova lista com tamanho igual a "num_elementos"
lista cria_lista(int num_elementos){
    lista l;
    l.capacidade = num_elementos;
    l.pv = (int*) malloc (l.capacidade * sizeof(int));
    l.tam = 0;
    return l;
}

//Exibe a lista
void exibe (lista* l){
    for (int i=0; i<l->tam; i++){
        printf ("%i ", l->pv[i]);
    }
    printf("\n");
}

//Adiciona um elemento na lista
void adiciona (lista* l, int elemento){
    int* tmp = NULL;
    if (l->tam == l->capacidade){
        l->capacidade = l->capacidade + 1;
        //quando se aloca algo com malloc acessar como se fosse vetor
        tmp = (int*) malloc (l->capacidade * sizeof(int));
        for (int i=0; i<l->tam; i++){
            //posição i do int no vetor
            tmp[i] = l->pv[i];
        }
        //desaloca a porçao de memória alocada por malloc
        free(l->pv);
        l->pv = tmp;
        tmp = NULL;
    }

    l->pv[l->tam] = elemento;
    l->tam = l->tam + 1;
}

//Remove o elemento dado como parametro
void remove_elemento (lista* l, int elemento){
    int posicao = -1;
    
    for (int i=0; i<l->tam; i++){
        if (l->pv[i] == elemento)
            posicao = i;
    }
    
    if (posicao >= 0){
        for (int i=posicao; i<l->tam-1; i++){
            l->pv[i] = l->pv[i+1];
        }
        l->tam = l->tam - 1;
    }
}


//Teste a sua lista
int main()
{
    lista l = cria_lista(4);
    
    adiciona (&l, 12);
    adiciona (&l, 5);
    adiciona (&l, 8);
    adiciona (&l, 10);
    adiciona (&l, 15);
    adiciona (&l, 22);
    exibe (&l);

    remove_elemento (&l, 5);
    exibe (&l);
    
    adiciona (&l, 34);
    exibe (&l);
    
    remove_elemento(&l, 12);
    exibe(&l);
    
}
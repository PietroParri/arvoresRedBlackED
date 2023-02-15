//PIETRO BORGES PARRI GRR20204445

#include <stdio.h>

struct arvore {
    struct arvore* raiz;
    struct arvore* direita;
    struct arvore* esquerda;
    int dado;
    int cor;
};

struct arvore* first = NULL;

void main(){
}

struct arvore* insercao(struct arvore* tree, struct arvore* aux){
   if (tree->dado > aux->dado){
        tree->esquerda = insercao(tree->esquerda, aux);
        tree->esquerda->raiz = tree;
    }else if (tree->dado < aux->dado){
        tree->direita = insercao(tree->direita, aux);
        tree->direita->raiz = tree;
    }
    if (tree == NULL)
        return aux;

return tree;
}
void organizaArvore(struct arvore* first, struct arvore* tree){
    struct arvore* raiz;
    struct arvore* anterior;
    raiz, anterior = NULL;

    while ((tree->cor != 0)&& (tree->raiz->cor == 1) && (tree != first)){

        raiz = tree->raiz;
        anterior = tree->raiz->raiz;

        if (raiz == anterior->esquerda ){
            struct arvore* lateral = anterior->direita;
            if ((lateral != NULL) && (lateral->cor == 1)){
                anterior->cor = 1;
                raiz->cor = 0;
                lateral->cor = 0;
                tree = anterior;
            }else {
                if (tree == raiz->direita) {
                    trocaOutroLado(raiz);
                    tree = raiz;
                    raiz = tree->raiz;
                }

            trocaLado(anterior);

                int x = raiz->cor;

                raiz->cor = anterior->cor;
                anterior->cor = x;
                tree = raiz;

            }
        }else{
            struct arvore* lateral = anterior->esquerda;

            if((lateral != NULL) && (lateral->cor == 1)){
                anterior->cor = 1;
                raiz->cor = 0;
                lateral->cor = 0;
                tree = anterior;
            }else {

               if(tree == raiz->esquerda){
                    trocaLado(raiz);
                    tree = raiz;
                    raiz = tree->raiz;
                }

            trocaOutroLado(anterior);

                int x = raiz->cor;
                raiz->cor = anterior->cor;
                anterior->cor = x;
                tree = raiz;

            }
        }
    }
first->cor = 0;

}

void trocaLado(struct arvore* aux){

    struct arvore* esquerda = aux->esquerda;
    aux->esquerda = esquerda->direita;

    if (aux->esquerda){
            aux->esquerda->raiz = aux;
    }

    esquerda->raiz = aux->raiz;

    if (!aux->raiz){

        first = esquerda;

    }else if (aux == aux->raiz->esquerda){

        aux->raiz->esquerda = esquerda;

    }else{

        aux->raiz->direita = esquerda;

    }

esquerda->direita = aux;
aux->raiz = esquerda;

}

void trocaOutroLado(struct arvore* aux){

    struct arvore* direita = aux->direita;
    aux->direita = direita->esquerda;

    if (aux->direita){

            aux->direita->raiz = aux;

    }

    direita->raiz = aux->raiz;

    if (!aux->raiz){

        first = direita;

    }else if (aux == aux->raiz->esquerda){

        aux->raiz->esquerda = direita;

    }else{

        aux->raiz->direita = direita;

    }

direita->esquerda = aux;
aux->raiz = direita;
}

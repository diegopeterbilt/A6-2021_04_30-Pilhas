#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementoPrimitivo
{
    char *dado;
    struct ElementoPrimitivo *seguinte;
       
}Elemento;

typedef struct ListaPilha
{
    Elemento *inicio;
    int tamanho;
}Pilha;

void Init_Pilha(Pilha *pilha)
{
    pilha->inicio = NULL;
    pilha->tamanho = 0;
}

int Push_Pilha(Pilha *pilha, char *texto)
{
    Elemento *novo_elemento;
    if((novo_elemento = (Elemento*) malloc(sizeof(Elemento))) == NULL)
        return -1;
    if ((novo_elemento->dado = (char *)malloc(10 * sizeof(char))) == NULL)
        return -1;
    strcpy(novo_elemento->dado, texto);
    novo_elemento->seguinte = pilha->inicio;
    pilha->inicio = novo_elemento;
    pilha->tamanho++;

}

int Pop_Pilha(Pilha *pilha)
{
    Elemento *remove_elemento;
    if (pilha->tamanho == 0)
        return -1;
    remove_elemento = pilha->inicio;
    pilha->inicio = pilha->inicio->seguinte;
    free(remove_elemento->seguinte);
    free(remove_elemento);
    pilha->tamanho--;
    return 0;
}

void List_Pilha(Pilha *pilha)
{
    Elemento *atual;
    int i;
    atual = pilha->inicio;

    printf("-------- TOPO DA PILHA--------\n");
    for(i = 0; i < pilha->tamanho; i++){
        printf(" %s\n", atual->dado);
        atual = atual->seguinte;
    }
    printf("-------- FUNDO DA PILHA--------\n");

}

int main()
{
    Pilha *teste1;
    char *aux;
    int i;

    if((teste1 = (Pilha *) malloc(sizeof(Pilha))) == NULL)
    return -1;
    Init_Pilha(teste1);
    for (i = 0; i < 3; i++)
    {
        printf("Digite alguma coisa com ate 10 letras: ");
        scanf("%s", aux);
        Push_Pilha(teste1, aux);
        printf("A pilha tem elementos: %i\n\n", teste1->tamanho);
        List_Pilha(teste1);
    }
    Pop_Pilha(teste1);
    printf("A pilha tem elementos: %i\n\n", teste1->tamanho);
    List_Pilha(teste1);
}
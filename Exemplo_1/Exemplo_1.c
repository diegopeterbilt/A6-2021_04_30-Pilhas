//Implementar uma pilha com dez posições de elementos inteiros;

#include <stdio.h>

int topo = 0; //variaveis globais
int pilha [10]; //variaveis globais

void main()
{
    char op;

    printf("Bem vindo ao sistema!\n\n");

    while (op != 'X')
    {
        printf("A - Adicionar um elemento na pilha\n");
        printf("R - Remover um elemento da pilha\n");
        printf("S - Verificar o tamanho atual da pilha\n");
        printf("X - Para sair");
        scanf("%c", &op);
        if(op == 'A' || op == 'a')
            Push();
        else if(op == 'R' || op == 'r')
            Pop();
        else if(op == 'S' || op == 's')
            Size();
        else
            printf("ERRO : Operação nao definida");
        
    }
    

}